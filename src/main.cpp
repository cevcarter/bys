#include <iostream>

#include "metropolis.h"
#include "normal.h"
#include "constant.h"

int main() {
    MetropolisSampler<double>* ms = new MetropolisSampler<double>();  
    Constant<double>* mu = new Constant<double>(0.);
    Constant<double>* sigma = new Constant<double>(1.);  
    Normal<double>* n = new Normal<double>(mu, sigma, ms);    

    std::cout << n->candidateLogp() << std::endl;

    return 0;
}
