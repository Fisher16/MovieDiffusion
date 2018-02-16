import pandas as pd
import numpy as np

df = pd.read_csv('movies_metadata.csv')
data={  'id': df['id'],
        'revenue': df['revenue'],
        'budget': df['budget'],
        'popularity': df['popularity'],
        'avg': df['vote_average']}
mdb=pd.DataFrame(data)

mdb['id']=pd.to_numeric(mdb['id'],errors='coerce')
mdb['revenue']=pd.to_numeric(mdb['revenue'],errors='coerce')
mdb['budget']=pd.to_numeric(mdb['budget'],errors='coerce')
mdb['popularity']=pd.to_numeric(mdb['popularity'],errors='coerce')
mdb['avg']=pd.to_numeric(mdb['avg'],errors='coerce')


print(type(mdb['id'][0]))



print(mdb.head(),len(mdb))

mdb=mdb[mdb['id'].notnull()]
mdb=mdb[mdb['revenue'].notnull()]
mdb=mdb[mdb['budget'].notnull()]
mdb=mdb[mdb['popularity'].notnull()]
mdb=mdb[mdb['avg'].notnull()]

mdb['avg']=mdb['avg'].divide(2)
mdb['popularity']=mdb['popularity'].apply(np.log)
mdb['divide']=mdb['revenue']/mdb['budget']
mdb['profit']=mdb['divide'].apply(np.log)
mdb=mdb.drop(columns=['divide','budget','revenue'])
mdb['profit']=mdb['profit'].fillna(0)
mdb['profit']=mdb['profit'].replace(np.inf,0)
mdb['profit']=mdb['profit'].replace(-np.inf,0)
mdb['title']=df['title']
mdb=mdb.astype({'id':'int32'})
print(mdb.head(),len(mdb))
mdb=mdb.sort_values('popularity',ascending=False)
print(mdb.head(),len(mdb))
print(mdb.astype(bool).sum(axis=0))
mdb.to_csv("mdbcp.csv",index=False)
