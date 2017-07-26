#include "model.h"

Model::Model( std::unique_ptr<Experiment>&& inExperiment ) : experiment( std::move( inExperiment ) )
{}

void Model::setScope( double inMinimum, double inMaximum )
{
    // Mark for recalculation, if necessary
    recalculate |= minimum_input != inMinimum;
    recalculate |= maximum_input != inMaximum;
    if ( not recalculate ) return;

    minimum_input = inMinimum;
    maximum_input = inMaximum;
}

void Model::setObservationCount( int inCount )
{
    // Mark for recalculation, if necessary
    recalculate |= count != inCount;
    if ( not recalculate ) return;

    count = inCount;
}

Eigen::VectorXd Model::getInputs()
{
    return inputs;
}

Eigen::VectorXd Model::getObservations()
{
    return observations;
}

