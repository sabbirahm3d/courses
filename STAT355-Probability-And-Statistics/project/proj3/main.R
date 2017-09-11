# main.R
# This file contains the implementation of the functions in the Project 3
# NOTE: THIS SCRIPT WAS COMPILED ON A LINUX MACHINE - SOME STATEMENTS MAY THROW
# WARNINGS OR ERRORS IN OTHER SYSTEMS

library(ggplot2)
library(gridExtra)
library(scales)
set.seed(0)  # seed the random generators

scoreTemplate <- 
    "\\begin{equation*}
    %s=\\frac{\\overline{X}-\\mu}{\\sfrac{\\sigma}{\\sqrt{n}}}
    =\\frac{%0.1f-%0.1f}{\\sfrac{%0.2f}{\\sqrt{%d}}}=%0.4f
    \\end{equation*}"


dumpComputation <- function(X, mu, sigma, n, alpha, 
    distType, twoSided, outputFile) {

    score <- (X - mu)/(sigma/sqrt(n))

    tableVal <- 0
    pScore <- 0

    if (distType == "Z") {

        tableVal <- qnorm(alpha/2)
        pScore <- 2 * (1 - (pnorm(score)))

    } else if (distType == "t") {

        if (twoSided) {
            tableVal <- qt(alpha/2, df=n-1)            
            pScore <- 2 * (1 - pt(score,df=n-1))
        } else {
            tableVal <- qt(alpha, df=n-1)
            pScore <- 1 - pt(score, df=n-1)
        }

    }

    # dump output to LaTex modules
    sink(
        paste0("latex_mods/", outputFile, "_out.tex"),
        append=FALSE, split=FALSE
    )
    cat(
        sprintf(scoreTemplate,
            distType, X, mu, sigma, n, 
            score, distType)
    )
    sink()  # return stdout to console
    print(outputFile)
    print(paste("Score:", tableVal))
    print(paste("P-value:", pScore))

}



# ------------------------------ Part 1 ------------------------------

X <- 73.2
mu <- 72.4
sigma <- 2.1
n <- 35
alpha <- 0.05

dumpComputation(X=X, mu=mu, sigma=sigma, n=n, 
    alpha=alpha, distType="Z", twoSided=TRUE, "part1")


# ------------------------------ Part 2 ------------------------------

X <- 73.2
mu <- 75
s <- 7.9
n <- 12

dumpComputation(X=X, mu=mu, sigma=s, n=n, 
    alpha=alpha, distType="t", twoSided=FALSE, "part2")


# ------------------------------ Part 3 ------------------------------

weights <- c(66, 63, 64, 62, 65)
X <- mean(weights)
s <- sd(weights)
n <- length(weights)
mu <- 60

weightsSeq <- seq(1,length(weights))

df <- data.frame(weightsSeq, weights)

dumpComputation(X=X, mu=mu, sigma=s, n=n, 
    alpha=alpha, distType="t", twoSided=TRUE, "part3")

probNormPlt <- ggplot(df, aes(sample=weights)) + stat_qq()
boxPlt <- ggplot(df, aes(x=weightsSeq, y=weights)) + geom_boxplot() + 
    theme(
        axis.title.x=element_blank(), 
        axis.text.x=element_blank(),
        axis.ticks.x=element_blank()
    )

# save plot to filename
png(filename="figures/part3.png", units="in", width=4, height=4, res=200)
grid.arrange(probNormPlt, boxPlt, ncol=2)
dev.off()


# ------------------------------ Part 4 ------------------------------

X <- 5.4
mu <- 5.2
sigma <- sqrt(0.8)
n <- 15

dumpComputation(X=X, mu=mu, sigma=sigma, n=n, 
    alpha=alpha, distType="t", twoSided=TRUE, "part4")


# ------------------------------ Part 5 ------------------------------

sigma <- 0.1  # standard deviation
alpha <- qnorm(1-0.05)  # P(Z > alpha)
xSeq <- c(0, 0.2)  # x bounds

png(
    filename="figures/part5.png", 
    units="in", width=6, height=4, res=200
)
ggplot(NULL, aes(x=x, colour=n, fill=n)) +
    stat_function(data=data.frame(x=xSeq, n=factor(5)), 
        fun=function(x) { pnorm(sqrt(5)*x/sigma - alpha) }) +
    stat_function(data=data.frame(x=xSeq, n=factor(10)), 
        fun=function(x) { pnorm(sqrt(10)*x/sigma - alpha) }) +
    stat_function(data=data.frame(x=xSeq, n=factor(15)), 
        fun=function(x) { pnorm(sqrt(15)*x/sigma - alpha) }) + 
    ylab("Power") + xlab("Difference") + labs(colour="Sample Size")
dev.off()

# ------------------------------ Part 6 ------------------------------

NUMSAMPS <- 10000

# initialize distribution variables
generateHist <- function(mu, filename) {

    # initialize empty arrays
    sampPScores <- generatedData <- rep(0, times=NUMSAMPS)

    # generate 10000 samples
    for (i in 1:NUMSAMPS) {

        generatedData <- rnorm(4, 20, 2)

        # store the sample means in vector
        xbar <- mean(generatedData)
        s <- sd(generatedData)

        tScore <- (xbar - mu)/(s/2)
        sampPScores[i] = pt(tScore, df=3)

    }

    # dump plots into PNG
    png(
        filename=paste0("figures/", filename), 
        units="in", width=4, height=4, res=200
    )

    # generate density histograms to display percentage
    h <- hist(
        sampPScores
    )
    h$density = h$counts/sum(h$counts)*100
    plot(
        h, freq=FALSE,
        main=NULL, xlab="P-value", ylab="Percent"
    )

    dev.off()

}

generateHist(mu=20, filename="part6a.png")
generateHist(mu=21, filename="part6b.png")
generateHist(mu=22, filename="part6c.png")
