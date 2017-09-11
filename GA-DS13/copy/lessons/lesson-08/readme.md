---
title: Introduction to Classification
duration: 2:30
creator:
    name: Ed Podojil
    city: NYC
    dataset: iris dataset
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Introduction to Classification
DS | Lesson 8 | [Slides](./assets/slides/slides-8.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Define class label and classification
- Build a K-Nearest Neighbors using the sci-kit-learn library
- Evaluate and tune model by using metrics such as classification accuracy/error

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Understand how to optimize for error in a model
- Understand the concept of iteration to solve problems
- Measure basic probability

### INSTRUCTOR PREP
*Before this lesson, instructors will have to:*

- Review [Final Project, pt 2](../../projects/final-projects/02-experiment-writeup/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-8.md)
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Discuss lesson objectives  |
| 10-15 mins  | [Introduction](#introduction-class) | What is Classification? |
| 20 mins  | [Guided Practice](#guided-practice-class) | Regression vs Classification |
| 20 mins  | [Independent Practice](#ind-practice-class)  | Build a Classifier |
| 10-15 mins  | [Introduction](#introduction-knn)  | Introduction to K Nearest Neighbors |
| 10-15 mins  | [Demo](#demo-knn)  | Demo of KNN |
| 10-15 mins  | [Introduction](#introduction-eval)   | First Classification Metrics |
| 30-35 mins  | [Independent Practice](#ind-practice-knn)  | Solving for K |
| 5-10 mins  | [Conclusion](#conclusion)  | Review topics |

---

<a name="opening"></a>
## Opening (5 mins)

In class so far, we've primarily worked with regression problems: machine learning approaches to solving or predicting a continuous set of values. Since regressions are continuous (for example, 1 is greater than 0, and 100 is greater than 1), we've been able to use distance to measure how accurate our prediction is.

While predicting something like the cost of a house or the number of clicks on an ad, we use ranges to sort our values. But other problems, like whether a loan is going to default or not, don't make sense within those parameters. A loan is either going to default, or it's not. We call these binary problems.

**Check:** What if we want to build a model to predict set values, like an social media status or photo color? How about the gender of a baby? Do we use regression problems or binary values? Do the same principles apply?

---

<a name="introduction-class"></a>
## Introduction: What is Classification (5 mins)

**Classification** is a machine learning problem for solving a set value given the knowledge we have about that value.

Many classification problems boil down to a *binary* problem. For example, with patient data, one could be working on solving a treatment problem for smokers... but first we need to know if their medical history suggests, or is predictive, of whether the patient is a smoker or not.

Many problems don't appear to be binary at first glance, but with a limited set of variables, you can usually boil your model down to a *boolean* value. For instance, what if you are predicting whether an image pixel will be red or blue? In analyzing the image, we could check whether a pixel "is red" or "is not red."

Binary classification is the simplest form of classification, though classification problems can certainly be wrapped around multiple _class labels_.

### What is a class label?

A class label is a representation of what we are trying to predict: our target. The examples of class labels from above would be:

Data Problem | Class Labels
-------------|--------------
Patient data problem | is smoker, is not smoker
pixel color | red, blue (etc)

The easiest way to understand if our `y`, the dependent variable, is a classification problem or not, is to see if the values can be ordered given math.

For example, if predicting revenue, $100MM is greater than $90MM (and more so, could be negative!), so revenue prediction sounds like a _regression_ problem. Red is not inherently greater than or less than blue, therefore predicting this pixel is a _classification_ problem, with "red" and "blue" as the class labels.

<a name="guided-practice-class"></a>
## Guided Practice: Regression or Classification? (20 mins)

Review the following situations and decide if each one is a regression problem, classification problem, or neither:

1. Using the total number of explosions in a movie, predict if the movie is by JJ Abrams or Michael Bay.
2. Determine how many tickets will be sold to a concert given who is performing, where, and the date and time.
3. Given the temperature over the last year by day, predict tomorrow's temperature outside.
4. Using data from four cell phone microphones, reduce the noisy sounds so the voice is crystal clear to the receiving phone.
5. With customer data, determine if a user will return or not in the next 7 days to an e-commerce website.

**Note:** The primary difference between regression and classification is the _result_; the data used as input should resonate with what we've used in the past. In fact, writing a classifier could look a lot like control flow, a common pattern in coding.

<a name="independent-practice-class"></a>
## Independent Practice: Build a classifier! (20 mins)

With our new knowledge about class labels and classification, it should be relatively straightforward to write a computer program that returns class labels based on some prior knowledge.

Our goal below is to (re) explore the iris dataset, which has 50 samples of 3 different class labels, and see if we can write a program that classifies the data. We can do this very easily with python if-else statements and some pandas functions.

Afterward, measure the _accuracy_ of your classifier using the math of "total correct" over "total samples."

Your classifier should be able to:

1. Get one class label 100% correct: one of the irises is very easy to distinguish from the other 2.
2. Accurately predict the majority of the other two, with some error.
    - Note: the samples for the remaining class labels are a little intertwined, so you may need to _generalize_.

Here's some starter code to get you going:

```python
from sklearn import datasets, neighbors, metrics
import pandas as pd

iris = datasets.load_iris()
irisdf = pd.DataFrame(iris.data, columns=iris.feature_names)
irisdf['target'] = iris.target
cmap = {'0': 'r', '1': 'g', '2': 'b' }
irisdf['ctarget'] = irisdf.target.apply(lambda x: cmap[str(x)])
irisdf.plot('petal length (cm)', 'petal width (cm)', kind='scatter', c=irisdf.ctarget)
print irisdf.plot('petal length (cm)', 'petal width (cm)', kind='scatter', c=irisdf.ctarget)
print irisdf.describe()

# starter code
def my_classifier(row):
    if row['petal length (cm)'] < 2:
        return 0
    else:
        return 1

predictions = irisdf.apply(my_classifier, axis=1)

```

1. How simple could the if-else classifier be to still be _relatively_ accurate?
2. How complicated could this if-else classifier be to be _completely_ accurate? How many if-else statements would you need, or nested if-else statements, in order to get the classifier 100% accurate? (The above uses a count of 2).
3. **RECALL** Which if-else classifier would work better against iris data that it hasn't seen? Why is that the case?

> Instructor Note: See [solution code](./code/solution-code/solution-code-8.ipynb) for more detail.

---

<a name="introduction-knn"></a>
## Introduction: What is K Nearest Neighbors? (5 mins)

K Nearest Neighbors (KNN) is a fairly straightforward algorithm used for classification:

1. For a given point, calculate the distance to all other points.
2. Given those distances, pick the k closest points.
3. Calculate the probability of each class label given those points
4. The original point is classified as the class label with the largest probability ("votes").

KNN uses distance to predict a class label. This is a different application of distance--previously we've used distance to calculate error in regression problems; now, we'll use it as a measure of similarity between classifications.

If I picked an arbitrary M&M's from a table without looking, but knew exactly _where_ I picked it from, I could use the surrounding M&M colors to make my most educated guess of what color candy is in my hand. This is a natural thing to do; if we're unfamiliar with something we're looking at, we'll typically look for things that are similar, identify which traits are shared the most, then use that information to gauge whether the new item is similar to something we already know.

**Check:** Can you think of other examples where we commonly use this heuristic?

---

<a name="demo-practice-knn"></a>
## Demo: KNN In Action

Below is some sample code that loads in the iris dataset.

```python
from sklearn import datasets, neighbors, metrics
import pandas as pd

iris = datasets.load_iris()
# n_neighbors is our option in KNN. We'll tune this value to attempt to improve our prediction.
knn = neighbors.KNeighborsClassifier(n_neighbors=5, weights='uniform')
knn.fit(iris.data[:,2:], iris.target)
print knn.predict(iris.data[:,2:])
print iris.target

print knn.score(iris.data[:,2:], iris.target)
```

Above we have the simplest implementation of KNN using sklearn, attempting to predict one of three iris types based the size of the iris. We use the default `n_neighbors` of 5, which will remove most ties. Of course, there could be ties; for example, if there are three labels, and two of them get two votes each, the last label would get one vote.

### What happens in ties?
It is certainly possible for a KNN classifier to have a tie for votes: in binary classification, we'd see this using 4 for k and each value (0 and 1) getting two votes each. For sklearn, in the case of ties, it will designate the class based on what it saw first in the _training set_.

We can also implement a _weight_, so that the total distance plays a more significant role. Try changing the `weights` argument in the previous code to "distance" and see how it affects the accuracy.

### What happens with high dimensionality?

In regressions, we could use L1 regularization when we have significantly more features than observations.

With KNN, we do _not_ have regularization, and a different problem: since KNN works with distance, higher dimensionality of data (i.e. more features) requires _significantly_ more samples in order to have the same predictive power. Consider this: with more dimensions, all points slowly start averaging out to be equally distant; this causes significant issues for KNN! Keep the feature space limited, and KNN can do well.

In a related example, consider the similarity of users for a particular product. When the product is very broad (for example, a newspaper/news website), the audience will also be very broad, so the newspaper will likely have many features: different sections, topics, types of stories, writers, etc. Yet with so many different different parts that appeal to such a broad audience, user similarity should actually be high!

What about a product like toothpaste? While it also appeals to a broad audience, the _types_ of toothpaste (and the features that separate them) are quite limited. It would be much simpler to identify "distance" between toothpaste users, since the feature set ("has fluoride," "controls tarter", etc) is much smaller.

<a name="introduction-eval"></a>
## Introduction to Classification Metrics

The previous metrics we've used for regressions do not apply for classification.

We _could_ measure distance between the probability of a given class and an item being in the class: for example, guessing .6 for a 1 is a .4 error, while guessing .99 for 1 is .01 error... but this overly complicates our current goal: understanding binary classifications, like whether something is right or wrong.

Instead, let's start with two new metrics, which are inverses of each other: accuracy and misclassification rate.

Accuracy's equation is simple: of all the samples/observations we predicted, how many were correct? This is a value we'd want to increase (like r-squared).

Misclassification rate is directly opposite; of all the samples/observations we predicted, how many were incorrect? This is a value we'd want to decrease (like mean squared error).

Since they are opposite of each other, you can pick one or the other; effectively they will be the same. But when coding, **do** make sure that you are using a classification metric when solving a classification problem!

SKLearn will not intuitively understand if you are doing classification or regression, and accidentally using mean squared error for classification, or accuracy for regression, is a common programming pitfall.

<a name="ind-practice-knn"></a>
## Independent Practice: Solving for K

One of the primary challenges of KNN is solving for k--how many neighbors do we use?

1. The **smallest** k we can use is 1: however, using only one neighbor will probably perform poorly.
2. The **largest** k we can use is n-1; that is, every _other_ point in the data set. But without weighting, this would always set it to the class with the largest sample size! Within the Iris data set, we should see at some value k and greater, the performance will flat line (in a bad way).

Using the [following starter code](./code/starter-code/starter-code-8.ipynb) and the iris data set, test and evaluate the following questions:

1. What is the accuracy for when using k=1?
2. What is the accuracy for using (most of, all) the other points as neighbors perform?
3. At what point, with cross validation, does k optimize accuracy? How many k for the best accuracy score for this data set?

Look at the grid_scores and contextualize the results a bit with a figure using matplotlib, where the x-axis represents `k`, and the y-axis represents accuracy (we call this a "fit chart"). This fit chart, and a print out of the scores, will help you answer the questions above.

```python
from sklearn import grid_search

# some n_list! keep in mind cross validation
# recall: what's an effective way to create a numerical list in python?
params = {'n_neighbors': }

gs = grid_search.GridSearchCV(
    estimator=,
    param_grid=,
    cv=,
)
gs.fit(iris.data, iris.target)
gs.grid_scores_
```

#### Bonus:

1. By default, the KNN classifier in SKlearn uses the _Minkowski metric_ for distance, given p: this is how it decides to calculate distance (using a triangle, p=1 is using the length of sides 1+2 to get the distance from a to c; p=2 using the length of side 3).
    - What _type_ of data does this metric work best for?
    - What _type_ of data does this distance metric may not work for?
        - For help, read about [distance metrics in the sklearn documentation](http://scikit-learn.org/stable/modules/generated/sklearn.neighbors.DistanceMetric.html#sklearn.neighbors.DistanceMetric).
2. It's possible to use KNN as a regression estimator. Using independent reading or your own brilliant creativity, come up with the following:
    - Steps that KNN Regression would follow
    - How it predicts a regression value

> Instructor Note: See [solution code](./code/solution-code/solution-code-8.ipynb) for more detail.

---

<a name="conclusion"></a>
## Conclusion (5-10 mins)

1. What are class labels? What does it mean to classify?
2. How is a classification problem different from a regression problem? How are they similar?
3. How does the KNN algorithm work?
4. What primary parameters are available for tuning a KNN estimator?
5. How do you define: accuracy, misclassification?

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **UPCOMING PROJECTS**  | [Final Project, Deliverable 1](../../projects/final-projects/01-lightning-talk/readme.md)  |

### ADDITIONAL RESOURCES

-
