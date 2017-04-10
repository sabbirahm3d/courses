# main.R
# This file contains the implementation of the functions in the Project 2
# NOTE: THIS SCRIPT WAS COMPILED ON A LINUX MACHINE - SOME STATEMENTS MAY THROW
# WARNINGS OR ERRORS IN OTHER SYSTEMS

library(ggplot2)  # for generating high quality plots
set.seed(124)  # seed the random generators

# LaTex template for the output
outputTemplate <- "\\subsection{Output}

    The first sample mean and standard deviation were computed:

    \\[ E(\\overline{X}) = %.3f, \\ \\sigma_{\\overline{X}} = %.3f \\]

    All the samples were then used to find the sample mean and standard
    deviation. The theoretical values were also computed based on the
    relationships:

    \\[ \\mu = %s \\]
    \\[ E(\\overline{X}) = %s \\]
    \\[ \\sigma = %s \\]
    \\[ \\sigma_{\\overline{X}} = %s \\]


    \\begin{table}[h]
        \\centering
        \\begin{tabular*}{200pt}{@{\\extracolsep{\\fill}} c c c}

        & \\textbf{Actual} & \\textbf{Theoretical} \\\\
        \\hline
        $\\mu$ & %.3f  & %.3f \\\\
        E($\\overline{X}$) & %.3f & %.3f \\\\
        $\\sigma$ & %.3f & %.3f \\\\
        $\\sigma$\\textsubscript{$\\overline{X}$} & %.3f & %.3f \\\\

        \\end{tabular*}
    \\end{table}
"

# global variables
NUMSAMPS <- 1000
firstMean <- 0
firstStd <- 0

# ------------------------------ Part 1 ------------------------------

# initialize parameters for normal distribution
N <- 40  # size
mu <- 3  # mean
sigma <- 2  # standard deviation

sampMeans <- rep(0, times=NUMSAMPS)  # initialize empty array
firstMean <- 0
firstStd <- 0

# generate 1000 samples
for (i in 1:NUMSAMPS){
    generatedData <- rnorm(N, mu, sigma)
    # store the sample means in vector
    sampMeans[i] = mean(generatedData)

    if (i == 1) {
        firstMean = mean(generatedData)
        firstStd = sigma/sqrt(N)
    }

}

# save output
sink("part1.tex", append=FALSE, split=FALSE)
cat(
    sprintf(
        outputTemplate,
        firstMean, firstStd,
        "\\mu", "\\mu", "\\sigma", "\\frac{\\sigma}{\\sqrt{n}}",
        mu, mu,
        mean(sampMeans), mu,
        sigma, sigma,
        sd(sampMeans), sigma/sqrt(N)
    )
)
sink()

png(filename="figures/hist1.png")
# plot a histogram of the data
ggplot() + aes(sampMeans) + 
    geom_histogram(binwidth=0.1, color="black", fill="white") +
    labs(y="Count", x="Sample Means")

dev.off()


# ------------------------------ Part 2 ------------------------------

# initialize parameters for binomial distribution
N <- 15
n <- 10
p <- 0.15

sampMeans <- rep(0, times=NUMSAMPS)  # initialize empty array
for (i in 1:NUMSAMPS){
    generatedData <- rbinom(N, n, p)
    sampMeans[i] = mean(generatedData)

    if (i == 1) {
        firstMean = mean(generatedData)
        firstStd = sd(generatedData)
    }

}

# save output
sink("part2.tex", append=FALSE, split=FALSE)
cat(
    sprintf(
        outputTemplate,
        firstMean, firstStd,
        "np", "np", "np(1-p)", "\\frac{np(1-p)}{\\sqrt{n}}",
        n*p, n*p,
        mean(sampMeans), n*p,
        n*p*(1-p), n*p*(1-p),
        sd(sampMeans), n*p*(1-p)/sqrt(N)
    )
)
sink()

png(filename="figures/hist2.png")

# plot a histogram of the data
ggplot() + aes(sampMeans) + 
    geom_histogram(binwidth=0.2, color="black", fill="white") +
    labs(y="Count", x="Sample Means")

dev.off()


# ------------------------------ Part 3 ------------------------------

# initialize parameters for binomial distribution
N <- 120
n <- 10
p <- 0.15

sampMeans <- rep(0, times=NUMSAMPS)  # initialize empty array
for (i in 1:NUMSAMPS){
    generatedData <- rbinom(N, n, p)
    sampMeans[i] = mean(generatedData)

    if (i == 1) {
        firstMean = mean(generatedData)
        firstStd = n*p*(1-p)/N
    }

}

# save output
sink("part3.tex", append=FALSE, split=FALSE)
cat(
    sprintf(
        outputTemplate,
        firstMean, firstStd,
        "np", "np", "np(1-p)", "\\frac{np(1-p)}{\\sqrt{n}}",
        n*p, n*p,
        mean(sampMeans), n*p,
        n*p*(1-p), n*p*(1-p),
        sd(sampMeans), n*p*(1-p)/sqrt(N)
    )
)
sink()

png(filename="figures/hist3.png")

# plot a histogram of the data
ggplot() + aes(sampMeans) + 
    geom_histogram(binwidth=0.1, color="black", fill="white") +
    labs(y="Count", x="Sample Means")

dev.off()
