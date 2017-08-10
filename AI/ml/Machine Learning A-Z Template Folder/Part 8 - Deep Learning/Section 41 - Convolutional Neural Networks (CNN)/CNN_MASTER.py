# Convolutional Neural Network

# Installing Theano
# pip install --upgrade --no-deps git+git://github.com/Theano/Theano.git

# Installing Tensorflow
# Install Tensorflow from the website: https://www.tensorflow.org/versions/r0.12/get_started/os_setup.html

# Installing Keras
# pip install --upgrade keras

##### Part 1 - Building the CNN #######
# Importing the Keras libraries and packages
from keras.models import Sequential     #initialize NN
from keras.layers import Convolution2D  #2D images: 1st step add convolutional layers
from keras.layers import MaxPooling2D   #2D images: 2nd step poolinglayers
from keras.layers import Flatten        #convert pool maps into vector
from keras.layers import Dense          #add full layers into classic ANN

# Initialising the CNN
classifier = Sequential()

# Step 1 - Convolution - 32 Feature detectors 3x3 Feature Detector
#                                                  convert pics to one format 64x64 3colors (tensorflow)
#                                                                 rectifier func 
classifier.add(Convolution2D(32, 3, 3, input_shape = (64, 64, 3), activation = 'relu'))

# Step 2 - Pooling - reduce size of feature maps and therefore neurons
classifier.add(MaxPooling2D(pool_size = (2, 2)))


# Adding a ***second*** convolutional layer on the pooled feature map from previous step
# hence no shape, Keras figures it
classifier.add(Convolution2D(32, 3, 3, activation = 'relu'))
classifier.add(MaxPooling2D(pool_size = (2, 2)))


# Step 3 - Flattening
classifier.add(Flatten())
# print(classifier)

# Step 4 - Full connection
classifier.add(Dense(output_dim = 128, activation = 'relu'))
classifier.add(Dense(output_dim = 1, activation = 'sigmoid')) #binary

# Compiling the CNN - binary cat or dog
classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])

#### Part 2 - Fitting the CNN to the images ####
from keras.preprocessing.image import ImageDataGenerator

train_datagen = ImageDataGenerator(rescale = 1./255,
                                   shear_range = 0.2,
                                   zoom_range = 0.2,
                                   horizontal_flip = True)

test_datagen = ImageDataGenerator(rescale = 1./255)

# rather than depended var, the file name in each folder stipulates category
# keras imports according to special structure
# some image augmentation as well


training_set = train_datagen.flow_from_directory('dataset/training_set',
                                                 target_size = (64, 64),
                                                 batch_size = 32,
                                                 class_mode = 'binary')
# >>> Found 8000 images belonging to 2 classes.

test_set = test_datagen.flow_from_directory('dataset/test_set',
                                            target_size = (64, 64),
                                            batch_size = 32,
                                            class_mode = 'binary')
# >>> Found 2000 images belonging to 2 classes.


# classifier is the model
classifier.fit_generator(training_set,
                         samples_per_epoch = 8000,
                         nb_epoch = 25,
                         validation_data = test_set,
                         nb_val_samples = 2000)