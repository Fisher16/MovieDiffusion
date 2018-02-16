import pandas as pd
import numpy as np

df =pd.read_csv('interactions16k.txt')
print(df.head())
df = df.groupby(['id']).size().reset_index(name='count')
dfcp=pd.read_csv('mdb49.csv')

df=df.set_index('id').join(dfcp.set_index('id'))
df=df.sort_values('count',ascending=False)
print(df.mean())
df['is_duplicated'] = df.duplicated(subset='title')
df.to_csv("16endDuplicated.csv")
