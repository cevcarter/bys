#ifndef NORMAL_H
#define NORMAL_H

#include <cmath>

class Normal
{
private:
    double mu, sigma;

public:
    Normal(const double& mu, const double & sigma) { this->mu = mu; this->sigma = sigma; };
    Normal() {this->mu = 0; this->sigma = 1; };

    inline const double logp(const double& x) { return -std::log(std::sqrt(2 * M_PI)) - std::log(this->sigma) - .5 * std::pow((x - this->mu)/this->sigma, 2); };

    void set_mu(const double& mu) { this->mu = mu; }
    void set_sigma(const double& sigma) { this->sigma = sigma; }
};

#endif
