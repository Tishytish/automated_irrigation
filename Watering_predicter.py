import pandas as pd
from sklearn.model _selection import train_test_split
from tensorflow.keras.model import Sequential, load_model
from tensorflow.keras.layers import Dense
from sklearn.metrics import accuracy_score

data = pd.read_csv("Irrigation_automation.csv")

X = data[['soil_moisture', 'temp', 'humidity']]
Y = data [ 'time']

#preprocessing
X_train, X_test, y_train, y_test = train_test_split( X, y, test_size=0.20)

X_train


#Building and compiling the model

model = Sequential()
model.add(Dense(units = 32, activation='relu', input_dim= len(X_train.columns)))
model.add(Dense(units= 64, activation= 'relu'))
model.add(Dense(units= 1, activation = 'sigmoid'))


#compile the model
model.compile(loss='binary_crossentropy', optimizer='sgd', metrics='accuracy')

#fitting and predicting the model
model.fit(X_train, y_train, epochs=200, batch_size=32)
y_hat = model.predict(X_test)
y_hat = [0 if al <0.5 else 1for val in y_hat]
y_hat

accuracy_score(y_test, y_hat)

#saving the model
model.save('irrigationtimeprediction')
