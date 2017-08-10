# GENERAL REGRESSION TEMPLATE

##################################
### check code     : cmd + i   ###
### run code       : cmd enter ###
### set working dir: Fn F5     ###
##################################

# Import libraries

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:, 1:2].values # A MATRIX
y = dataset.iloc[:, 2].values  # A VECTOR

# Splitting the dataset into the Training set and Test set
#from sklearn.cross_validation import train_test_split
#X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling
#from sklearn.preprocessing import StandardScaler
#sc_X = StandardScaler()
#X_train = sc_X.fit_transform(X_train)
#X_test = sc_X.transform(X_test)"""

# Fitting Regression Model to the dataset
# Create your regressor here

# Predicting a new result with Polynominal Regression
y_pred = regressor.predict(6.5)

# Visialize the Regression results
plt.scatter(X, y, color='red')  # actual
plt.plot(X, regressor.predict(X), color='blue')  # predicted
plt.title('Truth or Bluff (REGRESSION MODEL)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()