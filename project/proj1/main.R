# main.R
# This file contains the implementation of the functions in the Project 1
# NOTE: THIS SCRIPT WAS COMPILED ON A LINUX MACHINE - SOME STATEMENTS MAY THROW
# WARNINGS OR ERRORS IN OTHER SYSTEMS

library(ggplot2)  # for generating high quality plots

# ------------------------------ Part 1 ------------------------------

# initialize parameters for binomial distribution
x <- 20
N <- 1000
p <- 0.4
generatedData <- rbinom(N, x, p)

# ------ a ------

png(filename="figures/hist.png")

# plot a histogram of the data
ggplot() + aes(generatedData) + 
    geom_histogram(binwidth=1, color="black", fill="white") +
    labs(y="Count")

dev.off()

# ------ b ------

# print out the mean, variance and standard deviation
paste("Mean:", signif(mean(generatedData), digits=4),
    "| Variance:", signif(var(generatedData), digits=4),
    "| Standard Deviation:", signif(sqrt(var(generatedData)), digits=4)
)

# ------ c ------

# print out the summary statistics
summary(generatedData)

# ------ d ------

# generate a frequency table of the data and divide by the sample size
relfreq <- ftable(generatedData)/N

# convert the table to a dataframe for convenience
relfreq <- as.data.frame(relfreq)

png(filename="figures/relfreq.png")

# plot a bar plot of the relative frequencies
ggplot(data=relfreq, aes(x=generatedData, y=Freq)) + 
    geom_bar(color="black", fill="white", stat="identity") +
    labs(y="Relative Frequency")

dev.off()

# ------ e ------

# print out the cumulative probability to compare with the binomial 
# distribution table
cumProb <- 0  # initialize binomial cumulative probability

# iterate through the entire dataframe
for (i in 1:(nrow(relfreq))) {
    cumProb=cumProb+relfreq[i, "Freq"]
    print(
        paste0(
            "b(", relfreq[i, "generatedData"], ', ', x, ', ', p, ") -> ",
            cumProb
        )
    )
}

# ------------------------------ Part 2: 3.58 ------------------------------

# initialize variables
probs <- c(0.01, 0.05, 0.10, 0.20, 0.25)
proportions <- rep(0, times=length(probs))

# ------ a ------

# generate binomial probabilities with b(2, 10, p)
for (i in 1:length(proportions)) {
    proportions[i] = signif(pbinom(2, size=10, prob=probs[i]), digits=4)
}
bnomDF <- data.frame(p=probs, px=proportions)
print(bnomDF)

# ------ b ------

png(filename="figures/charcurve1.png")

# plot the characteristic curve
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")

dev.off()

# ------ c ------

# generate binomial probabilities with b(1, 10, p)
for (i in 1:length(proportions)) {
    proportions[i] = signif(pbinom(1, size=10, prob=probs[i]), digits=4)
}
bnomDF <- data.frame(p=probs, px=proportions)
print(bnomDF)

png(filename="figures/charcurve2.png")

# plot the characteristic curve
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")

dev.off()

# ------ d ------

# generate binomial probabilities with b(2, 15, p)
for (i in 1:length(proportions)) {
    proportions[i] = signif(pbinom(2, size=15, prob=probs[i]), digits=4)
}
bnomDF <- data.frame(p=probs, px=proportions)
print(bnomDF)

png(filename="figures/charcurve3.png")

# plot the characteristic curve
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")

dev.off()
