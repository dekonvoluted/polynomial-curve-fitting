#include "normal-distribution-generator.h"

NormalGenerator::NormalGenerator( double inMean, double inStddev ) : Generator(), distribution( inMean, inStddev )
{}

double NormalGenerator::sample()
{
    return distribution( generator );
}

std::vector<double> NormalGenerator::samples( int numSamples )
{
    std::vector<double> samples( numSamples, 0.0 );

    for ( auto i = 0; i < numSamples; ++i ) {
        samples.at( i ) = this->sample();
    }

    return samples;
}

