#set current working directory
setwd("/Users/ciska/CODE/_cpp/_cppExamples/course_content_2b/session3/")

samples <- read.csv(file="example2_sine/output.csv", header=FALSE)
x_indices <- c(0:44099)
length(x_indices)
length(samples[])

#retrieve min and max values used on y-axis
y_limits = c(-1.1, 1.1)

#set plotting point symbol and color 
par(pch=1, col="black") 
#plot graph outlines 
plot( x = x_indices, y = samples[, 1], 
      type="l", 
      main="Audio samples", 
      xlab="sample index", 
      ylab="amplitude", 
      ylim = y_limits,
      cex.main=1.1) # set size title

abline(h = 0, lty = 1, col = "gray")

