############# PYTHON #################
####  Data Preprocessing Template #### 
############# PYTHON #################
######## Contains all modules ########
############# PYTHON #################
### check code     : cmd + i       ###
### run code       : cmd enter     ###
### set working dir: Fn F5         ###
######################################

# Import libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Import dataset
dataset = pd.read_csv('Data.csv')
X = dataset.iloc[:, :-1].values # Best to make X a MATRIX
y = dataset.iloc[:, 3].values   # and y a VECTOR

# If necessay: Fill missing data using Imputer class
from sklearn.preprocessing import Imputer
# imputer object inherits from Imputer class
imputer = Imputer(missing_values = 'NaN', strategy = 'mean', axis = 0, )
# imputer to apply indecies with missing data
imputer = imputer.fit(X[:, 1:3])
# actually applies the calculation, X is now changed (Data.csv has not):
X[:, 1:3] = imputer.transform(X[:, 1:3])

# If necessary: Encode categorical data (masking)
#                                 X and y       X only
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder_X = LabelEncoder()
X[:, 0] = labelencoder_X.fit_transform(X[:, 0])
X[:, 0]
onehotencoder = OneHotEncoder(categorical_features = [0])
X = onehotencoder.fit_transform(X).toarray()
X
# y the dependent needs only a labelencoder
labelencoder_y = LabelEncoder()
y = labelencoder_y.fit_transform(y)

# Split dataset into Training and Test set
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# OPTIONAL: Feature Scaling if y is not just 0,1
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)

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


