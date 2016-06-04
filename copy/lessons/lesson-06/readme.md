---
title: Intro to Regression Analysis
duration: "02:50"
creator:
    name: Ed Podojil
    city: NYC
    dataset: animal weights and sleeping habit
    dataset: citibike ridership and weather data
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Intro to Regression Analysis
DS | Lesson 6 | [Slides](./assets/slides/slides-6.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Define data modeling and simple linear regression
- Build a linear regression model using a dataset that meets the linearity assumption using the sci-kit learn library
- Understand and identify multicollinearity in a multiple regression.

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Effectively show correlations between an independent variable `x` and a dependent variable `y`
- Be familiar with the `get_dummies` function in pandas
- Understand the difference between vectors, matrices, Series, and DataFrames
- Understand the concepts of outliers and distance.
- Be able to interpret p values and confidence intervals

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Review [Final Project pt 1](../../projects/final-projects/01-lightning-talk/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-6.md)
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Where are we in the Data Science Workflow?  |
| 10 min  | [Introduction](#intro1)   | Simple Linear Regression  |
| 10 min  | [Demo](#demo1)  | Regressing and Normal Distributions   |
| 15 min  | [Guided Practice](#guided-practice1)  | Seaborn & Single Variable Linear Model Plots  |
| 10 min  | [Introduction](#intro2)   | Single Regression Analysis in sklearn  |
| 20 min  | [Demo](#demo2)  | Significance is Key   |
| 15 min  | [Guided Practice](#guided-practice2)  | Using the LinearRegression Object  |
| 20 min  | [Independent Practice](#ind-practice1)  | Base Linear Regression Classes  |
| 10 min  | [Introduction](#intro3)   | Multiple Regression Analysis  |
| 15 min  | [Guided Practice](#guided-practice3)  | Multicollinearity with Dummy Variables |
| 15 min  | [Guided Practice](#guided-practice4)  | Combining Non-Correlated Features |
| 25 min  | [Independent Practice](#ind-practice2)  | Building Models for Other Y Variables  |
| 5 min  | [Conclusion](#conclusion)  | Topic Review  |


---

<a name="opening"></a>
## Opening (5 mins)
#### Where are we in the data science workflow?

The data we are working with for this lesson has been **acquired** and **parsed**. Through today's process we will be **refining** the data and **building** models, using some plotting to **represent** the results.


<a name="intro1"></a>
## Introduction: Simple Linear Regression (10 mins)

#### It starts with a simple correlation

A linear regression is _an explanation of a continuous variable given a series of independent variables._ In it's simplest form, a linear regression reminds us of a basic algebraic function - a line of best fit:

`y = mx + b`

That is: given some value __x__, its power in explanation __m__, and a starting point __b__, explain the value __y__.

However, the power of a linear regression is that we can use linear algebra to explain _multiple_ x's together in order to explain y:

`y = betas * X + alpha (+ error)`

Our terminology is now:

Given a matrix __X__, their relative coefficients __beta__, and a y-intercept __alpha__, explain a dependent vector, __y__.

A linear regression works best when:

* The data is normally distributed (but doesn't have to be)
* The Xs significantly explain y (have low p-values)
* The Xs are independent of each other (low multicollinearity)
* The resulting values passes linear assumptions (dependent on problem)

**Check:** What is linear regression and when can it be applied?


<a name="demo1"></a>
## Demo: Regressing and normal distributions (10 mins)

When working with linear regressions, it helps to have data with normal distributions. Linear regressions have linear solutions, and we want this linear solution to explain the majority, "normal" part of our data; not the outliers! If the data is not normally distributed, the model could introduce _bias_, a term we will be discussing in more detail later on in the course.

For example, let's look at explaining the relationship between an animal's body weight, and their brain weight.

```python
- Import libraries
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import seaborn as sns

- Read in the mammal dataset, and drop missing data.
mammals = pd.read_csv('../data/msleep.csv')
mammals = mammals[mammals.brainwt.notnull()].copy()

- Create a matplotlib figure
plt.figure()

- Generate a scatterplot inside the figure
plt.plot(mammals.bodywt, mammals.brainwt, '.')

- Show the plot
plt.show()
```

![01-mammals-plot](https://cloud.githubusercontent.com/assets/846010/11454352/ccb086ba-95f6-11e5-9fbe-e8d6de9cbe76.png)

In the plot, it's apparent that there is a relationship between the two values, but as it stands, it's not a linear solution. Using the seaborn library, we can plot the linear regression fit with these two variables:

```python
- Generate a plot of a single variable linear model of brain weight given body weight:
sns.lmplot('bodywt', 'brainwt', mammals)
```

![02-mammals-plot](https://cloud.githubusercontent.com/assets/846010/11454353/ccb0d8b8-95f6-11e5-96e2-175c2a4156e1.png)

Notice:

1. The `lmplot()` function returns a straight line. That is why it is a linear solution. If we had multiple variables, the solution would be a linear plane.
2. The linear solution does explain a portion of the data well, but because both "bodywt" and "brainwt" are log-log distributions, outliers effect the weight of the solution poorly. We can see this from the wide and inconsistently shaped confidence intervals that seaborn's lmplot generates.

Because both values are a log-log distribution, some math properties allow us to transform them into normal distributions. Then, we can solve for the linear regression!

```python

- Create a new data set that converts all numeric variables into log10
log_mammals = mammals[['bodywt', 'brainwt']].apply(np.log10)

sns.lmplot('bodywt', 'brainwt', log_mammals)
```

![03-mammals-plot](https://cloud.githubusercontent.com/assets/846010/11454354/ccb17da4-95f6-11e5-98dd-879dd30da086.png)


**Check:** Does this explain the animal's brain weight better or worse than the original data?

Even though we changed the way the data was shaped, this is still a _linear_ result: it's just linear in the log10 of the data, instead of in the data's natural state.


<a name="guided-practice1"></a>
## Guided Practice: Using Seaborn to generate single variable linear model plots (15 mins)

Update and complete the code below to use `lmplot` and display correlations between body weight and two dependent variables: `sleep_rem` and `awake`.

```python
log_columns = ['bodywt', 'brainwt',]  # any others?
log_mammals = mammals.copy()
log_mammals[log_columns] = log_mammals[log_columns].apply(np.log10)

- Complete below for sleep_rem and awake as a y, with variables you've already used as x.
sns.lmplot(x, y, mammals)
sns.lmplot(x, y, log_mammals)
```

> **Check:** Were you successfully able to use the code to determine correlations between body weight and the variables?


<a name="intro2"></a>
## Introduction: Single Regression Analysis in sklearn (10 mins)

#### Defining model objects
When modeling with sklearn, you'll use the following base principals.

1. All sklearn estimators (modeling classes) are based on this [base estimator](http://scikit-learn.org/stable/modules/generated/sklearn.base.BaseEstimator.html). This allows you to easily rotate through estimators without changing much code.
2. All estimators take a matrix, X, either sparse or dense.
3. Many estimators also take a vector, y, when working on a supervised machine learning problem. Regressions are supervised learning because we already have examples of y given X.
4. All estimators have parameters that can be set. This allows for customization and higher level of detail to the learning process. The parameters are appropriate to each estimator algorithm.

```python

- Generate an instance of an estimator class
estimator = base_models.AnySKLearnObject()

- Fit your data
    estimator.fit(X, y)

- Score it with the default scoring method (recommended to use the metrics module in the future)
    estimator.score(X, y)

- Predict a new set of data
    estimator.predict(new_X)

- Transform a new X if changes were made to the original X while fitting
    estimator.transform(new_X)
```

For today, our `LinearRegression()` does not have a transform function... but some do! We will not be using it today.

With this information, we can build a simple process for linear regressions that take advantage of a feature_selection function and the linear regression estimator, as well as get familiar with how to implement parameters.

**Check:** Describe some of the base principles for sklearn model objects.


<a name="demo2"></a>
## Demo: Significance is Key (20 mins)

With the sklearn library, we can generate an sklearn model object and explore important evaluation values for linear regression.

```python

- Import sklearn
from sklearn import feature_selection, linear_model

def get_linear_model_metrics(X, y, algo):
    - Get the pvalue of X given y. Ignore f-stat for now.
        pvals = feature_selection.f_regression(X, y)[1]
    - Start with an empty linear regression object
    - .fit() runs the linear regression function on X and y
    algo.fit(X,y)
        residuals = (y-algo.predict(X)).values

- Print the necessary values
    print 'P Values:', pvals
    print 'Coefficients:', algo.coef_
    print 'y-intercept:', algo.intercept_
    print 'R-Squared:', algo.score(X,y)
    plt.figure()
    plt.hist(residuals, bins=np.ceil(np.sqrt(len(y))))

- Keep the model
    return algo

X = mammals[['bodywt']]
y = mammals['brainwt']
lm = linear_model.LinearRegression()
lm = get_linear_model_metrics(X, y, lm)
```

```bash
P Values: [  9.15540205e-26]
Coefficients: [ 0.00096395]
y-intercept: 0.0859173102936
R-Squared: 0.871949198087
```

![04-mammals-residuals-hist](https://cloud.githubusercontent.com/assets/846010/11454351/cca7186e-95f6-11e5-9e12-e2b7abee9749.png)

**Check:**  What does our ouput tell us?

Our output tells us that:

* The relationship between bodywt and brainwt isn't random (p value approaching 0)
* The model explains, roughly, 87% of the variance of the dataset (the largest errors being in the large brain and body sizes)
* With this current model, `brainwt` is _roughly_ `bodywt * 0.00096395`
* The _residuals_, or error in the prediction, is _not normal_, with outliers on the right. A better with will have similar to normally distributed error.


#### Evaluating Fit, Evaluating Sense

Although we know there is a _better_ solution to the model, we should evaluate some other sense things first. For example, given this model, what is an animal's brainwt if their bodywt is 0?

```python
print lm.predict([[0]])
```

```bash
array([ 0.08591731])
```

**Check:** What would we expect an animal's brainwt to be if their bodywt is 0?

With linear modeling we call this part of the __linear assumption__. Consider it a test to the model. If an animal's body weights nothing, we expect their brain to be nonexistent. That given, we can improve the model by telling sklearn's LinearRegression object we do not want to fit a y intercept.

```python
lm = linear_model.LinearRegression(fit_intercept=False)
lm = get_linear_model_metrics(X, y, lm)
print lm.predict([[0]])
```

```bash
P Values: [  9.15540205e-26]
Coefficients: [ 0.00098291]
y-intercept: 0.0
R-Squared: 0.864418807451
[ 0.]
```

* Now, the model fits where brainwt = 0, bodywt = 0.
* Because we start at 0, the large outliers have a greater effect, so the coefficient has increased.
* Fitting the this linear assumption also explains slightly less of the variance.

**Check:** Is this a better or worse model? Why?


<a name="guided-practice2"></a>
## Guided Practice: Using the LinearRegression object (15 mins)

We learned earlier that the the data in its current state does not allow for the best linear regression fit. With a partner, generate two more models using the log-transformed data to see how this transform changes the model's performance. Complete the following code to update X and y to match the log-transformed data. Complete the loop by setting the list to be one True and one False.

```python
X =
y =
loop = []
for boolean in loop:
    print 'y-intercept:', boolean
    lm = linear_model.LinearRegression(fit_intercept=boolean)
    get_linear_model_metrics(X, y, lm)
    print
```
**Check:** Out of the four, which model performed the best? The worst? Why?


<a name="ind-practice1"></a>
## Independent Practice: Base linear regression classes (20 minutes)

Next class we'll go into further detail on other regression techniques, but for now, experiment with the model evaluation function we have (`get_linear_model_metrics`) with the following sklearn estimator classes to show how easy it is to implement different estimators:

* `linear_model.Lasso()`
* `linear_model.Ridge()`
* `linear_model.ElasticNet()`

**Check:** Did the implementation run without error? What were the r-squared outputs for each estimator?


<a name="intro3"></a>
## Introduction: Multiple Regression Analysis (10 minutes)

In the previous example, one variable explained the variance of another; however, more often than not, we will need multiple variables. For example, a house's price may be best measured by square feet, but a lot of other variables play a vital role: bedrooms, bathrooms, location, appliances, etc. For a linear regression, we want these variables to be largely independent of each other, but all of them should help explain the y variable.

We'll work with bike-share data to showcase what this means and to explain a concept called _multicollinearity_.

#### What is Multicollinearity?

With the bike share data, let's compare three data points: actual temperature, "feel" temperature, and guest ridership. Our data is already normalized between 0 and 1, so we'll start off with the correlations and modeling.

```python
bike_data = pd.read_csv('data/bikeshare.csv')
cmap = sns.diverging_palette(220, 10, as_cmap=True)

correlations = bike_data[['temp', 'atemp', 'casual']].corr()
print correlations
print sns.heatmap(correlations, cmap=cmap)
```

```bash
            temp     atemp    casual
temp    1.000000  0.987672  0.459616
atemp   0.987672  1.000000  0.454080
casual  0.459616  0.454080  1.000000
```
![05-correlation-matrix](https://cloud.githubusercontent.com/assets/846010/11454355/ccb31a7e-95f6-11e5-8bc2-54807b43ad9e.png)

The correlation matrix explains:

* both temperature fields are moderately correlated to guest ridership;
* the two temperature fields are _highly_ correlated to each other.

Including both of these fields in a model could introduce a pain point of _multicollinearity_, where it's more difficult for a model to determine which feature is effecting the predicted value.

We can measure this effect in the coefficients:

```python
y = bike_data['casual']
x_sets = (
    ['temp'],
    ['atemp'],
    ['temp', 'atemp'],
)

for x in x_sets:
    print ', '.join(x)
    get_linear_model_metrics(bike_data[x], y, linear_model.LinearRegression())
    print
```

```bash
temp
P Values: [ 0.]
Coefficients: [ 117.68705779]
y-intercept: -22.812739188
R-Squared: 0.21124654163

atemp
P Values: [ 0.]
Coefficients: [ 130.27875081]
y-intercept: -26.3071675481
R-Squared: 0.206188705733

temp, atemp
P Values: [ 0.  0.]
Coefficients: [ 116.34021588    1.52795677]
y-intercept: -22.8703398286
R-Squared: 0.21124723661
```

Even though the 2-variable model `temp + atemp` has a higher explanation of variance than two variables on their own, and both variables are considered significant (p values approaching 0), we can see that together, their coefficients are wildly different. This can introduce error in how we explain models.

What happens if we use a second variable that isn't highly correlated with temperature, like humidity?

```bash
temp, hum
P Values: [ 0.  0.]
Coefficients: [ 112.02457031  -80.87301833]
y-intercept: 30.7273338581
R-Squared: 0.310901196913
```

While temperature's coefficient is higher, the logical output still makes sense: for guest riders we expected a positive relationship with temperature and a negative relationship with humidity, and our model suggests it as well.

**Check:** What is multicollinearity? Why might this cause problems in a model?


<a name="guided-practice3"></a>
## Guided Practice: Multicollinearity with dummy variables (15 mins)

There can be a similar effect from a feature set that is a singular matrix, which is when there is a clear relationship in the matrix (for example, the sum of all rows = 1).

Run through the following code on your own. What happens to the coefficients when you include all weather situations instead of just including all except one?

```python
lm = linear_model.LinearRegression()
weather = pd.get_dummies(bike_data.weathersit)
get_linear_model_metrics(weather[[1, 2, 3, 4]], y, lm)
print

- Drop the least significant, weather situation  = 4
get_linear_model_metrics(weather[[1, 2, 3]], y, lm)
```

```bash
P Values: [  3.75616929e-73   3.43170021e-22   1.57718666e-55   2.46181288e-01]
Coefficients: [  4.05237297e+12   4.05237297e+12   4.05237297e+12   4.05237297e+12]
y-intercept: -4.05237297302e+12
R-Squared: 0.0233498651216

P Values: [  3.75616929e-73   3.43170021e-22   1.57718666e-55]
Coefficients: [ 37.87876398  26.92862383  13.38900634]
y-intercept: 2.66666666652
R-Squared: 0.0233906873841
```

**Check:** Are students able to explain how coefficients changed once all the weather situations were included?

This model makes more sense, because we can more easily explain the variables compared to the one we left out. For example, this suggests that a clear day (weathersit:1) on average brings in about 38 more riders hourly than a day with heavy snow. In fact, since the weather situations "degrade" in quality (1 is the nicest day, 4 is the worst), the coefficients now reflect that well. However at this point, there is still a lot of work to do, because weather on its own fails to explain ridership well.


<a name="guided-practice4"></a>
## Guided Practice: Combining non-correlated features into a better model (15 mins)

With a partner, complete this code together and visualize the correlations of all the numerical features built into the data set.

We want to:

* Add the three significant weather situations into our current model
* Find two more features that are not correlated with current features, but could be strong indicators for predicting guest riders.

```python
lm = linear_model.LinearRegression()
bikemodel_data = bike_data.join() # add in the three weather situations

cmap = sns.diverging_palette(220, 10, as_cmap=True)
correlations = # what are we getting the correlations of?
print correlations
print sns.heatmap(correlations, cmap=cmap)

columns_to_keep = [] #[which_variables?]
final_feature_set = bikemodel_data[columns_to_keep]

get_linear_model_metrics(final_feature_set, y, lm)
```

**Check:** Were groups able to add all three conditions into the model? Did they come up with two additional predictive features?


<a name="ind-practice2"></a>
## Independent Practice: Building models for other y variables (25 minutes)

We've completely a model together that explains casual guest riders. It's now your turn to build another model, but using a different y variable: registered riders.

**Pay attention to:**

* the distribution of riders (should we rescale the data?)
* checking correlations with variables and registered riders
* having a feature space (our matrix) with low multicollinearity
* model complexity vs explanation of variance: at what point do features in a model stop improving r-squared?
* the linear assumption -- given all feature values being 0, should we have no ridership? negative ridership? positive ridership?

**Bonus**

* Which variables would make sense to dummy (because they are categorical, not continuous)?
* What features might explain ridership but aren't included in the data set?
    * Is there a way to build these using pandas and the features available?

**Outcomes**
If your model at least improves upon the original model and the explanatory effects (coefficients) make sense, consider this a complete task. If your model has an r-squared above .4, this a relatively effective model for the data available. Kudos!

<a name="conclusion"></a>
## Conclusion (5 mins)

- How do you dummy a categorical variable?
    - How do you avoid a singular matrix?
- What is a single linear regression?
- What makes multi-variable regressions more useful?
    - What challenges do they introduce?

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **UPCOMING PROJECTS**  | [Final Project, Deliverable 1](/projects/final-projects/01-lightning-talk/readme.md)  |

### ADDITIONAL RESOURCES
- Add your own resources.
- Go crazy.
- So much room for bullets!
