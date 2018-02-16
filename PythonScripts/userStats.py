import pandas as pd
import numpy as np

df =pd.read_csv('user49.csv')

dfcp=pd.read_csv('mdbcp.csv')
dfData={'id': dfcp['id'],'avg':dfcp['avg']}
df2=pd.DataFrame(dfData)
#print(type(df['id'][0]))
df=df.set_index('id').join(df2.set_index('id'))
df=df.dropna()
df['ratio']=df['rating']-df['avg']
df=df.drop(columns=['rating','avg'])
print(df.head())

#ratio calculated
dfDir=pd.read_csv('dir.csv')
dfDir=dfDir.set_index('id').join(df)
dfDir=dfDir.dropna()
dfDir=dfDir.sort_values('directorId')
dfDir=dfDir.set_index('directorId')
print(len(dfDir),dfDir.head())

#merge by directorId
dfMdb=pd.read_csv('mdbcp.csv')

dfDircp=pd.read_csv('dir.csv')
dfDircp=dfDircp.set_index('directorId').join(dfDir)
dfDircp=dfDircp.fillna(0);
print(len(dfDircp),dfDircp.head())
dfMdb=dfMdb.set_index('id').join(dfDircp.set_index('id'))
print(dfMdb.astype(bool).sum(axis=0))
#rearrange col
#avg,id,popularity,profit,ratio,title
dfMdb=dfMdb.reset_index()
dfMdb=dfMdb[['avg','id','popularity','profit','ratio','title']]
dfMdb['ratio']=dfMdb['ratio'].replace(r'\s+',0, regex=True)
dfMdb=dfMdb.astype({'ratio':'float16'})
dfMdb=dfMdb.sort_values('popularity',ascending=False)
print(dfMdb.head())
dfMdb.to_csv("mdb49.csv",index=False)
