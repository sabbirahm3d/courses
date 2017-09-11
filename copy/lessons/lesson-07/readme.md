---
title: Evaluating Model Fit
duration: 3:00
creator:
    name: Ed Podojil
    city: NYC
    dataset: citibike ridership and weather data
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Evaluating Model Fit
DS | Lesson 7 | [Slides](./assets/slides/slides-7.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Define regularization, bias, and error metrics for regression problems
- Evaluate model fit by using loss functions including mean absolute error, mean squared error, root mean squared error
- Select regression methods based on fit and complexity

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Understand goodness of fit (r-squared)
- Measure statistical significance of features
- Recall what a _residual_ is
- Implement an sklearn estimator to predict a target variable

### INSTRUCTOR PREP
*Before this lesson, instructors will have to:*

- Review [Unit Project 3](../../projects/unit-projects/project-3/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-7.md)
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Discuss lesson objectives  |
| 10-15 mins  | [Introduction](#introduction-cv)  | Reviewing concepts of error for regression models and cross validation |
| 10-15 mins  | [Demo](#demo-cv)  | Demo using cross validation |
| 20-25 mins  | [Guided Practice](#guided-practice-cv)  | Cross validation in sklearn  |
| 10-15 mins  | [Introduction](#introduction-reg)   | What are Lasso and Ridge doing differently? |
| 10-15 mins  | [Demo](#demo-reg)  | Zeroing coefficients using alpha |
| 20-25 mins  | [Guided Practice](#guided-practice-reg)  | Solving for alpha using a grid search  |
| 10-15 mins  | [Introduction](#introduction-sgd)  | Using Gradient Descent to minimize error |
| 10-15 mins  | [Demo](#demo-sgd)  | Application of Stochastic Gradient Descent |
| 30-35 mins  | [Independent Practice](#ind-practice)  | Create an improved model of bikeshare rider data  |
| 5-10 mins  | [Conclusion](#conclusion)  | Review topics |

---

<a name="opening"></a>
## Opening (5 mins)

- What is r-squared?
- What is a residual?

Recall the central metric introduced for linear regressions, r-squared. If we had to compare two models we **built**, one with an r-squared of .79, and another of .81, which model performed better? If r-squared is an explanation of variance, then we know the value closer to 1 (.82) is a better model. But what about error? Does r-squared tell us how far off our predictions are? Or about the scale of that error? How do you explain r-squared to a business owner?

It is typical to use multiple prediction metrics while solving for an optimal solution to a regression problem. In particular, we're interested in the advantages of a loss function; that is, putting a cost against our prediction algorithm. While we use r-squared to inch our ways closer to 1, we'll explore loss functions and find ways to **refine** our model in order to minimize that value toward 0.

**Check:** What is r-squared? What is a residual?

---

<a name="introduction-cv"></a>
## Introduction: Linear Models and Error (15 mins)

#### Recalling: What's residual error?

In the last class, we reviewed one expectation of linear models: that the residual error be normal, and a median close to 0.

y = betas * x + alpha + epsilon <- epsilon == error

![residual_histogram](https://cloud.githubusercontent.com/assets/846010/11647511/d51bcfa2-9d36-11e5-8496-a29a2b01f5c1.png)

Knowing individual residual error is beneficial to the user, as it demonstrates where your error resides (do you have more outliers estimated too high? too low?). However, it is convoluted and not very effective for optimizing a model around each and every point; instead, we use summary metrics, like _mean squared error_, to summarize the error in our model into one value. Mean squared error is as it sounds: the mean, or average, residual error in our model.

#### Mean Squared Error (MSE)

For squared error, we will:

1. Calculate the difference between each target y and the models predicted predicted value y-hat (this is how we determine the _residual_)
2. Square each residual.
3. Take the mean of the squared residual error.

Sklearn's metrics module includes a mean_squared_error function. Sklearn's metrics module will be the tool we use to evaluate performance for the majority of our models

``` python
from sklearn import metrics
metrics.mean_squared_error(y, model.predict(X))
```

For example, if we to compare two arrays of the same values, we would expect a mean squared error of 0:

```python
from sklearn import metrics
metrics.mean_squared_error([1, 2, 3, 4, 5], [1, 2, 3, 4, 5])
```

```bash
0.0
```

While the opposite scenario should have a mean squared error of 8:

```python
from sklearn import metrics
metrics.mean_squared_error([1, 2, 3, 4, 5], [5, 4, 3, 2, 1])
# (4^2 + 2^2 + 0^2 + 2^2 + 4^2) / 5
```

```bash
8.0
```


#### How do we minimize error?

The regression we've been using in class is called "ordinary least squares," which literally means given a matrix X, solve for the _least_ amount of squared error for y. However, this approach assumes that the sample X is representative of the population; that is, it assumes that the sample is _unbiased_. For example, let's compare these two random models:

```python
import numpy as np
import pandas as pd
from sklearn import linear_model

df = pd.DataFrame({'x': range(100), 'y': range(100)})
biased_df  = df.copy()
biased_df.loc[:20, 'x'] = 1
biased_df.loc[:20, 'y'] = 1

def append_jitter(series):
    jitter = np.random.random_sample(size=100)
    return series + jitter

df['x'] = append_jitter(df.x)
df['y'] = append_jitter(df.y)

biased_df['x'] = append_jitter(biased_df.x)
biased_df['y'] = append_jitter(biased_df.y)

- Fit:
lm = linear_model.LinearRegression().fit(df[['x']], df['y'])
print metrics.mean_squared_error(df['y'], lm.predict(df[['x']]))

- Biased fit:
lm = linear_model.LinearRegression().fit(biased_df[['x']], biased_df['y'])
print metrics.mean_squared_error(df['y'], lm.predict(df[['x']]))
```


![Explanation of bias error](http://i.stack.imgur.com/JLDET.png)

When our error is described as _biased_, it means that the learner's prediction is consistently far away from the actual answer. This is a sign of poor sampling: perhaps the population is not well represented in the model, or other data needs to be collected.

Otherwise, one objective of a _biased_ model is to trade this biased error for _generalized_ error. That is, we'd prefer if the error was distributed more evenly across the model, even if that means it doesn't explain the sample as well. This is called error due to _variance_.

Since the whole point of prediction is for a model to work on data that the model hasn't seen yet, your want your model to perform _generally_ well on new data! If your model has a lot of _bias_, then even if you have a good r-squared or mean squared error from learned data, it could still perform **poorly** on new predictive data.

**Check:** Which of the following scenarios would be better for a weatherman?:

1. Knowing that I can very accurately "predict" the temperature outside from previous days perfectly, but be 20-30 degrees off for future days?
2. Knowing that I can accurately predict the general trend of the temperate outside from previous days, and therefore am at most only 10 degrees off on future days?


> Answer: If you said the second case, you just described what we call a good model fit.

***

<a name="demo-cv"></a>
## Demo: Cross Validation (20 minutes)

One approach data scientists use to account for bias is cross validation. The basic idea of cross validation is to generate several models based on different cross sections of the data, measure performance of each, and then take the mean performance. This technique is one way to swap bias error for generalized error in our model.

In other words, this method helps us create weatherman Scenario 2 - describing previous trends with a general amount of accuracy in order to make more specifically accurate predictions about future trends.

![crossvalidation_kfold](http://i.stack.imgur.com/8hyyh.png)

One of the most common cross validation techniques is called **k-fold**: split the data into _k_ groups, _train_ the data on all segments except one, and then _test_ the performance on the remaining set. If k equals five, then you split the data into five groups and generate five different models.

What happens to mean squared error if we use k-fold validation to _generalize_ the error?

```python
from sklearn import cross_validation
wd = '../../datasets/'
bikeshare = pd.read_csv(wd + 'bikeshare/bikeshare.csv')
weather = pd.get_dummies(bikeshare.weathersit, prefix='weather')
modeldata = bikeshare[['temp', 'hum']].join(weather[['weather_1', 'weather_2', 'weather_3']])
y = bikeshare.casual

kf = cross_validation.KFold(len(modeldata), n_folds=5, shuffle=True)
scores = []
for train_index, test_index in kf:
    lm = linear_model.LinearRegression().fit(modeldata.iloc[train_index], y.iloc[train_index])
    scores.append(metrics.mean_squared_error(y.iloc[test_index], lm.predict(modeldata.iloc[test_index])))

print np.mean(scores)

- This score will be lower, but we're trading off bias error for generalized error:
lm = linear_model.LinearRegression().fit(modeldata, y)
print metrics.mean_squared_error(y, lm.predict(modeldata))
```

**Check:** While the cross validated approach here generated more overall error, which of the two approaches would predict new data more accurately: the single model or the cross validated, averaged one? Why?

***

<a name="guided-practice-cv"></a>
## Guided Practice: Cross Validation with Linear Regression (20 mins)

If we were to continue increasing the number of folds in cross validation, which each increase would also increase the training set? Do you expect error to increase or decrease?

Apply the following code through a loop of numbers 2 to 50 and find answers to the following questions: `range(2, 51, 2)`

1. What does `shuffle=True` do?
2. At what point does cross validation no longer seem to help the model? The error line should look similar to a flat line.

```python
    kf = cross_validation.KFold(len(modeldata), n_folds=i)
    scores = []
    for train_index, test_index in kf:
        lm = linear_model.LinearRegression().fit(modeldata.iloc[train_index], y.iloc[train_index])
        scores.append(metrics.mean_squared_error(y.iloc[test_index], lm.predict(modeldata.iloc[test_index])))
```

***

<a name="introduction-reg"></a>
## Regularization and Cross Validation (15 mins)

#### What's Regularization? And why do we use it?

_Regularization_ is an additive approach to protect models against _overfitting_, or being potentially biased and overconfident. In regressions, regularization becomes an additional weight to coefficients, which is either added (L1) or squared and then added (L2). These are also known as Lasso and Ridge Regressions, which we experimented with during our last class. As good practice, we should use Lasso (L1) when we have a higher number of features (k) than we have observations (n), and use Ridge (L2) in about all other cases.

#### Wait a sec, what's overfitting?

![overfitting](https://cloud.githubusercontent.com/assets/846010/11647961/77c2781e-9d3c-11e5-9793-363dab993e14.png)

Above, we see three different linear models (yes, even the two "curved," polynomial models are linear!).

The first model, which is relatively flat, poorly explains roughly half the data. From our visual, it is clear that this is not a representative model.

The second model, a single polynomial curve, helps explain the general curve of our data. While there is error, it is spread throughout the entire dataset, and if plotted, the residuals would likely be normally distributed.

The last mode, (which is roughly a polynomial model up to the 13th power), is _overfit_ to the data. It matches each value perfectly. However, when attempting to predict new data it has not seen, we would expect this model to fail.

Regularization, which introduces the weights to these coefficients, would help prevent this last model from being a perfect fit, and would generate a model that would be applicable to a wider set of data.

#### Where Regularization Makes Sense
Consider this: what happens to MSE if we just directly use a Lasso or Ridge Regression?

```python
lm = linear_model.LinearRegression().fit(modeldata, y)
print metrics.mean_squared_error(y, lm.predict(modeldata))
lm = linear_model.Lasso().fit(modeldata, y)
print metrics.mean_squared_error(y, lm.predict(modeldata))
lm = linear_model.Ridge().fit(modeldata, y)
print metrics.mean_squared_error(y, lm.predict(modeldata))
```

```bash
1672.58110765 # OLS
1725.41581608 # L1
1672.60490113 # L2
```

In this example; L1 (lasso) massively increases our error (likely from not fitting to the L1 criteria), and L2 also increases the error. What gives?

Regularization, like any important optimization function, will be more important during _cross validation_. In particular, we will optimize the regularization weight parameter _through_ cross validation.

**Check:** Why is regularization important? What does it protect against and how?

***

<a name="demo-reg"></a>
## Demo: Understanding Regularization Effects (15 mins)

**Check:** We are working with the bike-share data to predict riders over hours/days with a few features. Why does it make sense to use a ridge regression over a lasso regression?

Let's test a variety of alpha weights for Ridge Regression on the bike-share data.

```python
alphas = np.logspace(-10, 10, 21)
for a in alphas:
    print 'Alpha:', a
    lm = linear_model.Ridge(alpha=a)
    lm.fit(modeldata, y)
    print lm.coef_
    print metrics.mean_squared_error(y, lm.predict(modeldata))
```

1. What happens to the weights of the coefficients as alpha increases?
2. What happens to the error as alpha increases

**Bonus** Try plotting!

#### Make this easier! Introducing: Grid Search

We can tell sklearn to try all of these alphas in less code using a _grid search_. Grid search sounds exactly like what it means: telling the computer to exhaustively search through all options to find the best solution.

A grid search will end up trying as many combos as you specify in the `param_grid` argument. For example:

```python
{
    'intercept': [True, False],
    'alpha': [1, 2, 3],
}
```

This `param_grid` has 6 different options:

1. intercept True, alpha 1
2. intercept True, alpha 2
3. intercept True, alpha 3
4. intercept False, alpha 1
5. intercept False, alpha 2
6. intercept False, alpha 3

This makes grid search an incredibly powerful tool in machine learning! Check out the example below.

```python
from sklearn import grid_search

alphas = np.logspace(-10, 10, 21)
gs = grid_search.GridSearchCV(
    estimator=linear_model.Ridge(),
    param_grid={'alpha': alphas},
    scoring='mean_squared_error')

gs.fit(modeldata, y)

print -gs.best_score_ # mean squared error here comes in negative, so let's make it positive.
print gs.best_estimator_ # explains which grid_search setup worked best
print gs.grid_scores_ # shows all the grid pairings and their performances.
```

***

<a name="guided-practice-reg"></a>
## Guided Practice: Grid Search CV, Solving for Alpha (25 mins)

Use similar code from above, but now:

1. Introduce cross validation into the grid search. This is accessible from the `cv` argument.
2. Add to the param_grid dictionary fit_intercept = True and False.
3. Re-investigate the best score, best estimator, and grid scores attributes as a result of the grid search.

***

<a name="introduction-gds"></a>
## Minimizing Loss Through Gradient Descent (15 mins)

One last approach to minimizing error is Gradient Descent. The concept behind Gradient Descent could be explained in the following steps:

1. A random linear solution is provided as a starting point (usually a "flat" line or solution)
2. The solver then attempts to find a next step: we take a step in any direction and measure each performance.
3. If the solver finds a better solution (optimizing toward a metric such as mean squared error), this is the new starting point.
4. Repeat these steps until the performance is optimized and no "next steps" perform better. The size of the steps will shrink over time.

Gradient Descent is very similar to traversal or dynamic programming, programming concepts that by design work through iteration. For example, if you had a bunch of user data about Facebook checkins and wanted to solve for the longest path (total number of days) of continual checkins, that would be solved through dynamic programming.


#### Stepping away from the data and getting the concept right

Walk through this code, which suggests a similar pattern to how gradient descent behaves:

```python
num_to_approach, start, steps, optimized = 6.2, 0., [-1, 1], False
while not optimized:
    current_distance = num_to_approach - start
    got_better = False
    next_steps = [start + i for i in steps]
    for n in next_steps:
        distance = np.abs(num_to_approach - n)
        if distance < current_distance:
            got_better = True
            print distance, 'is better than', current_distance
            current_distance = distance
            start = n
    if got_better:
        print 'found better solution! using', current_distance
        a += 1
    else:
        optimized = True
        print start, 'is closest to', num_to_approach

```

**Check:**
1. What is the code doing?
2. What could go wrong?

One particular challenge with gradient descent is that it could potentially solve for a _local_ minimum of error, instead of a _global_ minimum.

##### Global vs Local Minimum
You can think of the difference between _local_ minimum and _global_ minimum in terms of directions. Let's say you're trying to get to your relative's house and you have a choice between shortest distance and fastest route.

A _local_ minimum distance would look at a very small part of the map and try to optimize for that section. This would be equivalent to telling you the "shortest distance," since it only looks at a small sliver of information: your location and your destination.

However, solving for _global_ minimum would be equivalent to choosing the "fastest route". A _global_ minimum distance would zoom out and look at the sum of all the different data sections. This would take into account information that might be left out of a single _local_ minimum sample, like for instance: construction or heavy traffic. In this case, the "fastest route" would give you a more complete set of directions based on a broader sample of the available data.

![Optimum Examples](http://i.stack.imgur.com/XaKx6.png)

In this chart, our local optimum distance gets you close to your desired location but stuck in heavy traffic; meanwhile, the global optimum returns a longer route but is a much better solution for actually getting to where you want to go.

***

<a name="demo-gds"></a>
## Demo: Application of Gradient Descent (15 mins)

Gradient Descent works best when:

1. We are working with a large data set. Smaller sets are more prone to error, and proneness to error could be steps in the wrong direction.
2. Data is severely cleaned up and normalized (such as the bike-share data set).

Gradient descent's advantages are huge: with a very large data set, OLS will take significantly longer to solve (computationally). We may not notice it as much on the smaller data sets in class, but in a live system with millions of data points, gradient descent is vastly superior. You'll particularly see this with the regressors `partial_fit()` function.

Like Ridge and Lasso regression, we can penalize (add in weights) to the gradient descent solver.

To follow along with either our "grandmother's house" example or the python example code above, try turning the estimator's argument `verbose` to 1. It will print its optimizations up to the number of iterations you allow it to run (default is 5).

```python
lm = linear_model.SGDRegressor()
lm.fit(modeldata, y)
print lm.score(modeldata, y)
print metrics.mean_squared_error(y, lm.predict(modeldata))
```

**Check:** Untuned, how well did gradient descent perform compared to OLS?

***

<a name="ind-practice"></a>
## Independent Practice: On your Own (30 mins)

There are tons of ways to approach a regression problem. The regularization techniques appended to ordinary least squares optimizes the size of coefficients to best account for error. Gradient Descent also introduces learning rate (how aggressively do we solve the problem), epsilon (at what point do we say the error margin is acceptable), and iterations (when should we stop no matter what?)

For this deliverable, our goals are to:

- implement the gradient descent approach to our bike-share modeling problem,
- show how gradient descent solves and optimizes the solution,
- demonstrate the grid_search module!

While exploring the Gradient Descent regressor object, you'll build a grid search using the stochastic gradient descent estimator for the bike-share data set. Continue with either the model you evaluated last class or the simpler one from today. In particular, be sure to implement the "param_grid" in the grid search to get answers for the following questions:

1. With a set of alpha values between 10^-10 and 10^-1, how does the mean squared error change?
2. Based on the data, we know when to properly use l1 vs l2 regularization. By using a grid search with l1_ratios between 0 and 1 (increasing every 0.05), does that statement hold true? If not, did gradient descent have enough iterations?
3. How do these results change when you alter the learning rate (eta0)?

**Bonus** Can you see the advantages and disadvantages of using gradient descent after finishing this exercise?

#### Materials:
You can use the following starter code to get started:

```python
params = {} # put your gradient descent parameters here
gs = grid_search.GridSearchCV(
    estimator=linear_model.SGDRegressor(),
    cv=cross_validation.KFold(len(modeldata), n_folds=5, shuffle=True),
    param_grid=params,
    scoring='mean_squared_error',
    )

gs.fit(modeldata, y)

print 'BEST ESTIMATOR'
print -gs.best_score_
print gs.best_estimator_
print 'ALL ESTIMATORS'
print gs.grid_scores_
```

**Check:** Were you able to answer all three questions? What questions do you have?

***

<a name="conclusion"></a>
## Conclusion (5 mins)

#### Lesson Review:

1. What's the (typical) range of r-squared?
2. What's the range of mean squared error?
3. How would changing the scale or interpretation of y (your target variable) effect mean squared error?
4. What's cross validation, and why do we use it in machine learning?
5. What is error due to bias? What is error due to variance? Which is better for a model to have, if it had to have one?
6. How does gradient descent try a different approach to minimizing error?

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **UPCOMING PROJECTS**  |[Final Project, Deliverable 1](../../projects/final-projects/01-lightning-talk/readme.md)  |

### ADDITIONAL RESOURCES
-
