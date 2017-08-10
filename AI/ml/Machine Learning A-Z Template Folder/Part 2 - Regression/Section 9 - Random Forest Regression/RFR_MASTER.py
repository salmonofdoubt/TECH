# RANDOM FOREST REGRESSION TEMPLATE

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

# Feature Scaling (optional) necessary if there are Euclidian distances to be processed
#from sklearn.preprocessing import StandardScaler
#sc_X = StandardScaler()
#X_train = sc_X.fit_transform(X_train)
#X_test = sc_X.transform(X_test)"""

# Fitting Regression Model to the dataset
from sklearn.ensemble import RandomForestRegressor
# each step is calculated from n_estimators trees,
# NOTE the steps may not change with number of trees
regressor = RandomForestRegressor(n_estimators = 1000, #1000 trees in the forrest
                                  random_state = 0)
regressor.fit(X, y)

# Predicting a new result with Polynominal Regression
y_pred = regressor.predict(6.5)

# Visualize the Random Forrest Regression results
# With this non-lin, non-continious regression model, we need the high-res plot
# NOTE: This isn't very interesting as data is only a 1D matrix, we don't
# have many salaries for a given level
X_grid = np.arange(min(X), max(X), 0.001)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color='red')  # actual
plt.plot(X_grid, regressor.predict(X_grid), color='blue')  # predicted
plt.title('Truth or Bluff (RANDOM FOREST REGRESSION MODEL)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()