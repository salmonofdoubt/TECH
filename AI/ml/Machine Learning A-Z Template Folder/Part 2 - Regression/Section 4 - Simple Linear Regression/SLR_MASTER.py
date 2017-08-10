# Data Preprocessing SLR

##################################
### check code     : cmd + i   ###
### run code       : cmd enter ###
### set working dir: Fn F5     ###
##################################

# Import libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Import dataset
dataset = pd.read_csv('Salary_Data.csv')
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 1].values

# Split dataset into Training and Test set
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 1/3, random_state = 0)

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
"""from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)"""

# Fit SLR to the training set
from sklearn.linear_model import LinearRegression
# regressor (the 'machine') an object of the class
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Predict the Test set results
y_pred = regressor.predict(X_test)
y_pred_train = regressor.predict(X_train)

# Visualise ***Training*** set results
plt.scatter(X_train, y_train, color='red')
plt.plot(X_train, y_pred_train, color='blue')
plt.title('Salary vs Experience (TRAINING set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Visualise ***Test*** set results
plt.scatter(X_test, y_test, color='red')
# NOTE: the lin regression line was already done using Training set
plt.plot(X_train, y_pred_train, color='green')
plt.title('Salary vs Experience (TEST set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()


