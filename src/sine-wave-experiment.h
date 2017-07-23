#ifndef SINE_WAVE_EXPERIMENT_H
#define SINE_WAVE_EXPERIMENT_H

#include "experiment.h"

class SineWaveExperiment : public Experiment
{
    public:
    SineWaveExperiment( double = 1.0, std::unique_ptr<Generator>&& = std::make_unique<NormalGenerator>( 0.0, 1.0 ) );
    ~SineWaveExperiment() = default;

    // Specialize for custom signal
    double signal( double ) override;
};

#endif

