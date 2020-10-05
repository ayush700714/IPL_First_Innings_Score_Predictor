import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
df = pd.read_csv('ipl.csv')
df['bat_team'].unique()
present_teams = ['Kolkata Knight Riders', 'Chennai Super Kings', 'Rajasthan Royals',
       'Mumbai Indians', 'Kings XI Punjab',
       'Royal Challengers Bangalore', 'Delhi Daredevils','Sunrisers Hyderabad']
df = df[df['bat_team'].isin(present_teams) & df['bowl_team'].isin(present_teams)]
df['bat_team'].unique()
df.loc[df['bat_team']=='Delhi Daredevils','bat_team']='Delhi Capitals'
df.loc[df['bowl_team']=='Delhi Daredevils','bowl_team']='Delhi Capitals'
df = df[df['overs']>=5.0]
df.drop(['mid','venue','batsman','bowler','striker','non-striker'],axis=1,inplace=True)
df['date'] = pd.to_datetime(df['date'],format = "%Y-%m-%d")
df_encoded = pd.get_dummies(df,columns = ['bat_team','bowl_team'])

X_train = df_encoded.drop(['total'],axis=1)[df_encoded['date'].dt.year<=2016]
X_test = df_encoded.drop(['total'],axis=1)[df_encoded['date'].dt.year>=2017]

y_train = df_encoded['total'][df_encoded['date'].dt.year<=2016].values
y_test = df_encoded['total'][df_encoded['date'].dt.year>=2017].values

X_train.drop(['date'],axis=1,inplace=True)
X_test.drop(['date'],axis=1,inplace=True)

from sklearn.tree import DecisionTreeRegressor

rf = DecisionTreeRegressor()
rf.fit(X_train,y_train)

import pickle
pickle.dump(rf,open('model','wb'))
