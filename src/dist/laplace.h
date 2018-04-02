#ifndef LAPLACE_H
#define LAPLACE_H

#include <cmath>

class Laplace
{
private:
    double mu, b;

public:
    Laplace(const double& mu, const double & b) { this->mu = mu; this->b = b; };
    Laplace() : Laplace(0., 1.) {};

    const double logp(const double& x) { return -std::log(2) - std::log(b) - .5 * std::abs((x - mu)/b); };

    void set_mu(const double& mu) { this->mu = mu; };
    void set_b(const double& b) { this->b = b; };
    void set_params(const double& mu, const double& b) { this->mu = mu; this->b = b; };
};

#endif
