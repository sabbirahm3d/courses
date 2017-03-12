library(ggplot2)

x <- 20
N <- 1000
p <- 0.4
generatedData <- rbinom(N, x, p)

# a
png(filename="hist.png")
ggplot() + aes(generatedData) + 
  geom_histogram(binwidth=1, colour="black", fill="white")
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
relfreq <- as.vector(ftable(generatedData))/N

ftable(generatedData)/N

# d
png(filename="relfreq.png")
barplot(relfreq, ylab="y")
# ggplot() + aes(x=c(1:length(relfreq))) + 
#   geom_histogram(y=relfreq, binwidth=1, colour="black", fill="white")
dev.off()

# e


# 3.58
# a

bnom_df <- data.frame(
    p=c(0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(2, size=10, prob=0.05), digits=4),
        signif(pbinom(2, size=10, prob=0.10), digits=4),
        signif(pbinom(2, size=10, prob=0.20), digits=4),
        signif(pbinom(2, size=10, prob=0.25), digits=4)
    )
)
print(bnom_df)

# b

png(filename="charcurve1.png")
ggplot(bnom_df, aes(x=p, y=px)) + geom_line() + geom_point(colour="red")
dev.off()

# c

bnom_df <- data.frame(
    p=c(0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(1, size=10, prob=0.05), digits=4),
        signif(pbinom(1, size=10, prob=0.10), digits=4),
        signif(pbinom(1, size=10, prob=0.20), digits=4),
        signif(pbinom(1, size=10, prob=0.25), digits=4)
    )
)
print(bnom_df)

png(filename="charcurve2.png")
ggplot(bnom_df, aes(x=p, y=px)) + geom_line() + geom_point(colour="red")
dev.off()

# d

bnom_df <- data.frame(
    p=c(0.05, 0.10, 0.20, 0.25), 
    px=c(
        signif(pbinom(2, size=15, prob=0.05), digits=4),
        signif(pbinom(2, size=15, prob=0.10), digits=4),
        signif(pbinom(2, size=15, prob=0.20), digits=4),
        signif(pbinom(2, size=15, prob=0.25), digits=4)
    )
)
print(bnom_df)

png(filename="charcurve3.png")
ggplot(bnom_df, aes(x=p, y=px)) + geom_line() + geom_point(colour="red")
dev.off()
