#ifndef NORMAL_DISTRIBUTION_GENERATOR_H
#define NORMAL_DISTRIBUTION_GENERATOR_H

#include "generator.h"

class NormalGenerator : public Generator
{
    public:
    // Defaults to a unit normal distribution
    NormalGenerator( double = 0.0, double = 1.0 );
    virtual ~NormalGenerator() = default;

    // Generate samples from normal distribution
    double sample() override;
    std::vector<double> samples( int ) override;

    private:
    std::normal_distribution<double> distribution;
};

#endif

