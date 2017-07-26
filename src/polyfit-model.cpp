#include "polyfit-model.h"

PolyFitModel::PolyFitModel( std::unique_ptr<Experiment>&& inExperiment ) : Model( std::move( inExperiment ) )
{}

void PolyFitModel::setOrder( int inOrder )
{
    // Mark for recalculation, if necessary
    recalculate |= ( order != inOrder );
    if ( not recalculate ) return;

    order = inOrder;
}

Eigen::VectorXd PolyFitModel::solve()
{
    // Recalculate, only if necessary
    if ( not recalculate ) return coefficients;

    // Resize of vectors (destructive)
    inputs.resize( count );
    observations.resize( count );

    // Acquire observations
    for ( auto i = 0; i < count; ++i ) {
        // Avoid including endpoints for aesthetic reasons
        auto input = ( i + 1 ) * ( maximum_input - minimum_input ) / ( count + 1 );
        auto observation = experiment->observe( input );

        inputs( i ) = input;
        observations( i ) = observation;
    }

    // Calculate coefficients of polynomial fit

    // Constitute components of inversion matrix
    std::vector<double> sum_x_power_j( 2 * order + 1, 0.0 );
    for ( auto j = 0; j < 2 * order + 1; ++ j ) {
        double value = 0.0;
        for ( auto i = 0; i < count; ++ i ) {
            value += pow( inputs( i ), j );
        }
        sum_x_power_j.at( j ) = value;
    }

    Eigen::MatrixXd A( order + 1, order + 1 );
    for ( auto row = 0; row < order + 1; ++row ) {
        for ( auto col = 0; col < order + 1; ++col ) {
            A( row, col ) = sum_x_power_j.at( row + col );
        }
    }

    // Constitute RHS vector
    Eigen::VectorXd B( order + 1 );
    for ( auto j = 0; j < order + 1; ++j ) {
        double value = 0.0;
        for ( auto i = 0; i < count; ++ i ) {
            value += observations( i ) * pow( inputs( i ), j );
        }
        B( j ) = value;
    }

    // Calculate coefficients using matrix inversion
    // TODO: Eigen recommends using a decomposition instead of inverting a matrix
    coefficients = A.inverse() * B;

    recalculate = false;
    return coefficients;
}

double PolyFitModel::predict( double input )
{
    // Recalculate if necessary
    if ( recalculate ) solve();

    double value = 0.0;

    for ( auto i = 0; i < coefficients.size(); ++i ) {
        value += coefficients( i ) * pow( input, i );
    }

    return value;
}

