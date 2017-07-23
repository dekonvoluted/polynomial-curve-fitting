#include <cmath>

#include "sine-wave-experiment.h"

SineWaveExperiment::SineWaveExperiment( double inPrecision, std::unique_ptr<Generator>&& inGenerator ) : Experiment( inPrecision, std::move( inGenerator ) )
{}

// Return y = sin( 2πx )
double SineWaveExperiment::signal( double input )
{
    return sin( 2 * M_PI * input );
}

