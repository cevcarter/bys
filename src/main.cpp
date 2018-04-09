#include <iostream>

#include "normal.h"
#include "constant.h"

int main() {
    Constant<double>* mu = new Constant<double>("prior_mean", 0.);
    Constant<double>* sigma = new Constant<double>("prior_std", 1.);  
    Normal<double>* n = new Normal<double>("exp", mu, sigma);    

    std::cout << n->logp() << std::endl;

    return 0;
}
