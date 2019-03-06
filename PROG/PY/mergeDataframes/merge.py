# -*- coding: utf-8 -*-
"""
Andre Baumann, the Spyder Editor
"""

# Import libraries
import pandas as pd

# Problem to be solved
problem = """Merging two unsorted dataframes, rather than dictionaries,
             using the pandas lib"""
print(problem)

data1 = pd.read_csv('data1.csv')
print(data1)
"""
   Month   CrimeRate
0    JUL         310
1    MAR         220
2    APR         240
3    DEC         400
4    MAY         290
5    AUG         305
6    FEB         200
7    JUN         300
8    JAN         250
9    SEP         306
10   NOV         301
11   OCT         230
"""
data2 = pd.read_csv('data2.csv')
print(data2)
"""
  Month   Temp
0    NOV     10
1    FEB      2
2    MAR      5
3    APR      7
4    JAN      5
5    JUN     16
6    AUG     24
7    MAY     14
8    SEP     22
9    OCT     17
10   DEC      8
11   JUL     20
"""
merged = pd.merge(data1, data2, on='Month')
print(merged)


