import cv2
import tensorflow as tf
import numpy as np
from flask import Flask, render_template, request
import os
from werkzeug.utils import secure_filename

CATEGORIES = ["Browsing", "Drinking",
                     "Proper-Driving", "One_Hand",
                     "Stereo", "Phone",
                     "Backseat", "COnversation","Talking on the Phone", "Talking on the phone"]
new_categories = np.array(CATEGORIES)


path1 = 'C:/Users/Chidambar P Bangre/PycharmProjects/untitled3/uploaded/images'

def prepare(filepath):
    IMG_SIZE = 200  # 50 in txt-based
    img_array = cv2.imread(filepath, cv2.IMREAD_GRAYSCALE)
    new_array = cv2.resize(img_array, (IMG_SIZE, IMG_SIZE))
    return new_array.reshape(-1, IMG_SIZE, IMG_SIZE, 1)


#model = tf.keras.models.load_model("cnn.model")
# model = tf.Keras.models.load_model('my_model_name.h5', custom_objects={
#     'Adam': lambda **kwargs: tf.DistributedOptimizer(keras.optimizers.Adam(**kwargs))
# })
model = tf.keras.models.load_model('cnn.model', compile=False)
prediction = model.predict([prepare('talking_L-196.jpg')])
new_prediction = np.array(prediction)
index_max = np.argmax(new_prediction)
# print(index_max)
#print(new_prediction)
#print(prediction)  # will be a list in a list.
a = (new_categories[index_max])
if(index_max == 2):
    Safe = "Safe Driving"
else:
    Safe = "Driver Distracted"

app = Flask(__name__)
@app.route('/')
def upload_f():
    return render_template('upload.html')

@app.route('/uploader', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        # f = request.files['file']

        # f.save(os.path('C:/Users/Chidambar P Bangre/PycharmProjects/untitled3/uploaded/images'))

        val = prediction

        return render_template('pred.html', ss=val, xx=a, safe=Safe)


if __name__ == '__main__':
    app.run(host='192.168.1.13', debug=True)
