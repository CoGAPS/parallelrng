rnorm_par <- function(n=1, chains=1, seed=-1, cores=min(chains, detectCores())) {
    chains.list <- list()

    if (seed < 1) {
        set_seed <- rpois(1, 1000)
    } else {
        set_seed <- seed
    }
    
    cl <- makeCluster(2)
    clusterExport(cl, c("rnorm_cpp", "parallelrng_rnorm_cpp"))
    registerDoParallel(cl)

    foreach(i=seq_len(chains)) %dopar% {
        X <- rnorm_cpp(n=n, seed=set_seed * i)
        chains.list[[i]] <- X
    }

    stopCluster(cl)

    return(chains.list)
}
