#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <Rcpp.h>
#include <vector>

// [[Rcpp::export]]
Rcpp::NumericVector rnorm_boost(int n=1, int seed=-1) {
    int set_seed;

    if (seed < 1) {
        set_seed = std::time(0);
    } else {
        set_seed = seed;
    }

    boost::mt19937 rng(set_seed);

    boost::normal_distribution<> nd(0.0, 1.0);

    boost::variate_generator<boost::mt19937 &, boost::normal_distribution<> > norm_rnd(rng, nd);

    Rcpp::NumericVector draws(n);

    for (int i = 0; i < n; ++i) {
        draws[i] = norm_rnd();
    }

    return draws;
}
