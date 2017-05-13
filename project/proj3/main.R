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

probNormPlt <- ggplot(data, aes(sample=weights)) + stat_qq()
boxPlt <- ggplot(data, aes(x=weightsSeq, y=weights)) + geom_boxplot() + 
    theme(
        axis.title.x=element_blank(), 
        axis.text.x=element_blank(),
        axis.ticks.x=element_blank()
    )

# save plot to filename
png(filename="figures/part3.png", units="in", width=4, height=4, res=200)
grid.arrange(probNormPlt, boxPlt, ncol=2)
dev.off()


# ------------------------------ Part 5 ------------------------------

sigma <- 0.1        # The standard deviation.
n <- 15         # The sample size.
theta0 <- 0       # The value of theta0 in H0.
pow <- 0.80       # The minimum desired power.
alpha <- 0.05     # The significance level. Try 0.01, 0.05, 0.10
beta <- 1 - pow   # The desired maximum Type II error probability.
z.alpha <- qnorm(1-alpha)  # P( Z > z.alpha ) = alpha
z.beta <- qnorm(1-beta)    # P( Z > z.beta ) = beta





# ### This command plots the power function
# curve(pnorm(sqrt(n)*(x - theta0)/sigma - z.alpha), 
#       # from=theta0,                   # Left endpoint of the domain
#       to=0.2,   # Right endopint of the domain
#       col="blue",                    # Try different colors
#       main="Power Function",         # The Main Title
#       xlab=expression(theta),        # Label the horizontal axis
#       ylab=expression(gamma(theta)), # Label the vertical axis
#       lwd=2,                         # Line width.
#       add=NA)                      # TRUE or NA. NA erases old plots.

# n <- 5          # The sample size.
# curve(pnorm(sqrt(n)*(x - theta0)/sigma - z.alpha), 
#       # from=theta0,                   # Left endpoint of the domain
#       # to=theta0+3.7*sigma/sqrt(n),   # Right endopint of the domain
#       col="red",                    # Try different colors
#       main="Power Function",         # The Main Title
#       xlab=expression(theta),        # Label the horizontal axis
#       ylab=expression(gamma(theta)), # Label the vertical axis
#       lwd=2,                         # Line width.
#       add=TRUE)                      # TRUE or NA. NA erases old plots.

# n <- 10          # The sample size.
# curve(pnorm(sqrt(n)*(x - theta0)/sigma - z.alpha), 
#       # from=theta0,                   # Left endpoint of the domain
#       # to=theta0+3.7*sigma/sqrt(n),   # Right endopint of the domain
#       col="green",                    # Try different colors
#       main="Power Function",         # The Main Title
#       xlab=expression(theta),        # Label the horizontal axis
#       ylab=expression(gamma(theta)), # Label the vertical axis
#       lwd=2,                         # Line width.
#       add=TRUE)                      # TRUE or NA. NA erases old plots.


# abline(v=0.10,  # Plot a vertical line
#        # col="green",                              # Choose the color
#        lwd=2)                                    # Choose the line width

for (i in seq(5, 16, 5)) {
    ggplot(data.frame(x=c(0, 0.20)), aes(x=x, color=i)) + 
        stat_function(
            fun=function(x) pnorm(sqrt(n)*(x - theta0)/sigma - z.alpha)
        )
}
