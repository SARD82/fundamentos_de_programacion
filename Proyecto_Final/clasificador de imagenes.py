# Importamos las librerías necesarias
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical

# Cargamos el dataset de MNIST de dígitos manuscritos
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# Normalizamos los valores de píxeles
x_train, x_test = x_train / 255.0, x_test / 255.0

# Convertimos las etiquetas en categorías
y_train = to_categorical(y_train)
y_test = to_categorical(y_test)

# Creamos el modelo de red neuronal
modelo = Sequential([
    Flatten(input_shape=(28, 28)),  # Aplanamos la imagen de 28x28 píxeles
    Dense(128, activation='relu'),  # Capa oculta con 128 neuronas y función de activación ReLU
    Dense(10, activation='softmax') # Capa de salida con 10 neuronas para clasificar dígitos del 0 al 9
])

# Compilamos el modelo
modelo.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# Entrenamos el modelo
modelo.fit(x_train, y_train, epochs=5, validation_data=(x_test, y_test))

# Evaluamos el modelo en el conjunto de prueba
loss, accuracy = modelo.evaluate(x_test, y_test)
print(f"Pérdida en test: {loss:.2f}, Precisión en test: {accuracy:.2f}")