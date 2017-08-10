# Polynominal Regression Template

# Importing the dataset
dataset = read.csv('Position_Salaries.csv')
dataset = dataset[2:3]

# Splitting the dataset into the Training and Test set >>> Lets not do that here, 10 records only
#install.packages('caTools')
#library(caTools)
#set.seed(123)
#split = sample.split(dataset$Purchased, SplitRatio = 0.8)
#training_set = subset(dataset, split == TRUE)
#test_set = subset(dataset, split == FALSE)

# Feature Scaling >>> no need
# training_set[, 2:3] = scale(training_set[, 2:3])
# test_set[, 2:3] = scale(test_set[, 2:3])

# Fitting Regression to the dataset
# Create your regressor here

# Single Predicting new result
y_pred = predict(regressor, data.frame(Level = 6.5))
summary(y_pred)

# Visualize Regression Model
# install.packages('ggplot2')
library(ggplot2)
ggplot() +
  # actual values
  geom_point(aes(x = dataset$Level , y = dataset$Salary),
             colour = "red") +
  # prediction
  geom_line(aes(x = dataset$Level , y = predict(regressor, newdata = dataset)), 
            colour = "blue") +
  ggtitle('Truth or Bluff (REGRESION MODEL)') +
  xlab('Level') +
  ylab('Salary')

# ALT: Visualize Regression Model HIGH RES
# install.packages('ggplot2')
library(ggplot2)
x_grid = seq(min(dataset$Level), max(dataset$Level), 0.1)
ggplot() +
  # actual values
  geom_point(aes(x=dataset$Level , y=dataset$Salary),
             colour = "red") +
  # prediction
  geom_line(aes(x = x_grid, y = predict(regressor, newdata = data.frame(Level = x_grid))), 
            colour = "blue") +
  ggtitle('Truth or Bluff (REGRESION MODEL)') +
  xlab('Level') +
  ylab('Salary')


