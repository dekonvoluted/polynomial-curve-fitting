#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <memory>
#include <vector>

#include "generator.h"
#include "normal-distribution-generator.h"

class Experiment
{
    public:
    // Initialize with precision of observations
    Experiment( double = 1.0, std::unique_ptr<Generator>&& = std::make_unique<NormalGenerator>( 0.0, 1.0 ) );
    virtual ~Experiment() = default;

    // Make observations on a signal with some precision
    virtual double observe( double );
    virtual std::vector<double> observe( std::vector<double> );

    protected:
    // Model the underlying signal
    virtual double signal( double ) = 0;

    // Noise in the observation
    virtual double noise();

    private:
    // Measure of noise in the observation
    double precision;

    // Noise in the measurement is modeled as a unit normal distribution
    std::unique_ptr<Generator> generator;
};

#endif

