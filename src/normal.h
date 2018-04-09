#include <cmath>
#include <string>
#include <random>

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

    std::default_random_engine generator = std::default_random_engine();
    std::normal_distribution<T> stepper = std::normal_distribution<T>(0., 1.);
    double width = 1.;

public:
    Normal(string name, Distribution<T>* mu, Distribution<T>* sigma, SimpleInput<T>* obs=NULL) : Distribution<T>(name), mu(mu), sigma(sigma), obs(obs) { this->current = mu->getCurrent(); };

    static double logpdist(const T& x, const T& mu, const T& sigma) { return -std::log(std::sqrt(2 * M_PI)) - std::log(sigma) - .5 * std::pow((x - mu)/sigma, 2); }; 

    double logp() { 
        if (obs == NULL) return this->logpdist(this->candidate, this->mu->getCandidate(), this->sigma->getCandidate()) + this->mu->logp() + this->sigma->logp(); 
        else {
            double sum = 0.;
            for (T x : obs->getBuffer()) {
                sum += this->logpdist(x, this->mu->getCandidate(), this->sigma->getCandidate()) + this->mu->logp() + this->sigma->logp(); 
            }
            return sum;
        }
    }

    T getSample();

    void acceptCandidate() { this->trace.push_back(this->candidate); this->current = this->candidate; this->mu->acceptCandidate(); this->sigma->acceptCandidate();}
};

template <class T>
T Normal<T>::getSample() {
    T sample = stepper(generator);

    this->candidate = sample / this->width + this->current;
    this->mu->getSample();
    this->sigma->getSample();
    return this->candidate;
}

#endif
