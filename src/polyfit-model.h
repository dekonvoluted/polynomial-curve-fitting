#ifndef POLYFIT_MODEL_H
#define POLYFIT_MODEL_H

#include <Eigen/Dense>
#include <memory>
#include <vector>

#include "sine-wave-experiment.h"
#include "normal-distribution-generator.h"

class PolyFitModel
{
    public:
    PolyFitModel( std::unique_ptr<Experiment>&& = std::make_unique<SineWaveExperiment>( 1.0, std::make_unique<NormalGenerator>( 0.0, 1.0 ) ) );
    ~PolyFitModel() = default;

    // Set minimum and maximum value of inputs
    void setScope( double, double );

    // Set number of observations made
    void setObservationCount( int );

    // Set order of polynomial used
    void setOrder( int );

    // Return inputs and observations
    Eigen::VectorXd getInputs();
    Eigen::VectorXd getObservations();

    // Return coefficients of polynomial
    Eigen::VectorXd solve();

    // Predict observation using model
    double predict( double );

    private:
    std::unique_ptr<Experiment> experiment;

    double minimum_input = 0.0;
    double maximum_input = 1.0;

    int count = 10;
    int order = 3;

    // Store input and observation vectors
    Eigen::VectorXd inputs;
    Eigen::VectorXd observations;

    // Calculated coefficients vector
    Eigen::VectorXd coefficients;

    // Internal flag to signal recalculation
    bool recalculate = true;
};

#endif

