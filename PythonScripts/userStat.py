import pandas as pd
import numpy as np
df = pd.read_csv('obj49.csv')
print(df.head())
user=df.drop(columns=['userId','timestamp'])
print(user.head())
user.to_csv("user49.csv",index=False)
