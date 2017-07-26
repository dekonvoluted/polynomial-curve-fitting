#ifndef MODEL_H
#define MODEL_H

#include <Eigen/Dense>
#include <memory>

#include "experiment.h"

class Model
{
    public:
    Model( std::unique_ptr<Experiment>&& );
    ~Model() = default;

    // Set minimum and maximum value of inputs
    void setScope( double, double );

    // Set number of observations made
    void setObservationCount( int );

    // Return inputs and observations
    Eigen::VectorXd getInputs();
    Eigen::VectorXd getObservations();

    //Return model parameters
    virtual Eigen::VectorXd solve() = 0;

    // Predict observation using model
    virtual double predict( double ) = 0;

    protected:
    std::unique_ptr<Experiment> experiment;

    double minimum_input = 0.0;
    double maximum_input = 1.0;

    int count = 10;
    int order = 3;

    // Store inputs and observations
    Eigen::VectorXd inputs;
    Eigen::VectorXd observations;

    // Internal flag to recalculate
    bool recalculate = true;
};

#endif

