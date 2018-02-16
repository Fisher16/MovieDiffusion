import pandas as pd
import numpy as np
df = pd.read_csv('ratings.csv')
tab=df['rating'].as_matrix()
tab*=2
print (np.histogram(tab,bins=[1,2,3,4,5,6,7,8,9,10,11]))
meanCount=df['userId'].value_counts().as_matrix()
print ("AvgCount",np.average(meanCount)," MedianCount ",np.median(meanCount))
print (np.histogram(meanCount,bins=[0,25,50,75,100,125,150,175,200,225,250,300,400,500,600,700,800,900,1000]))
