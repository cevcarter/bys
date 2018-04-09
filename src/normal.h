#include <cmath>
#include <string>

#include "distribution.h"
#include "simpleinput.h"

#ifndef NORMAL_H
#define NORMAL_H

template <class T>
class Normal : public Distribution<T> {
private:
    Distribution<T>* mu;
    Distribution<T>* sigma;
    SimpleInput<T>* obs;

public:
    Normal(string name, Distribution<T>* mu, Distribution<T>* sigma, SimpleInput<T>* obs=NULL) : Distribution<T>(name), mu(mu), sigma(sigma), obs(obs) { this->current = mu->getCurrent(); };

    static double logpdist(const T& x, const T& mu, const T& sigma) { return -std::log(std::sqrt(2 * M_PI)) - std::log(sigma) - .5 * std::pow((x - mu)/sigma, 2); }; 

    double logp() { 
        if (obs == NULL) return this->logpdist(this->candidate, this->mu->getCandidate(), this->sigma->getCandidate()) + this->mu->logp() + this->sigma->logp(); 
        else {
            double sum = 0.;
            for (T x : obs->getBuffer()) {
                sum += this->logpdist(this->candidate, this->mu->getCandidate(), this->sigma->getCandidate()) + this->mu->logp() + this->sigma->logp(); 
            }
            return sum;
        }
    }

    T getSample() { // sample up the tree
        this->candidate = 0.; 
        this->mu->getSample();
        this->sigma->getSample();
        return this->candidate; 
    } 
};

#endif
