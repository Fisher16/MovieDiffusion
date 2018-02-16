import pandas as pd
import numpy as np

df =pd.read_csv('movies_metadata.csv',low_memory=False)
data={  'id': df['id'],
        'title':df['title'],
        'overview':df['overview'],
        'poster_path':df['poster_path']
        }
mdbEnd=pd.DataFrame(data)
mdbEnd['id']=pd.to_numeric(mdbEnd['id'],errors='coerce')
mdbEnd=mdbEnd.set_index('id')
#4k[30596,1688,48988]
#16k [9993,265189,4912,25541]90125,102001,11228
mdbEnd=mdbEnd.loc[[9993,265189,4912,25541]]
mdbEnd.to_csv("done16k.txt")
