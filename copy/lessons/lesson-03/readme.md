---
title: Statistics Fundamentals pt. 1
duration: "1:45"
creator:
    name: Amy Roberts
    city: NYC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Statistics Fundamentals pt. 1
DS | Lesson 3 | [Slides](./assets/slides/slides-3.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Use NumPy and Pandas libraries to analyze datasets using basic summary statistics: mean, median, mode, max, min, quartile, inter-quartile range, variance, standard deviation, and correlation
- Create data visualizations - including: line graphs, box plots, and histograms- to discern characteristics and trends in a dataset
- Identify a normal distribution within a dataset using summary statistics and visualization
- ID variable types and complete dummy coding by hand


### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Create and open an iPython Notebook
- Have completed all of the python pre-work

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Review [project feedback guidelines](../../projects/project-feedback.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-3.md)
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Lesson Objectives  |
| 10 min  | [Introduction](#introduction1)   | Laying the ground work |
| 30 min  | [Codealong](#codealong1)  | Summary statistics in Pandas |
| 10 min  | [Introduction](#introduction2)   | Is this normal? |
| 15 min  | [Demo](#demo)   | Determining the distribution of your data |
| 10 min  | [Guided Practice ](#guidedpractice2)  | Is this skewed?  |
| 20 min  | [Introduction](#introduction3) | Variable types |
| 10 min  | [Demo](#demo2)  | Classes |
| 10 min  | [Independent Practice](#practice)  | Dummy colors |
| 10 min  | [Conclusion](#conclusion)  | Review dummies and lesson objectives |
| 15 min  | [Wrap-up](#wrapup)  | Project questions and Next Project|

---
<a name="opening"></a>
## Opening (5 min)

> Instructor Note: Review Prior Lesson Content & Exit Tickets. Discuss Current Objectives.

<a name="introduction"></a>
## Intro: Laying the ground work (20 mins)

Define:

1. Mean
2. Median
3. Mode
4. Max
5. Min
6. Quartile
7. Inter-quartile Range
8. Variance
9. Standard Deviation
10. Correlation

### Mean
> Source: Content for mean, median and mode sourced from www.yti.edu/lrc/images/math_averages.doc.

The mean of a set of values is the sum of the values divided by the number of values.  It is also called the average.

	Example:  Find the mean of 19, 13, 15, 25, and 18

		19 + 13 + 15 + 25 + 18    =    90   =   18
		_______________________	    _______
			   5		                5


### Median

The median refers to the midpoint in a series of numbers.

To find the median, arrange the numbers in order from smallest to largest. If there is an odd number of values, the middle value is the median. If there is an even number of values, the average of the two middle values is the median.

	Example #1:  Find the median of 19, 29, 36, 15, and 20

		In order:  15,  19,  20,  29,  36  since there are 5 values (odd number), 20 is the median (middle number)

	Example #2:  Find the median of 67, 28, 92, 37, 81, 75

		In order:  28,  37,  67,  75,  81,  92   since there are 6 values (even number), we must average those two  middle numbers to get the median value

		Average:  (67 + 75) / 2  =    142/2    =    71 is the median value


### Mode

The mode of a set of values is the value that occurs most often. A set of values may have more than one mode or no mode.

	Example #1:  Find the mode of  15, 21, 26, 25, 21, 23, 28, 21
	     The mode is 21 since it occurs three times and the other values occur only once.

	Example #2:  Find the mode of 12, 15, 18, 26, 15, 9, 12, 27
	      The modes are 12 and 15 since both occur twice.

	Example #3:  Find the mode of 4, 8, 15, 21, 23
	      There is no mode since all the values occur the same number of times.

**Check:**

A.  For the following groups of numbers, calculate the mean, median and mode by hand:


		1. 18, 24, 17, 21, 24, 16, 29, 18		
			Mean_______
			Median______
			Mode_______
			Max _______
			Min _______

		> Answers:
			Mean = 20.875
			Median = 19.5
			Mode = 18, 24
			Max = 29
			Min = 16

		2. 75, 87, 49, 68, 75, 84, 98, 92			
			Mean_______
			Median______
			Mode_______
			Max _______
			Min _______

		> Answers:
			Mean = 78.5
			Median = 79.5
			Mode = 75
			Max = 98
			Min = 49

		3. 55, 47, 38, 66, 56, 64, 44, 39		
			Mean_______
			Median______
			Mode_______
			Max _______
			Min _______

		> Answers:
			Mean = 51.125
			Median = 51
			Mode = none
			Max = 66
			Min = 38


<a name="#codealong1"></a>
## Codealong: Summary statistics in Pandas (30 min)

> Instructor Note: Have students open the [starter-code](./code/starter-code/starter-code-3.ipynb). Solutions are available in [the solution-code](./code/solution-code/solution-code-3.ipynb).

### Codealong Part 1: Basic Stats-
> Instructor Note: Review "Part 1. Basic Stats" of the [starter-code](./code/starter-code/starter-code-3.ipynb).

We will begin by using pandas to calculate the same Mean, Median, Mode, Max, Min from above.

	Methods available include:
		.min() - Compute minimum value
		.max() - Compute maximum value
		.mean() - Compute mean value
		.median() - Compute median value
		.mode() - Compute mode value
		.count() - Count the number of observations


#### Quartiles and Interquartile Range
Quartiles divide a rank-ordered data set into four equal parts. The values that divide each part are called the first, second, and third quartiles; and they are denoted by Q1, Q2, and Q3, respectively. The interquartile range (IQR) is a measure of variability, based on dividing a data set into quartiles. Let's take a look in the notebook.

### Codealong Part 2: Box Plot
> Instructor Note: Review "Part 2. Box Plot" of the [starter-code](./code/starter-code/starter-code-3.ipynb).

The box plot is a handy graph that gives us a nice visual of these metrics, as well as the quartile and the interquartile range.

#### Bias vs Variance
- **Error due to Bias:** Error due to bias is taken as the *difference between the expected (or average) prediction of our model and the correct value which we are trying to predict.* Imagine you could repeat the whole model building process more than once: each time you gather new data and run a new analysis, thereby creating a new model. Due to randomness in the underlying data sets, the resulting models will have a range of predictions. Bias measures **how far off in general these models' predictions are from the correct value.**  

- **Error due to Variance:** The error due to variance is taken as *the variability of a model prediction for a given data point.* Again, imagine you can repeat the entire model building process multiple times. The variance is **how much the predictions for a given point vary between different realizations of the model.**

![](./assets/images/biasVsVarianceImage.png)

#### Standard Deviation
In statistics, the standard deviation (SD, also represented by the Greek letter sigma `σ` for the population standard deviation, or just `s` for the sample standard deviation) is a measure that is used to quantify the amount of variation or dispersion of a set of data values. **Standard deviation is the square root of the variance.**

#### Standard Error
The _standard error of the mean_ (SEM) quantifies the precision of the mean. It is a measure of **how far your sample mean is likely to be from the true population mean**. It is expressed in the same units as the data.

As the standard error of an estimated value generally increases with the size of the estimate, a large standard error may not necessarily result in an unreliable estimate. Therefore it is often better to compare the error in relation to the size of the estimate.

The regression line is the line that minimizes the sum of squared deviations of prediction (also called the sum of squares error). The standard error of the estimate is closely related to this quantity.


### Codealong Part 3: Standard Deviation & Variance
> Instructor Note: Review "Part 3. SD & Variance" of the [starter-code](./code/starter-code/starter-code-3.ipynb).

To calculate the variance and SD in pandas.

	Methods include:
		.std() - Compute Standard Deviation
		.var() - Compute variance
		.describe() - short cut that prints out count, mean, std, min, quartiles, max

#### Correlation
The correlation is a quantity measuring the extent of interdependence of variable quantities.

**Check:**

1. What is the difference between bias and variance?
>	- A: see graphic above

2. What is a commonly used metric that describes variance?
>	- A: "STD"

3. What is the formula for this metric?
>	- A: square root of variance

#### Context
On many projects, descriptive statistics will be the first - and often times only - step for analysis. Say you need to understand the demographics of your customer base: descriptive stats will give you the answer. You don't necessarily need a fancy model to answer many common business questions.

<a name="introduction2"></a>
## Introduction: Is this normal? (10 mins)
A normal distribution is a key assumption to many models we will later be using. But what is _normal_?

The graph of the normal distribution depends on two factors - _the mean and the standard deviation_. The mean of the distribution determines the location of the center of the graph, and the standard deviation determines the height of the graph. When the standard deviation is large, the curve is short and wide; when the standard deviation is small, the curve is tall and narrow. All normal distributions look like a symmetric, bell-shaped curve.

Two metrics are commonly used to describe your distribution: _skewness and kurtosis_.

**Skewness**  
In probability theory and statistics, skewness is a measure of the asymmetry of the probability distribution of a real-valued random variable about its mean. The skewness value can be positive or negative, or even undefined.

**Kurtosis**  
Kurtosis is a measure of whether the data are peaked or flat relative to a normal distribution.That is, data sets with high kurtosis tend to have a distinct peak near the mean, decline rather rapidly, and have heavy tails.


<a name="demo"></a>
## Demo: Determining the distribution of your data (15 mins)
> Instructor Note: Use the [lesson-3-demo](./code/lesson-3-demo.ipynb) for this section. Walk through each section of the notebook in order.


<a name="guidedpractice2"></a>
## Guided Practice: Is this skewed? (10 mins)

> Instructor Note: Walk through images of normal, skewed, sigmoid (etc) distributions. Stand up and vote on the types. After each image, discuss methods of correcting the issue. Use your own work or review [the sample images from the asset folder](./assets/images/).

For example:

- Skewed? Discuss centering on the mean or median
- Not smooth? Log transformations
- Sigmodial? That's a feature- use logistic regression!

<a name="introduction3"></a>
## Variable Types (5 min)

1. Continuous: Continuous variables are things such as: height, income, etc.
2. Categorical: Categorical variables are things such as: race, gender, paint colors, movie titles, etc

We'll discuss these in future lessons.


<a name="demo2"></a>
## Demo: Classes (15 mins)

### Class/Dummy Variables
Let's say we have a categorical variable called "area". It is saved in our dataset as one of the following strings:  

*	"rural"  
*	"suburban"  
*	"urban"

We have to represent categorical variables numerically, but we can't simply code it `0=rural, 1=suburban, 2=urban` because that would imply an **ordered relationship** between suburban and urban. Is urban somehow "twice" the suburban category? Since an ordered relationship wouldn't make sense, we'll do this by converting our 1 location variable into two new variables: `area_urban` and `area_suburban.`

> Instructor note: Draw this on the board

Using the example above, let's draw out how these variables can be represented mathematically without implying an order. We can do this with 0s and 1s.

One of our categories will be all 0's, that will be our reference category. It is often good to select your reference category to be the group with: 1) the largest sample size and 2) the criteria that will help with your model interpretations. For example, often if you are testing for a disease, the reference category would be people without that disease.

- Step 1: Select a reference category. Here we will choose rural as our reference. Because urban is our reference category, we won't have to include it when we make our two new variables.

- Step 2. Convert the values urban, suburban and urban into a numeric representation that does not imply an order.

- Step 3. Create two new variables:`1area_urban` and `area_suburban`

Why do we only need _two_ dummy variables, not three? Because two dummy variables will capture all of the information about the `area` feature, and implicitly define `rural` as the reference level. In general, if you have a categorical feature with `k` levels, you create `k-1` dummy variables.

 | area_urban | area_suburban
--- | --- | ---
rural | 0 | 0
suburban | 0 | 1
urban | 1 | 0

Great! Let's look at a second example. Let's say we have a category called "gender" with two categories: 1. male and 2. female.  

1. How many dummy variables will we have in our data set? Determine by looking at the # of categories - 1. In this case, 2-1 = 1!
2. We'll make female our reference; therefore, female will be coded 0 and male will be coded 1.

 | gender_female
--- | ---
male | 0
female | 1

We can do this in pandas with the "get_dummies" method. Let's check it out in practice.


<a name="practice"></a>
## Independent Practice: Dummy Colors (15 mins)

It's important to understand the concept before we use `get_dummies` so today we'll create dummy variables by hand. In future classes, we'll use `get_dummies` to create these.  In fact, we'll be using dummy variables in almost every analysis you complete because it is very rare to have continuous variables.

> Instructor Note: Have each student draw a table (like we did above) on the white board or table.

Create dummy variables for the variable "colors" that has 6 categories: blue, red, green, purple, grey, brown. Set grey as the reference.

> Answer:
	| color_blue | color_red | color_green | color_purple | color_brown
--- | --- | --- | --- | --- | ---
blue | 1 | 0 | 0 | 0 | 0
red  | 0 | 1 | 0 | 0 | 0
green | 0 | 0 | 1 | 0 | 0
purple | 0 | 0 | 0 | 1 | 0
grey | 0 | 0 | 0 | 0 | 0
brown | 0 | 0 | 0 | 0 | 1


<a name="conclusion"></a>
## Conclusion (10 mins)

> - Review questions from dummy practice
> - Review objectives from class

<a name="wrapup"></a>
## Project questions and Next Project (15 mins)

> - Review [Project 1](../../projects/unit-projects/project-1/readme.md)
> - Introduce the next project
> - Exit tickets

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **PROJECT 2** | [Unit Project 2](../../projects/unit-projects/project-2/readme.md)   |

### ADDITIONAL RESOURCES
- [Anscombe's quartet](https://en.wikipedia.org/wiki/Anscombe%27s_quartet)
