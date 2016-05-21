---
title: Statistics Fundamentals pt. 2
duration: "1:45"
creator:
    name: Amy Roberts
    city: NYC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Statistics Fundamentals pt. 2
DS | Lesson 4 | [Slides](./assets/slides/slides-4.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Explain the difference between causation vs. correlation
- Test a hypothesis within a sample case study
- Validate your findings using statistical analysis (p-values, confidence intervals)

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Explain the difference between variance and bias  
- Use descriptive stats to understand your data

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Review [Unit Project 2](../../projects/unit-projects/project-2/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-4.md)
- Read through datasets and starter / solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE

| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Lesson Objectives  |
| 5 min  | [Introduction](#introduction1)   | Causation and Correlation |
| 25 min  | [Lecture](#lecture1)  | Causality vs Correlation |
| 15 min  | [Guided Practice](#guided-practice)  | Confounding and DAGs |
| 5 min  | [Introduction](#introduction2)   | Hypothesis Testing |
| 30 min  | [Demo](#demo)   | Hypothesis Testing: Case Study |
| 5 min  | [Introduction](#introduction3) | Validate your findings |
| 20 min  | [Demo](#demo2)  | P-values, CI: Case Study|
| 35 min  | [Independent Practice](#independent-practice)  | Practice with p-values and CI|
| 15 min  | [Wrap-up](#wrapup)  | Review Guided Practice|


---
<a name="opening"></a>
## Opening (5 min)
- Review any questions from last session
- Discuss Current Lesson Objectives
- Review prior exit tickets

#### Data Source
Today we will use advertising data from an example in
[An Introduction to Statistical Learning by Gareth James](http://www-bcf.usc.edu/~gareth/ISL/Advertising.csv).

> Instructor Note: This is used in the demo and can be downloaded directly from the website by running that specific cell of [demo-starter notebook](./code/starter-code/demo-starter-code-4.ipynb). No other files are needed.  


<a name="introduction"></a>
## Intro: Causation and Correlation (5 mins)
If an association is observed, the first question to ask should always be… is it real?

Just think of all the times you've seen press about foods being good for you then being terrible for you.

![Coffee & Cancer](./assets/images/caffeine-not-causal.png)


Why is this? The first reason might simply be sensational headlines. But the other issue is the neglecting robust data analysis and lacking an understanding of the difference between *causation* and *correlation*.


![Alcohol & Dementia](./assets/images/alcohol-not-causal.png)

Understanding these differences is critical, especially at the beginning of the data science workflow, while **Identifying** and **Acquiring** data.

We need to make sure that we fully articulate our question and use the right data to answer it, including any potential *confounders*.

Additionally, this topic comes up again during the final step in our data science workflow, when we **Present** our results to stakeholders.

It's important that we communicate our findings in a way that doesn't overstate what our model actually measures. For example, be careful not to say "caused" when you really mean "measured" or "associated".


<a name="#lecture1"></a>
## Intro: Causation vs Correlation (10 min)

#### Causal Criteria
Causal criteria is one approach to assessing causal relationships, but it's very hard (nearly impossible!) to define universal *causal* criteria.

One such attempt that is commonly used in the medical/health sciences fields is based on work by Bradford Hill. He developed a list of "tests" that an analysis much pass in order to indicate a causal relationship. These requirements include:

1. Strength of association
2. Consistency
3. Specificity
4. Temporality
5. Biological gradient
6. Plausibility
7. Coherence
8. Experiment
9. Analogy

This is by no means an exhaustive checklist, but it's useful for understanding that your predictor/exposure **must have occurred before your outcome**. For example, in order for smoking to cause cancer, one must have started smoking prior to getting cancer.

Most commonly we find an association between two variables. This means that we observe a **correlation** between our variables.

However, we may not fully understand the causal direction or how other factors may be influencing the association we are observing.

**Check:** What is the difference between causation and association?


<a name="#guided-practice"></a>
## Guided Practice: Confounding and DAGs (15 min)

#### Confounding
Often times, the observation that we observe may be influenced by another *confounding* factor.

Let's say we did an analysis to understand what causes lung cancer. We find a strong association between carrying cigarette lighters and lung cancer.

![Lighters & Cancer](./assets/images/smoking-DAG.png)

In fact, people who carry cigarette lighters are 2.4 times as likely to contract lung cancer as people who don’t carry lighters. However, does this mean that the lighters are causing lung cancer? No.

**Check:** What factor(s) are missing from this model? How might we measure for these?

A *DAG- Directed Acyclic Diagram* is a handy tool to help you determine which variables are most important for your model.

A DAG always includes at least one exposure/predictor and one outcome. For example:

![TV Sales DAG](./assets/images/sales-tv-model-output.png)

Here the exposure/predictor is TV ads and it is associated with an outcome, sales. We can measure the strength to demonstrate a strong association between tv ads and sales.

What other factors may increase sales? What other types of ads? Creating a DAG might then look something like:

`TV Ads --> Sales <-- Google Ads`

### Think, Pair, Share
Let's say we want to evaluate which type of ad is associated with higher sales.

> Instructor Note: Have students draw a basic DAG on their table or board. Take 2 mins and think about other variables that may predict sales. Discuss in small groups and share one or two examples with the class.

> Instructor Note: Be alert for an example of seasonality (or something similar). Use this a jumping off point to connect to confounding.

Great- let's take a look at the association between TV Ads and Sales by taking into account *seasonality*.

On a DAG this would look something like a triangle between:  
`TV--> Sales and seasonality --> TV Ads and seasonality --> Sales`

> Instructor Note: Repeat with a 2nd DAG swapping out TV ads with Google ads.

Let's assume that the TV ads were run in November/December (right before holiday gift season) while the Google ads were run during February & March (when sales are historically low).

If we compare TV and Google Ads but don't take into account seasonality, then we are likely to make the wrong conclusion. In this case, we might assume that Google ads are not as effective at driving sales as tv ads, but this would be an example of *bias* and *confounding*.

**Check:** What is bias and confounding? What could we do differently in this example to avoid these elements?


#### Real World Application
This example highlights a few key takeaways:

1) The importance of having deep subject area knowledge. You'll develop this over time and it will help you move through your analysis in a logical manner. However, keep in mind that you can show a strong association and still be totally wrong.

2) That a DAG (directed acyclic graph) can be a handy tool for thinking through the logic of your models.

3) The distinction between causation and correlation. In our smoking example, it's relatively obvious that there's a flaw in our logic; however, this won't always be so readily apparent... especially in cutting edge fields where there are many other unknown variables.

4) The importance of good data. Throughout the class we will be working on helping you develop your data intuition, so that you can spot gaps and bias more readily. With this will come a bunch of tools to help you. However, your analysis is only as good as your understanding of the problem and the data.


<a name="introduction2"></a>
## Intro: Hypothesis Testing (5 mins)

You'll remember from last time that we worked on descriptive statistics. How would we tell if there is a difference between our groups? How would we know if this difference was real or if our finding is simply due to chance?

These are the questions we often tackle when we are building out our models in the Refine & Build steps of our data science workflow.

For example, if we are working on sales data, how would we know if there was a difference between the buying patterns of men and women at Acme Inc? Hypothesis testing!

#### Hypothesis testing steps
Generally speaking, you start with a null hypothesis and an alternative hypothesis, which is opposite the null. Then, you check whether the data supports rejecting your null hypothesis or failing to reject the null hypothesis.

Note that "failing to reject" the null is ***not*** the same as "accepting" the null hypothesis. Your alternative hypothesis may indeed be true, but you don't necessarily have enough data to show that yet.

This distinction is important to help you avoid overstating your findings. You should only state what your data and analysis can truly represent.

Here is an example of a conventional hypothesis test:

- Null hypothesis: There is no relationship between Gender and Sales.
- Alternative hypothesis: There is a relationship between gender and Sales

Let's dive into this more with the demo.

<a name="demo"></a>
## Demo: Hypothesis Testing Case Study (30 mins)
> Instructor Note: Walk through the demo with students. Throughout the demo there are certain sections marked student questions. Give  students time to answer these questions individually or as a small group (2 min or so per question), then share with the class and discuss before moving on to the next question.

> Instructor Note: Have students open the [guided demo starter code](./code/starter-code/demo-starter-code-4.ipynb) and move through Part 1. Answers can be found in the [demo solution code](./code/solution-code/demo-solution-code-4.ipynb).


**Check:** What is the null hypothesis? Why is this important to use?


<a name="introduction3"></a>
## Intro: Validate your findings (5 mins)
How do we tell if the association we observed is *statistically significant*?

*Statistical Significance* is the likelihood that a result or relationship is caused by something other than mere random chance. Statistical hypothesis testing is traditionally employed to determine if a result is statistically significant or not.

Typically, we use a cut point of 5%. In other words, we say that something is NOT statistically significant if there is a less than 5% chance that our finding was due to chance alone.

When data scientists present results and say we found a significant result- it is almost always using these criteria. Let's dive into them further to understand p-values and confidence intervals.


<a name="demo2"></a>
## Demo: P-values & CI in the case study (20 mins)

> Instructor Note: Have students open the [guided demo starter code](./code/starter-code/demo-starter-code-4.ipynb) and move through Part 2. Answers can be found in the [demo solution code](./code/solution-code/demo-solution-code-4.ipynb).

**Check:** What does a 95% confidence interval indicate?

> Answer: If we repeated our analysis 100 times, the point estimate we found would be there 95% of the time.


<a name="independent-practice"></a>
## Independent Practice (35 min)
For this exercise, you will look through a variety of analyses and interpret the findings.

You will be presented a series of outputs (similar to the ones we will generate once we start regression) and tables from a published analysis.

For this lab you will be asked to read these outputs and tables and determine if the findings are statically significant or not.

You will also get practice looking at the output and understanding how the model was built (e.g. identifying predictor/exposure vs outcome).

> Instructor Note: Have students open and work through the [lab starter code](./code/starter-code/lab-starter-code-4.ipynb).


<a name="wrapup"></a>
## Conclusion: Questions (15 mins)

> Instructor Note: Go over the [lab solutions](./code/solution-code/lab-solution-code-4.ipynb) with the class and clarify any confusing points or remaining questions.

Any questions?

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **UPCOMING PROJECTS**  | [Unit Project 2](../../projects/unit-projects/project-2/readme.md)  |

### ADDITIONAL RESOURCES
- If any
