#include <string>

#include "distribution.h"

#ifndef CONSTANT_H
#define CONSTANT_H

template <class T>
class Constant : public Distribution<T> {
private:
    T c;
    
public:
    Constant(string name, T c) : Distribution<T>(name), c(c) { this->current = this->candidate = c; }

    double logp() { return 0.; }
    T getSample() { return c; }
    
    void acceptCandidate() { this->trace.push_back(c); }

    void incrementWidth( double delta ) {};
};

#endif
