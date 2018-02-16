import pandas as pd
import numpy as np
import json
import re
import ast


df = pd.read_csv('credits.csv')
df=df.drop(columns='cast')

test=0
tab =[]

for index, row in df.iterrows():
    lista=ast.literal_eval(row['crew'])
    if len(lista):
        test+=1
        tab.append(lista[0]['id'])
print(test,len(df))

df['directorId']=pd.Series(tab)
df=df[df['directorId'].notnull()]
df=df.astype({'directorId':'int32'})

df=df.drop(columns='crew')
print(df.head())
df.to_csv("dir.csv",index=False)
