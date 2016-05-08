rnorm_par <- function(n=1, chains=1, seed=-1) {
    chains <- matrix(0, n, chains)

    for (i in 1:chains) {
        X <- rnorm_cpp(n=n, seed=seed * i)
        chains[, i] <- x
    }

    return(chains)
}
