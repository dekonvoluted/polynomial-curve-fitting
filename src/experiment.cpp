#include "experiment.h"

Experiment::Experiment( double inPrecision, std::unique_ptr<Generator>&& inGenerator ) : precision( inPrecision ), generator( std::move( inGenerator ) )
{}

double Experiment::observe( double input )
{
    // If the generator returns a sample from a normal distribution,
    // y = m + s.N(μ = 0.0, σ = 1.0)
    // in turn generates a normal distribution N(μ = m, σ = s)
    // TODO: Is this only valid for normal distribution?
    auto mean = signal( input );
    auto error = noise();

    return mean + error;
}

std::vector<double> Experiment::observe( std::vector<double> inputs )
{
    std::vector<double> observations;
    observations.reserve( inputs.size() );
    for ( const auto& input : inputs ) {
        observations.push_back( this->observe( input ) );
    }
    return observations;
}

double Experiment::noise()
{
    return precision * generator->sample();
}

