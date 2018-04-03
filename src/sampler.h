
#ifndef SAMPLER_H
#define SAMPLER_H

template <class varType>
class Sampler {
public:
    virtual varType generateCandidate( const varType& current ) {};
};

#endif
