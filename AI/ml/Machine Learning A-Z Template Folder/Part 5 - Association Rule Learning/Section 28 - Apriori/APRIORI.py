# Apriori

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Data Preprocessing
dataset = pd.read_csv('Market_Basket_Optimisation.csv', header = None)
#sparse matrix
transactions = []
for i in range(0, 7501):
    transactions.append([str(dataset.values[i,j]) for j in range(0, 20)])

# Training Apriori on the dataset
from apyori import apriori
rules = apriori(transactions, min_support = 0.003, min_confidence = 0.2, min_lift = 3, min_length = 2)

# Visualising the results
results = list(rules)
#bug https://www.udemy.com/machinelearning/learn/v4/questions/1750176
# show top 10:
for i in range(0,11):
    lhs = str(results[i][2]).split('=')[1]
    rhs = str(results[i][2]).split('=')[2]
    lhs = lhs[0:lhs.rfind(',')]
    lhs = lhs.replace('frozenset','')
    rhs = rhs[0:rhs.rfind(',')]
    rhs = rhs.replace('frozenset','')
    print("%r -> %r" %(lhs,rhs))

