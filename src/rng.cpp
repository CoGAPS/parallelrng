#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <Rcpp.h>

class Rnorm_class {
  private:
    boost::mt19937 rng;
    boost::normal_distribution<> nd;
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > norm_rnd;

    int seed_method(int seed=1) {
        if (seed < 1) {
            return std::time(0);
        } else {
            return seed;
        }
    }

  public:
    Rnorm_class(int seed=-1, double mean=0.0, double variance=1.0):
       rng(seed_method(seed)), 
       nd(mean, variance),
       norm_rnd(rng, nd) { }

    ~Rnorm_class() { }

    Rcpp::NumericVector draw(int n = 1) {
        Rcpp::NumericVector samples(n);

        for (int i = 0; i < n; ++i) {
            samples[i] = norm_rnd();
        }

        return samples;
    }
};

// [[Rcpp::export]]
Rcpp::NumericVector rnorm_cpp(int seed=-1, int n=1) {
    Rnorm_class draws(seed);

    return draws.draw(n);
}
