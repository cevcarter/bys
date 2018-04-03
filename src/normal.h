#include <cmath>
#include <string>

#include "distribution.h"
#include "sampler.h"

#ifndef NORMAL_H
#define NORMAL_H

template <class varType>
class Normal : virtual public Distribution<varType> {
private:
    Sampler<varType>* sampler;
    Distribution<varType>* mu;
    Distribution<varType>* sigma;
    varType current; // current sampled value
    varType candidate; // candidate sampled value

public:
    // constructors
    Normal(Distribution<varType>* mu, Distribution<varType>* sigma, Sampler<varType>* sampler) { 
        this->mu = mu; 
        this->sigma = sigma; 
        this->sampler = sampler;

        this->current = this->candidate = mu->getCurrent();
    };


    static double logp(const varType& x, const varType& mu, const varType& sigma) { return -std::log(std::sqrt(2 * M_PI)) - std::log(sigma) - .5 * std::pow((x - mu)/sigma, 2); }; 

    double candidateLogp() { return this->logp(this->candidate, this->mu->getCandidate(), this->sigma->getCandidate()) + this->mu->candidateLogp() + this->sigma->candidateLogp(); };

    varType getCandidate() { candidate = sampler->generateCandidate( this->current ); return candidate; };

    varType getCurrent() { return current; };
    void acceptCandidate() { *(this->current) = *(this->candidate); };
};

#endif
