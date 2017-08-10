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
dataset = read.csv('Data.csv')

# Taking care of missing data, if condition, if true, if false
dataset$Age = ifelse(is.na(dataset$Age),
                     ave(dataset$Age, FUN = function(x) mean(x, na.rm = TRUE)),
                     dataset$Age)
dataset$Salary = ifelse(is.na(dataset$Salary),
                     ave(dataset$Salary, FUN = function(x) mean(x, na.rm = TRUE)),
                     dataset$Salary)

# Encoding categorical data using factor function, c being a vector
dataset$Country = factor(dataset$Country,
                         levels = c('France', 'Spain', 'Germany'), 
                         labels = c(1,2,3))
dataset$Purchased = factor(dataset$Purchased, 
                         levels = c('No', 'Yes'), 
                         labels = c(0,1))

# Splitting the dataset into the Training set and Test set
#  install.packages('caTools')
library(caTools)
set.seed(123)
split = sample.split(dataset$Purchased, SplitRatio = 0.8)
training_set = subset(dataset, split == TRUE)
test_set = subset(dataset, split == FALSE)

# Feature Scaling (a factor is not numeric, hence excluding)
training_set[, 2:3] = scale(training_set[, 2:3])
test_set[, 2:3] = scale(test_set[, 2:3])

# Fitting Simple Linear Regression to Training set
regressor = lm(formula = Salary ~ YearsExperience, 
               data = training_set)
# Check info
summary(regressor)

# Predicting the Test set results, 
y_pred = predict(regressor, newdata = test_set)
y_pred

# Visualize Training set
# install.packages("ggplot2")
library(ggplot2)
ggplot() +
  # actual value 
  geom_point(aes(x=training_set$YearsExperience, y=training_set$Salary),
             colour = "red") +
  # prediction line
  geom_line(aes(training_set$YearsExperience, y=predict(regressor, newdata = training_set)),
                colour = "blue") +
  ggtitle('Salary vs Experience (Training Set)') +
  xlab('Years of Experience') +
  ylab('Salary')

# Visualize Test set
ggplot() +
  geom_point(aes(x=test_set$YearsExperience, y=test_set$Salary),
             colour = "red") +
  geom_line(aes(training_set$YearsExperienc, y=predict(regressor, newdata = training_set)),
            colour = "blue") +
  ggtitle('Salary vs Experience (Test Set)') +
  xlab('Years of Experience') +
  ylab('Salary')


