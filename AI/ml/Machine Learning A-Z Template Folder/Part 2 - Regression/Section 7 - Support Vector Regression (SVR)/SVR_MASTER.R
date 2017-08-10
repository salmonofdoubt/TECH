############### R ####################
####  Data Preprocessing Template ####
############### R ####################
######## Contains all modules ########
############### R ####################
### check code      : Fn F1        ###
### run code        : cmd enter    ###
### set working dir : files 'more' ###
######################################


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

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
# training_set[, 2:3] = scale(training_set[, 2:3])
# test_set[, 2:3] = scale(test_set[, 2:3])

# Fitting SVR to the datase
install.packages('e1071')
library(e1071)
regressor = svm()


# Single Predicting new result
y_pred = predict(regressor, data.frame(Level = 6.5))
summary(y_pred)

# Visualize SVR Model
# install.packages('ggplot2')
library(ggplot2)
ggplot() +
  # actual values
  geom_point(aes(x = dataset$Level , y = dataset$Salary),
             colour = "red") +
  # prediction
  geom_line(aes(x = dataset$Level , y = predict(regressor, newdata = dataset)), 
            colour = "blue") +
  ggtitle('Truth or Bluff (SVR MODEL)') +
  xlab('Level') +
  ylab('Salary')