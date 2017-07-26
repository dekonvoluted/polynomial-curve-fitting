#ifndef POLYFIT_MODEL_H
#define POLYFIT_MODEL_H

#include <Eigen/Dense>
#include <memory>

#include "sine-wave-experiment.h"
#include "model.h"
#include "normal-distribution-generator.h"

class PolyFitModel : public Model
{
    public:
    PolyFitModel( std::unique_ptr<Experiment>&& = std::make_unique<SineWaveExperiment>( 1.0, std::make_unique<NormalGenerator>( 0.0, 1.0 ) ) );
    ~PolyFitModel() = default;

    // Set order of polynomial used
    void setOrder( int );

    // Return coefficients of polynomial
    Eigen::VectorXd solve() override;

    // Predict observation using model
    double predict( double ) override;

    private:
    // Calculated coefficients vector
    Eigen::VectorXd coefficients;
};

#endif

