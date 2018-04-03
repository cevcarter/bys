#include <cmath>

#include "distribution.h"

#ifndef CONSTANT_H
#define CONSTANT_H

template <class varType>
class Constant : virtual public Distribution<varType> {
private:
    double c;
    
public:
    Constant(const double& c) { this->c = c; };

    static double logp(const double& x) { return 0.; };
    varType getCandidate() { return c; }; 
    varType getCurrent() { return c; };
};

#endif
