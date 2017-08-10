# Data Preprocessing MLR

############### R ####################
### check code      : Fn F1        ###
### run code        : cmd enter    ###
### set working dir : files 'more' ###
######################################

# Importing the dataset
dataset = read.csv('50_Startups.csv')
# dataset = dataset[, 2:3]

# Splitting the dataset into the Training set and Test set
# install.packages('caTools')
library(caTools)
set.seed(123)
split = sample.split(dataset$Purchased, SplitRatio = 0.8)
training_set = subset(dataset, split == TRUE)
test_set = subset(dataset, split == FALSE)

# Encoding categorical data using factor function (c being a vector)
dataset$State = factor(dataset$State,
                         levels = c('New York', 'California', 'Florida'), 
                         labels = c(1,2,3))

# Splitting the dataset into the Training set and Test set
library(caTools)
set.seed(123)
split = sample.split(dataset$Profit, SplitRatio = 0.8)
training_set = subset(dataset, split == TRUE)
test_set = subset(dataset, split == FALSE)

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
# Here it will be take care of by fit function


# Fitting Multiple Linear Regression to Training set
regressor = lm(formula = Profit ~ ., 
               data = training_set)
# NOTE: R builds and if necessary removes one Dummy Vars
summary(regressor)

# Predicting the Test set results (10) 
y_pred = predict(regressor, newdata = test_set)
y_pred

# BACKWARD ELIMINATION == Find vars that have effect
regressor = lm(formula = Profit ~ R.D.Spend + Administration + Marketing.Spend + State, 
               data = dataset) #NOTE: the training_set
summary(regressor)

regressor = lm(formula = Profit ~ R.D.Spend + Administration + Marketing.Spend, 
               data = dataset) 
summary(regressor)

regressor = lm(formula = Profit ~ R.D.Spend + Marketing.Spend, 
               data = dataset) 
summary(regressor)

regressor = lm(formula = Profit ~ R.D.Spend, 
               data = dataset) #NOTE Marketing had moved from P=10 to P=6
summary(regressor)

















