rnorm_par <- function(n=1, chains=1, seed=-1) {
    chains.list <- list()

    if (seed < 1) {
        set_seed <- rpois(1, 1000)
    } else {
        set_seed <- seed
    }

    for (i in seq_len(chains)) {
        X <- rnorm_cpp(n=n, seed=set_seed * i)
        chains.list[[i]] <- X
    }

    return(chains.list)
}
