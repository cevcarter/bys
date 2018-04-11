#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "normal.h"
#include "constant.h"

int main() {
    SimpleInput<double>* in = new SimpleInput<double>();
    in->push(1.);
    in->push(1.1);
    in->push(2.);

    Normal<double>* mu = new Normal<double>("mu", new Constant<double>("mu_mean", 0.), new Constant<double>("mu_std", 2.));
    Constant<double>* sigma = new Constant<double>("sigma", 1.);  
    Normal<double>* obs = new Normal<double>("exp", mu, sigma, in);    

    std::default_random_engine gen;
    std::uniform_real_distribution<double> u(0., 1.);

    int sampler_counter = 0;
    int samples_collected = 0;
    int tune_size = 500;
    int sample_size = 2500;
    double curr_logp;
    double model_logp = obs->logp();
    double u_logp;
    double accept_ratio;

    int recent_samples_collected = 0;
    int check_ratio = 1000;

    while (samples_collected < sample_size) {
        obs->getSample();
        curr_logp = obs->logp();
        if (curr_logp > model_logp & sampler_counter > tune_size) {
            model_logp = curr_logp;
            obs->acceptCandidate();
            ++samples_collected;
            ++recent_samples_collected;
        } else {
            u_logp = std::log(u(gen));
            if (curr_logp > u_logp & sampler_counter > tune_size) {
                model_logp = curr_logp;
                obs->acceptCandidate();
                ++samples_collected;
                ++recent_samples_collected;
            }
        }
        
        if (sampler_counter % check_ratio == 0) {
            accept_ratio = (double)recent_samples_collected / check_ratio;
            recent_samples_collected = 0;
            std::cout << accept_ratio << std::endl;
        }

        ++sampler_counter;
    }

    std::cout << std::endl << std::endl;

    vector<double> trace = obs->getTrace();
    for (double t : trace) {
        std:: cout << t << " ";
    }

    std::cout << std::endl << std::endl;
    return 0;
}
