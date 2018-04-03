#include <iostream>

#include "normal.h"
#include "laplace.h"
#include "binomial.h"

using std::cout;
using std::endl;


int main() {
    Binomial* b = new Binomial(10, .5);
    cout << b->logp(6) << endl;

}
