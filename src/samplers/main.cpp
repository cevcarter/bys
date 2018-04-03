#include <vector>
#include "metropolis.h"

using std::vector;
double logp(vector<double> x) {
    return 0.;
}

int main() {

    MetropolisSampler* ms = new MetropolisSampler(logp);
    return 0;
}
