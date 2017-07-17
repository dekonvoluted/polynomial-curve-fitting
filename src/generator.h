#ifndef GENERATOR_H
#define GENERATOR_H

#include <random>
#include <vector>

class Generator
{
    public:
    Generator() = default;
    virtual ~Generator() = default;

    // Generators can be sampled if distribution is known
    virtual double sample() = 0;
    virtual std::vector<double> samples( int ) = 0;

    protected:
    // Use a default random device
    std::random_device device;

    // Mersenne-Twister-based unsigned random integer generator
    std::mt19937 generator = std::mt19937( device() );
};

#endif

