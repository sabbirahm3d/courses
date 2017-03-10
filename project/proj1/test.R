generated_data <- rbinom(1000,20,0.4)

# a
png(filename="hist.png")
hist(generated_data)
dev.off()

# b
paste("Mean:", signif(mean(generated_data), digits=4),
    "| Variance:", signif(var(generated_data), digits=4),
    "| Standard Deviation:", signif(sqrt(var(generated_data)), digits=4)
)
