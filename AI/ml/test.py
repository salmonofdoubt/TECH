# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
print("Hello World!")


# Import libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn import datasets, linear_model

# Import dataset
dataset = pd.read_csv('Crime_Data.csv')
print(dataset)
"""probably poor data, example only"""
"""Crimes,Temperature
250,10
300,9
299,9
150,20
210,24
275,18
275,19
310,22
301,20
199,4
187,3
210,6"""
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 1].values
print(X)
print(y)
regr = linear_model.LinearRegression()
print(regr)
regr.fit(X, y)
plt.scatter(X,y)
plt.plot(X,regr.predict(X),color='red',linewidth=4)
plt.xticks(())
plt.yticks(())
plt.show() 

