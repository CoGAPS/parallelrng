// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// rnorm_boost
Rcpp::NumericVector rnorm_boost(int n, int seed);
RcppExport SEXP parallelrng_rnorm_boost(SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    __result = Rcpp::wrap(rnorm_boost(n, seed));
    return __result;
END_RCPP
}