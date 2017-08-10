# Data Preprocessing template

# Importing the dataset
dataset = read.csv('Salary_Data.csv')
# dataset = dataset[, 2:3]

# Splitting the dataset into the Training set and Test set
# install.packages('caTools')
library(caTools)
set.seed(123)
split = sample.split(dataset$Salary, SplitRatio = 2/3)
training_set = subset(dataset, split == TRUE)
test_set = subset(dataset, split == FALSE)

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
# training_set[, 2:3] = scale(training_set[, 2:3])
# test_set[, 2:3] = scale(test_set[, 2:3])

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
  geom_point(aes(x=training_set$YearsExperience, y=training_set$Salary),
             colour = "red") +
  geom_line(aes(training_set$YearsExperienc, y=predict(regressor, newdata = training_set)),
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
            
            








