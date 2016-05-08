rnorm_par <- function(n=1, chains=1, seed=1) {
    chains <- matrix(0, n, chains)

    for (i in 1:chains) {
        if (seed >= 1) {
            chains[, i] <- rnorm_cpp(n, seed * i)
        } else {
            chains[, i] <- rnorm_cpp(n)
        }
    }

    return(chains)
}
