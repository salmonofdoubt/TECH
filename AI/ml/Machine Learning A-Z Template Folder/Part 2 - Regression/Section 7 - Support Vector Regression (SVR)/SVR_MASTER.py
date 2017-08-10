# SUPPORT VECTOR REGRESSION TEMPLATE

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
y = dataset.iloc[:, 2].values # A VECTOR

# Splitting the dataset into the Training set and Test set
# from sklearn.cross_validation import train_test_split
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
# Necessary here as SVR class doesn't do it 
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
sc_y = StandardScaler()
X = sc_X.fit_transform(X)
y = sc_y.fit_transform(y)

# Fitting SVR to the dataset 
from sklearn.svm import SVR
regressor = SVR(kernel = 'rbf')
regressor.fit(X, y)

# Predicting a new result with Polynominal Regression
y_pred = sc_y.inverse_transform(regressor.predict(sc_X.transform(np.array([6.5]))))

# Visialize the SVR results (CEO is considered outlier :( )
plt.scatter(X, y, color='red')  # actual
plt.plot(X, regressor.predict(X), color='blue')  # predicted
plt.title('Truth or Bluff (SVR MODEL)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()