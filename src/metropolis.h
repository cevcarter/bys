#include "sampler.h"

#ifndef METROPOLIS_H
#define METROPOLIS_H

template <class varType>
class MetropolisSampler : virtual public Sampler<varType> {

public:
    MetropolisSampler<varType>() { };

    varType generateCandidate( const varType& current ) { return 0; };    
};

#endif
