#include <vector>
#include <string>

using std::string;
using std::vector;

#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

template <class T>
class Distribution {
protected:
    T current;
    T candidate;
    vector<T> trace;
    string name;
    double width;

public:
    Distribution(string name) : name(name) {};

    virtual double logp() {}; // for model logp computation
    virtual T getSample() {}; // get random sample from model

    virtual void acceptCandidate() {};

    T getCandidate() { return candidate; }
    T getCurrent() { return current; }
    
    vector<T> getTrace() { return trace; }
    string getName() { return name; }
   
     virtual void incrementWidth( double delta ) { }
};

#endif
