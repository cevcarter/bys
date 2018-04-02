#include <cmath>

#ifndef NORMAL_H
#define NORMAL_H


class Normal {
private:
    double mu, sigma;

public:
    // constructors
    Normal(const double& mu, const double & sigma) { this->mu = mu; this->sigma = sigma; };
    Normal() : Normal(0., 1.) {};

    // logp method
    double logp(const double& x) { return -std::log(std::sqrt(2 * M_PI)) - std::log(sigma) - .5 * std::pow((x - mu)/sigma, 2); };

    // parameter setting methods
    void setParams(const double& mu, const double& sigma) { this->mu = mu; this->sigma = sigma; };
    void setMu(const double& mu) { this->mu = mu; };
    void setSigma(const double& sigma) { this->sigma = sigma; };
};

#endif
