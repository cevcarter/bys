#ifndef LAPLACE_H
#define LAPLACE_H

#include <cmath>

class Laplace
{
private:
    double mu, b;

public:
    Laplace(const double& mu, const double & b) { this->mu = mu; this->b = b; };
    Laplace() {this->mu = 0; this->b = 1; };

    inline const double logp(const double& x) { return -std::log(2) - std::log(this->b) - .5 * std::abs((x - this->mu)/this->b); };

    void set_mu(const double& mu) { this->mu = mu; }
    void set_b(const double& b) { this->b = b; }
};

#endif
