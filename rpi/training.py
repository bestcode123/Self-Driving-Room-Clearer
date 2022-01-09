import tensorflow.keras as keras
import tensorflow as tf
import cv2
import keras_tuner as kt
import random

ds_train = keras.utils.image_dataset_from_directory(
    'datasets/cvd',
    validation_split=0.1,
    seed=random.randint(0, 1000),
    subset='training',
    image_size=(255, 255),
    label_mode='int',
    color_mode='grayscale'
)

s_val = keras.utils.image_dataset_from_directory(
    'datasets/cvd',
    validation_split=0.1,
    seed=random.randint(0, 1000),
    subset='validation',
    image_size=(255, 255),
    label_mode='int',
    color_mode='grayscale'
)

class_names = ds_train.class_names

model = keras.Sequential([
    keras.layers.Input(shape=(255, 255, 1)),
    keras.layers.AveragePooling2D(4, 2),
    keras.layers.Conv2D(64, 3, activation='relu'),
    keras.layers.Conv2D(32, 3, activation='relu'),
    keras.layers.Dropout(0.8),
    keras.layers.Flatten(),
    keras.layers.Dense(128, activation='relu'),
    keras.layers.Dense(2, activation='softmax')
])

model.compile(
    optimizer='adam',
    loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    metrics=['accuracy']
)

model.fit(ds_train, epochs=10, batch_size=32)

CATEGORIES= ['cats', 'dogs']

def prepare(filepath):
  IMG_SIZE = 255
  pic1 = cv2.imread(filepath, cv2.IMREAD_GRAYSCALE)
  pic2 = cv2.resize(pic1, (IMG_SIZE, IMG_SIZE))
  return pic2.reshape(-1, IMG_SIZE, IMG_SIZE, 1)


pre = model.predict(prepare("/content/dataset/phone/DSCF1893.JPG"))
print(CATEGORIES[int(pre[0][0])])
