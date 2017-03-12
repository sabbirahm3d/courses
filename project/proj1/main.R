library(ggplot2)

x <- 20
N <- 1000
p <- 0.4
generatedData <- rbinom(N, x, p)

# a
png(filename="hist.png")
ggplot() + aes(generatedData) + 
    geom_histogram(binwidth=1, color="black", fill="white") +
    labs(y="Count")
dev.off()

# b
# print out the mean, variance and standard deviation
paste("Mean:", signif(mean(generatedData), digits=4),
    "| Variance:", signif(var(generatedData), digits=4),
    "| Standard Deviation:", signif(sqrt(var(generatedData)), digits=4)
)

# c
# print out the summary statistics
summary(generatedData)

# d
relfreq <- ftable(generatedData)/N
relfreq <- as.data.frame(relfreq)
png(filename="relfreq.png")
ggplot(data=relfreq, aes(x=generatedData, y=Freq)) + 
    geom_bar(color="black", fill="white", stat="identity") +
    labs(y="Relative Frequency")
dev.off()

# e


# 3.58
# a

# generate binomial probabilities
bnomDF <- data.frame(
    p=c(0.01, 0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(2, size=10, prob=0.01), digits=4),
        signif(pbinom(2, size=10, prob=0.05), digits=4),
        signif(pbinom(2, size=10, prob=0.10), digits=4),
        signif(pbinom(2, size=10, prob=0.20), digits=4),
        signif(pbinom(2, size=10, prob=0.25), digits=4)
    )
)
print(bnomDF)

# b

png(filename="charcurve1.png")
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")
dev.off()

# c

bnomDF <- data.frame(
    p=c(0.01, 0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(1, size=10, prob=0.01), digits=4),
        signif(pbinom(1, size=10, prob=0.05), digits=4),
        signif(pbinom(1, size=10, prob=0.10), digits=4),
        signif(pbinom(1, size=10, prob=0.20), digits=4),
        signif(pbinom(1, size=10, prob=0.25), digits=4)
    )
)
print(bnomDF)

png(filename="charcurve2.png")
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")
dev.off()

# d

bnomDF <- data.frame(
    p=c(0.01, 0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(2, size=15, prob=0.01), digits=4),
        signif(pbinom(2, size=15, prob=0.05), digits=4),
        signif(pbinom(2, size=15, prob=0.10), digits=4),
        signif(pbinom(2, size=15, prob=0.20), digits=4),
        signif(pbinom(2, size=15, prob=0.25), digits=4)
    )
)
print(bnomDF)

png(filename="charcurve3.png")
ggplot(bnomDF, aes(x=p, y=px)) + geom_line() + geom_point(color="red") +
    labs(x="p", y="P(Acceptance)")
dev.off()
