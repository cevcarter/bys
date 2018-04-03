

#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

template <class varType>
class Distribution {
private:

public:
//    double logp(const varType& x) {}; // logp of input
    virtual double candidateLogp() {};
    virtual varType getCandidate() {}; // generates a new sample using MCMC sampling method
    virtual varType getCurrent() {}; // returns current sample
};

#endif
