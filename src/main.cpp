#include <iostream>
#include <fstream>

#include "polyfit-model.h"
#include "sine-wave-experiment.h"

int main( int argc, char** argv )
{
    // Set up a polynomial fit model
    PolyFitModel model( std::make_unique<SineWaveExperiment>( 0.5, std::make_unique<NormalGenerator>( 0.0, 1.0 ) ) );
    model.setScope( 0.0, 1.0 );
    model.setObservationCount( 10 );
    model.setOrder( 3 );

    // Write out coefficients
    const auto coefficients = model.solve();
    for ( auto i = 0; i < coefficients.size(); ++i ) {
        std::cout << "w_" << i << " = " << coefficients( i ) << '\n';
    }

    // Save observations and predictions
    std::ofstream dataFile;
    dataFile.open( "data.dat" );
    const auto inputs = model.getInputs();
    const auto observations = model.getObservations();

    for ( auto i = 0; i < inputs.size(); ++i ) {
        dataFile << inputs( i ) << '\t' << observations( i ) << '\t' << model.predict( inputs( i ) ) << '\n';
    }

    dataFile.close();

    // Shortcut to plot
    system( "gnuplot --persist -e \"plot [0:1][-2:2] 'data.dat' using 1:2 with points pointtype 7 linecolor rgbcolor 'blue' title 'Observations', \
            'data.dat' using 1:3 with lines smooth csplines linetype 1 linecolor rgbcolor 'red' title 'Prediction', \
            sin(2*pi*x) with lines linetype 1 linecolor rgbcolor 'green' title 'Actual'\"" );
}

