#include <algorithm>
#include <iostream>

#include "sine-wave-experiment.h"

int main( int argc, char** argv )
{
    SineWaveExperiment experiment;

    // Make multiple measurements at same input
    const auto input = 0.5;
    const auto count = 100;

    std::vector<double> inputs( count, input );
    auto observations = experiment.observe( inputs );

    // Find the mean of observations
    std::cout << std::accumulate( std::begin( observations ), std::end( observations ), 0.0 ) / observations.size() << '\n';
}

