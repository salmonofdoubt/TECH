import os                # for file handling functions
import numpy as np            # for array/matrix processing
import matplotlib.pyplot as plt        # for general plotting

0.157957
-0.108352
-0.416099
-0.147049
0.194426
-0.0338146
-0.146482
0.0952099



femaleDataSets = 0
females = []
lists = []
femaleVectors = 0
femaleSizes = 0

filePath = "Dataset/parameter feature vectors"
for fname in os.listdir(filePath):
    index = fname.find("female")   
    if index != -1:
        females.append(index)
        femaleDataSets +=1
        tempFile = open(filePath+"/"+fname, 'rU') # open each female file
        for line in tempFile:
            femaleVectors +=1
            for word in line.split():
                femaleSizes +=1        
                lists.append(word)
                
print "Number of females: ", femaleDataSets
        
femaleData = np.zeros((femaleSizes, femaleVectors))

for j in range(femaleSizes):
    for i in range(femaleVectors):
        femaleData[j, i] = # fill array  
        
plt.hold('on') 
plt.plot(femaleData[0,:],femaleData[1,:],'r+')
plt.title('Female/Male Feature Vectors')
plt.show()