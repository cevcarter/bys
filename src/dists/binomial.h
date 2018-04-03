#include <cmath>

#ifndef BINOMIAL_H
#define BINOMIAL_H

class Binomial {
private:
    unsigned int n;
    double p;
    
    double logbinom(const unsigned int& n, const unsigned int& x);

public:
    Binomial(const unsigned int& n, const double& p) { this->n = n; this->p = p; };
    Binomial(const unsigned int& n) : Binomial(n, .5) {};
    Binomial() : Binomial(1, .5) {};

    double logp(const unsigned int& x) { return logbinom(n, x) + x * std::log(p) + (n-x) * std::log(1-p); };

    void setParams(const unsigned int& n, const double p) { this->n = n; this->p = p; };

};


int fact(int x) {
    if (x == 0) return 1;
    else return x * fact(x - 1);
}

double Binomial::logbinom(const unsigned int& n, const unsigned int& x) {
    return std::log(fact(n)) - std::log(fact(x)) - std::log(fact(n-x));
}

#endif
