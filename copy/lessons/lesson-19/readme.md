---
title: Neural Networks and Deep Learning - Flex Lesson
duration: "1:10"
creator:
    name: Jim Simpson
    city: DC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Neural Networks and Deep Learning
DS | Lesson 19 | [Slides](./assets/slides/slides-19.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Understand Neural Networks and their relationship to Logistic Regression
- Understand going from Neural Networks to Deep Learning
- Explain Convolutional Neural Networks
- Build Deep Neural Network Classifiers using TensorFlow

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- You will need to install TensorFlow on your machine using the instructions below.

```
# Ubuntu/Linux 64-bit, CPU only, Python 2.7
export TF_BINARY_URL=https://storage.googleapis.com/tensorflow/linux/cpu/tensorflow-0.9.0-cp27-none-linux_x86_64.whl

# Mac OS X, CPU only, Python 2.7:
export TF_BINARY_URL=https://storage.googleapis.com/tensorflow/mac/tensorflow-0.9.0-py2-none-any.whl

pip install --ignore-installed --upgrade $TF_BINARY_URL
```

See more details at:
https://www.tensorflow.org/versions/r0.9/get_started/os_setup.html#pip-installation

Note:
1. `sudo pip != pip` Don't do `sudo pip` as it says in the link above if you are using anaconda. `sudo pip` will override anaconda and install TF for the system python
2. Don't forget the `--ignore-installed` pip option if you are getting `easy_install` errors during the pip install
3. Don't worry about running on GPU even if your laptop happens to have an NVIDIA graphics. The dependency list is slightly complicated

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Gather materials needed for class
- Complete Prep work required
- Prepare any specific instructions

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Lesson Objectives  |
| 35 min  | [Introduction](#introduction)   | Neural Networks and Deep Learning |
| 10 min  | [Demo](#demo1)  | TensorFlow and Playground |
| 15 min  | [Independent Practice](#ind-practice)  | TensorFlow DNN Classifier |
| 5 min  | [Conclusion](#conclusion)  | Conclusion  |

---

### BEFORE NEXT CLASS


### ADDITIONAL RESOURCES

- http://colah.github.io/posts/2014-03-NN-Manifolds-Topology/
- http://karpathy.github.io/2015/05/21/rnn-effectiveness/
- http://deeplearning.net/tutorial/
- http://keras.io/getting-started/sequential-model-guide/#examples
- http://playground.tensorflow.org
- https://github.com/ChristosChristofidis/awesome-deep-learning
