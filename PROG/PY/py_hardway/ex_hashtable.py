import random

data = []
m = 10
t = []
for i in range(10):
    data.append(random.randint(0, 100))

print(data)
n = len(data)
print(n)

def hfunc(data, m):
    return list(map(lambda index : index % m, data))

def htable(table):
    table = [None]*10
    return table

def get_index(keys, m):
    index = hfunc(keys, m)
    return(index)

def get_i(index):
    for i in index:
        return(i)

def get_k(data):
    for k in data:
        return k

print (get_index(data, m))

def linear(keys):
    table = htable(t)
    index = get_index(keys, m)
    j = 0
    i = get_i(index)
    k = get_k(keys)
    while (j == m):
        if table[i] == None:
            table[i] = k
            j = j+1
    
print(linear(data))