# main.R
# This file contains the implementation of the functions in the Project 2
# NOTE: THIS SCRIPT WAS COMPILED ON A LINUX MACHINE - SOME STATEMENTS MAY THROW
# WARNINGS OR ERRORS IN OTHER SYSTEMS

library(ggplot2)  # for generating high quality plots

# ------------------------------ Part 1 ------------------------------

# initialize parameters for normal distribution
N <- 40
mu <- 3
sigma <- 2
# set.seed(124)
samp_means <- c()
for (i in 1:1000){
    generatedData <- rnorm(N, mu, sigma)
    samp_means[i] = mean(generatedData)
}

print(mean(samp_means))
print(sd(samp_means))
print(sigma/sqrt(N))
# ------ a ------

png(filename="figures/hist.png")

# plot a histogram of the data
ggplot() + aes(samp_means) + 
    geom_histogram(binwidth=1, color="black", fill="white") +
    labs(y="Count")

dev.off()


# ------------------------------ Part 2 ------------------------------

# initialize parameters for binomial distribution
x <- 15
N <- 10
p <- 0.15
# set.seed(124)
samp_means <- c()
for (i in 1:1000){
    generatedData <- rbinom(N, x, p)
    samp_means[i] = mean(generatedData)
}

print(mean(samp_means))
print(x*p)
print(sd(samp_means))
print(sqrt(x*p*(1-p)))
print(sigma/sqrt(N))
# ------ a ------

png(filename="figures/hist1.png")

# plot a histogram of the data
ggplot() + aes(samp_means) + 
    geom_histogram(binwidth=1, color="black", fill="white") +
    labs(y="Count")

dev.off()


# ------------------------------ Part 3 ------------------------------

# initialize parameters for binomial distribution
x <- 120
N <- 10
p <- 0.15
# set.seed(124)
samp_means <- c()
for (i in 1:1000){
    generatedData <- rbinom(N, x, p)
    samp_means[i] = mean(generatedData)
}

print(mean(samp_means))
print(x*p)
print(sd(samp_means))
print(sqrt(x*p*(1-p)))
print(sigma/sqrt(N))
# ------ a ------

png(filename="figures/hist2.png")

# plot a histogram of the data
ggplot() + aes(samp_means) + 
    geom_histogram(binwidth=1, color="black", fill="white") +
    labs(y="Count")

dev.off()
