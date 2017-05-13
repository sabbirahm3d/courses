# main.R
# This file contains the implementation of the functions in the Project 3
# NOTE: THIS SCRIPT WAS COMPILED ON A LINUX MACHINE - SOME STATEMENTS MAY THROW
# WARNINGS OR ERRORS IN OTHER SYSTEMS

library(ggplot2)
library(gridExtra)
set.seed(0)  # seed the random generators

scoreTemplate <- 
    "\\begin{equation*}
    %s=\\frac{\\overline{X}-\\mu}{\\sfrac{\\sigma}{\\sqrt{n}}}
    =\\frac{%0.1f-%0.1f}{\\sfrac{%0.1f}{\\sqrt{%d}}}=%0.4f
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
            pScore <- pt(score, df=n-1)
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

data <- data.frame(weightsSeq, weights)

dumpComputation(X=X, mu=mu, sigma=s, n=n, 
    alpha=alpha, distType="t", twoSided=TRUE, "part3")

probNormPlt <- ggplot(data, aes(sample=weights))+stat_qq()
boxPlt <- ggplot(data, aes(x=weightsSeq, y=weights)) + geom_boxplot() + theme(axis.title.x=element_blank(),
    axis.text.x=element_blank(),
    axis.ticks.x=element_blank())
# save plot to filename
png(filename="figures/part3.png")
grid.arrange(probNormPlt, boxPlt, ncol=2)
dev.off()
