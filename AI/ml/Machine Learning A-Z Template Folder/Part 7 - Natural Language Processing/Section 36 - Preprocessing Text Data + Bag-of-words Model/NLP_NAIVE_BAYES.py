# Natural Language Processing

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Restaurant_Reviews.tsv', delimiter = '\t', quoting = 3)

# Cleaning the texts
import re
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
corpus = []
for i in range(0, 1000):
    # one string with what should not be removed, seperated by a space, 
    # and from where (colum 'Review')
    review = re.sub('[^a-zA-Z]', ' ', dataset['Review'][i])
    # lower case everything what remains
    review = review.lower()
    # split into a list of words
    review = review.split()
    # the object ps of class PorterStemmer() class, so to create sparser lists
    ps = PorterStemmer()
    # object runs stem() func
    # set() will make bigger texts run faster
    review = [ps.stem(word) for word in review if not word in set(stopwords.words('english'))]
    # join the result into one string, by space 
    review = ' '.join(review)
    corpus.append(review)

# Creating the Bag of Words model:
# After the "review" string, create cols for each word, and mark 1 of that word occurs in a string
from sklearn.feature_extraction.text import CountVectorizer as CV
# also removes any stop words, it could do above cleaning as well
# would be 1565 (all the words from the corpus), we reduce to most sparse 1500
cv = CV(max_features = 1500)
# the sparse matrix and make it a matrix)
X = cv.fit_transform(corpus).toarray()
# And what is the dependend variable, need our 1 yay, or 0 nay
y = dataset.iloc[:, 1].values

# Splitting the dataset into the Training set and Test set
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.20, random_state = 0)

# Fitting Naive Bayes to the Training set
#from sklearn.naive_bayes import GaussianNB
#classifier = GaussianNB()
#classifier.fit(X_train, y_train)

from sklearn import tree
#default is 10 trees
classifier = tree.DecisionTreeClassifier(criterion = 'entropy')
classifier.fit(X_train, y_train)





# Predicting the Test set results
y_pred = classifier.predict(X_test)

# Making the Confusion Matrix
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test, y_pred)
print(cm)
