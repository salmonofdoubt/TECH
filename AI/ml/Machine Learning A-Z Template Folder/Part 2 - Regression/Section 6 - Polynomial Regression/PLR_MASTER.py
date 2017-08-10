# Data Preprocessing PR

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
# Only 10 values here. No split here, removing something from small training
# set will reduce accuracy
# from sklearn.cross_validation import train_test_split
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling (optional) necessary if there are Euclidian distance to be processed
# No need for FS here
"""from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)"""

# Lets build a linear regression model for comarision first
from sklearn.linear_model import LinearRegression
lin_reg = LinearRegression()
lin_reg.fit(X, y)  # execute fit

# Lets rather build the actual Polynomial Regression model
# 1.
from sklearn.preprocessing import PolynomialFeatures
# 2. compose regression object based on class PolynomialFeatures (^2 or x^3...)
poly_reg = PolynomialFeatures(degree = 4)
# 3. Transform X to a new X matrix based on that regression object
#    Introduces X*B0 (X=1) and the higher, non-lin order x^2
X_poly = poly_reg.fit_transform(X)
# 4. Execute the fit
poly_reg.fit(X_poly, y)
# 5. Fit a linear regression onto the polynomial terms
lin_reg2 = LinearRegression() 
lin_reg2.fit(X_poly, y)

# Visialize the referential LinearRegression
plt.scatter(X, y, color='red')  # actual
plt.plot(X, lin_reg.predict(X), color='blue')  # predicted
plt.title('Truth or Bluff (LINEAR REGRESSION)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

# Visialize the Polynominal, referential Linear Regression
X_grid = np.arange(min(X), max(X), 0.1)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color='red')  # actual
plt.plot(X_grid, lin_reg2.predict(poly_reg.fit_transform(X_grid)), color='blue')  # predicted
plt.title('Truth or Bluff (POLYNOMINAL LIN REGRESSION)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

# Predicting a new result with Linear Regression
lin_reg.predict(6.5)  # yields 330k

# Predicting a new result with Polynominal Regression using degree = 4 
lin_reg2.predict(poly_reg.fit_transform(6.5))  # yields 159k TRUTH
