#include <iostream>
#include <vector>

#include "normal.h"
#include "constant.h"

int main() {
    SimpleInput<double>* in = new SimpleInput<double>();
    in->push(1.);
    in->push(1.1);
    in->push(2.);

    Constant<double>* mu = new Constant<double>("prior_mean", 0.);
    Constant<double>* sigma = new Constant<double>("prior_std", 1.);  
    Normal<double>* n = new Normal<double>("exp", mu, sigma);    

    for (int i = 0; i < 100; ++i) {
        n->getSample();
        n->acceptCandidate();
        std::cout << n->logp() << " ";
    }

    std::cout << std::endl << std::endl;

    vector<double> trace = n->getTrace();
    for (double t : trace) {
        std:: cout << t << " ";
    }

    std::cout << std::endl << std::endl;
    return 0;
}
