#include <iostream>

#include "normal.h"
#include "laplace.h"

using std::cout;
using std::endl;


int main() {
    Normal* n = new Normal(0., 1.);
    cout << n->logp(-1.2) << endl;

    Laplace* l = new Laplace(0., 1.);
    cout << l->logp(-1.2) << endl;
}
