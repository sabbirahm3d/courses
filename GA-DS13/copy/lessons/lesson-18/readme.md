---
title: Progressing in Your Data Science Career
duration: "3:00"
creator:
    name: Arun Ahuja
    city: NYC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Advancing in Data Science
DS | Lesson 18 | [Slides](./assets/slides/slides-18.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*
- Specify common models used within different industries
- Identify the use cases for common models
- Discuss next steps and additional resources for data science learning

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*
- Define the data science workflow
- Apply course information to your own professional interests

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*
- Review [Final Project, pt. 4](../../projects/final-projects/04-notebook-rough-draft/readme.md) and [Part 5](../../projects/final-projects/05-presentation/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-18.md)
- Brainstorm organization assignments for the group activity
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Topic description  |
| 60 mins  | [Real-World ML Systems](#systems)   | Real-World ML Systems |
| 20 mins  | [Exercise](#exercise)   | Group Exercise |
| 20 mins  | [Demo/Codealong](#demo)   | Pipelines in scikit-learn |
| 45 mins  | [Alternative Tools](#alternative)   | Alternative Tools  |
| 20 mins  | [Next Steps](#nextsteps)   | Next Steps |
| 10 mins  | [Conclusion](#conclusion)  | Conclusion |

---
<a name="opening"></a>
## Opening (5 mins)
In this class, we'll focus on adapting the skills of this course in real-world problems.

We will describe what is required to maintain and improve analyses and what steps can be taken to make your work 'production' ready.

Lastly, we will focus on what other tools exist in the data science ecosystem and additional topics you may want to focus on.

***

<a name="systems"></a>
## ML Systems (60 mins)

### Integrating a Model Into a Data Product

As you move on to real-world data science projects, it's important to remember that models and analysis are typically only a single aspect of a larger goal or business objective. Typically, your model or analysis may only answer one of many questions that need to be addressed.

For example, in a system that will present recommendations, we may have many modeling components that come together. Different aspects may categorize content, extract text features, analyze popularity... all of which are then tied together into a final data product.

For example, in Hulu's recommendation system, they pull data from multiple sources, build user profiles and summaries, then apply a recommendation model. However, this isn't the final step! Additional filters are placed to refine the model in order to ensure that predictions are novel and don't overlap with previous content.

![](assets/images/hulu.jpg)

Organizing and managing the systems and data dependencies can become an important part of the job.

![](assets/images/ml-systems.png)

Many organizations rely on data engineering teams to encode these common tasks into pipelines. **Data pipelines** are a series of automated data transformations that ensure the validity of your work for routine data maintenance tasks. Below is a description of the AirBnB model building pipeline.

![](assets/images/airbnb-system.png)

### Model Maintenance

Most of our class has focused on building analysis and models, but once a final model is trained (and good predictive performance is achieved!), then that model needs to be maintained.

As new data is gathered, the model will likely need to be re-trained. Previously predictive features may begin to lose their value, requiring you to investigate once more.

Google addresses this phenomenon, calling it the 'Technical Debt' of a machine learning system in a paper on ["Machine Learning: The High Interest Credit Card of Technical Debt"](http://research.google.com/pubs/pub43146.html)

They focused on a few core issues of model maintenance:
1. Code complexity
2. Evolving features
3. Monitoring and testing

#### Code Complexity

Most of the code in this class has been written in notebooks. However, as your analysis and models develops, you are likely to revise and reuse parts of this code. Improving the quality of the code can go along way to ease this process.

While this isn't always the responsibility of a data scientist, more clarity in the code will often lead to more clarity in the analysis. This is particularly true for long-term or open source projects where your code has to make sense to other people in the future!

One way to write better code is to create and follow a _styleguide_, which is a clear set of rules for your code's organization. In fact, Columbia recently developed a [special styleguide just for data scientists](http://columbia-applied-data-science.github.io/pages/lowclass-python-style-guide.html)!

Some of the rules are pretty straightforward:
- "Give variables, methods, and attributes descriptive names"
- "Write functions that take well-defined inputs and produce well-defined output"

##### Unit Testing
Another common practice in software development is _unit-testing_. Unit-testing involves write short statements that _test_ a piece of code or function you have written. Typically, this test provides a few sample inputs and outputs to ensure your code can produce the same outputs.

According to Google, ___"ensuring that code has been tested is vital to ensuring that your analysis results are correct."___

On long-term or big data projects, the code supporting a machine learning model can get terrifically complex. This "glue code" holds the model together, but can get weighed down with bloat and feature creep over time, which needs to be _refactored_ in order to trim the fat. As Google says:

___"Only a tiny fraction of the code in many machine learning systems is actually doing "machine learning" ... Without care, the resulting system for preparing data in an ML-friendly format may become a jungle of scrapes, joins, and sampling steps, often with intermediate files output. Managing these pipelines, detecting errors, and recovering from failures are all difficult and costly"___

Creating and following a clear styleguide as well as testing and refactoring your code will help you maintain your machine learning algorithm over time. Reducing this _technical debt_ saves time and money in the long term. Even Google is not immune:

___"As a real-world anecdote, in a recent cleanup effort of one important machine learning system at Google, it was possible to rip out tens of thousands of lines of unused, experimental codepaths!"___

**Check:** Take a look at the following code that parses descriptions for an apartment's square footage. In which corner cases would it fail?

```python

def extract_sqft(apt_description):
    # Split the text on spaces
    words = apt_description.split(' ')
    for (i, word) in enumerate(words):
        # Look for "sqft"
        if word == 'sqft':
            # Select the word before sqft
            return int(words[i-1])
        else:
            return np.nan
```

> Answer: There are so many!
- What if the ad says "sqft." instead of sqft?
- What if the ad says "square feet" or "sq ft" etc. ?
- What if the thing before is not an integer?
- What if "sqft" is the first word in the text?

Each of these corner cases would be very good unit tests to improve the code.

**Check:** Think back to your earlier projects; are there any places where your code could be cleaned up and optimized?

#### Evolving Features

Once your model is trained, it's important to track performance over time. Many of the correlations found or features predicted may not remain true a few months or years into the future!

For example, our "evergreen" article prediction example looks for food mentions to predict the popularity of certain recipes. However, it doesn't know how to gauge trends in popular foods! Over time, it will return a smaller and smaller sample unless we readjust the model's parameters.

Google's technical debt paper groups troublesome feature evolution into two groups, _legacy features_ and _bundled features_.

1. Legacy Features: When a feature `F` is included in a model early in its development, but as time goes on, other features are added that make `F` mostly or entirely redundant!

2. Bundled Features: When a group of features are bundled together, it can be hard to identify which features aren't performing well. Features can also be "bundled" with commonly occurring variables, but these occurrences may change over time, making those features obsolete:

__"Machine learning systems often have a difficult time distinguishing the impact of correlated features. This may not seem like a major problem: if two features are always correlated, but only one is truly causal, it may still seem okay to ascribe credit to both and rely on their observed co-occurrence. However, if the world suddenly stops making these features co-occur, prediction behavior may change significantly."__

This is very important for _black-box models_. Such models may rely on correlations from a wide-range of features; however, in doing so we can typically ignore one of two variables that are highly correlated (think of PCA or regularization, where we try to remove correlated features).

In the future, if these two variables are no longer correlated, we may need to update this. This is especially common when analyzing economics and cultural trends.

##### Feedback Loops
Another way in which features may evolve is through _feedback loops_. Once you've performed your analysis or built your model, it's likely you are going to take some action or make a business decision. It's important to track how these actions may end up changing the data you've used in your analysis!

For example, in the health field, many data analysis efforts look for ways to stop infections from spreading in a hospital setting. Suppose that we analyze hospital data and find that whenever a doctor sees more than 5 patients in an hour, those patients are at a greater risk for infection. Following this analysis, the hospital enforces a new rule: doctors' _cannot_ see more than 4 patients in an hour.

At the end of year, if we then attempt to analyze our prior feature of "saw > 5 patients in an hour", it won't exist. Through our intervention, we changed the data.

**Check** Brainstorm two correlated features from prior work in this class that may not be correlated in the future.

#### Monitoring Models

Once a model is deployed and making predictions, it's important to _monitor_ and track its performance. This will also help diagnose any features that are evolving. As Google says:

__"Unit testing of individual components and end-to-end tests of running systems are valuable, but in the face of a changing world, such tests are not sufficient to provide evidence that a system is working as intended. Live monitoring of system behavior in real time is critical."__

One frequently used monitoring technique is to always have a baseline. When you are evaluating your model, it is important to always compare to a simple baseline - something that predicts the average or the most commonly occurring thing.

While monitoring a model, you can evaluate this baseline model over time to ensure that your 'better' model never underperforms it.

In Google's paper [Ad Click Prediction: A View From The Trenches](http://research.google.com/pubs/pub41159.html), they describe more complex monitoring systems that analyze how model performance changes and in which subcategories:

__"Evaluating the quality of our models is done most cheaply through the use of logged historical data ... Because the different metrics respond in different ways to model changes, we find that it is generally useful to evaluate model changes across a plurality of possible performance metrics. We compute metrics such as AucLoss (that is, 1 − AUC, where AUC is the standard area under the ROC and SquaredError ... We also compute these metrics on a variety of sub-slices of the data, such as breakdowns by country, query topic, and layout. ... This is important because click rates vary from country to country and from query to query, and therefore the averages change over the course of a single day. ... A small aggregate accuracy win on one metric may in fact be caused by a mix of positive and negative changes in distinct countries, or for particular query topics. This makes it critical to provide performance metrics not only on the aggregate data, but also on various slicing of the data, such as a per-country basis or a per-topic basis."__


### Ethical Considerations

Another, often overlooked, aspect of managing real-world data science projects are _ethical considerations_! A core aspect of any data science project is understanding the _biases_ of the data we are studying. Data often represent the summary of a system, so any biases within that system will appear in the data and any analysis built from it.

Two common examples of this are in legal sentencing and financial loan applications. In the first, it's common to want to find data-driven solution in criminal justice. Can we analyze what drives crime in certain cities and what actions we can take to reduce it?

 However, most data that is collected on this is based on how the current criminal justice system works. Therefore, it's difficult to separate the biases of the current system from any correlations/predictions that may be found in the model. In other words, we might only find what the system is currently constructed to find.

Similarly, in most financial loan applications, we are interested analyzing applications to identify the best borrowers - who is most likely to pay back in a timely fashion and what rate?

These applications are strongly regulated to ensure that loan officers do not consider protected factors such as race and gender. However, this information can often leak in, even unintentionally!

This can happen with _proxy features_, or features that are strongly correlated with protected factors. For instance, neighborhood zip codes can often be a proxy for race during home loan considerations.

**Check:** Discuss other possible ethical issues in Data Science. How might this occur when examining health data? What about educational records?

<a name="exercise"></a>
## Group Exercise: Data Science in an Organization  (20 mins)
> Instructor Note: Break students into groups of 4-5 students each. Assign each group a company and 1-2 data products or analyses that the company must perform.

1. Brainstorm any maintenance that must be performed on your pre-existing model. When should you re-do your study? What features may change or become difficult to collect in the future?
2. Describe possible interventions; will these interventions change the data you're collecting in the future?
3. Describe any ethical issues that may arise from these tasks.


Example:
- Company: HBO
- Task: Build a customized home screen with recommended shows

1. Maintenance: Popular movies are consistently changing and new movies/shows are added, so the model must be consistently updated. Must be a way to track unexpected events: possibly override recommendations before re-releases or sequel releases.
2. Intervention: Displaying the movies (somewhat a given here). Recommendation systems are where feedback issues are most common: movies not recommended are more likely to fall to the bottom in viewership, making them seem less appealing. Users may not like recommendations and stop using the service altogether.
3. Ethical considerations: Should gender be used in the recommendations? Should the descriptions or images of the movies or shows be altered based on 'perceived' interests of a specific gender?

Example:
- Company: Credit Card Company
- Task: Identify fraudulent transactions

1. Maintenance: User spending likely changes as their income increases. Expensive purchases that may have been expensive (and fraudulent) in previous year may not be this year.
2. Intervention: Block fraud transactions. Another common case of feedback is when the intervention is adversarial. As you find ways to block fraud transactions, they are try to hide their actions better. Suppose we identify 10 common IPs used for fraudulent transaction, if we block those IPs, the fraudsters will likely change.
3. Ethical considerations: Should we immediately block transactions when we believe they are fraudulent or let them occur and review later? Is it more important to have many false positive (incorrectly blocked purchases) or false negatives (missed fraudulent transactions)


<a name="demo"></a>
## Demo: Pipelines in scikit-learn (30 mins)
One way to improve coding and model management is to use pipelines in `scikit-learn`.

These tie to together all the steps that you may need to prepare your dataset and make your predictions.

Because you will need to perform all of the exact same transformations on your evaluation data, encoding the exact steps is important.

```python
from sklearn.pipeline import Pipeline
```

Previously, we looked at building a text classification model using `CountVectorizer`

```python
import pandas as pd
import json

data = pd.read_csv("../../assets/dataset/stumbleupon.tsv", sep='\t')
data['title'] = data.boilerplate.map(lambda x: json.loads(x).get('title', ''))
data['body'] = data.boilerplate.map(lambda x: json.loads(x).get('body', ''))

titles = data['title'].fillna('')

from sklearn.feature_extraction.text import CountVectorizer

vectorizer = CountVectorizer(max_features = 1000,
                             ngram_range=(1, 2),
                             stop_words='english',
                             binary=True)

# Use `fit` to learn the vocabulary of the titles
vectorizer.fit(titles)

# Use `tranform` to generate the sample X word matrix - one column per feature (word or n-grams)
X = vectorizer.transform(titles)
```

We used this input X, a matrix of all common n-grams in the dataset, as an input to our classifier. We wanted to classify how evergreen a story was, based on these inputs.

```python
from sklearn.linear_model import LogisticRegression

model = LogisticRegression(penalty = 'l1')
y = data['label']

from sklearn.cross_validation import cross_val_score

scores = cross_val_score(model, X, y, scoring='roc_auc')
print('CV AUC {}, Average AUC {}'.format(scores, scores.mean()))
```

#### Combining Steps in Pipelines

Often we will want to combine these steps to evaluate some future dataset. Therefore, we need to make sure we perform the _exact same_ transformations on the data. If "has_brownies_in_text" is column 19, we need to make sure it is __also__ column 19 during future evaluation.

Pipelines combines both pre-processing and model building steps into a _single object_. Rather than manually evaluating the transformers and then feeding them into the models, pipelines ties both of these steps together.

Similar to models and vectorizers in scikit-learn, pipelines are equipped with `fit` and `predict` or `predict_proba` methods (as any model would be), but they ensure that proper data transformations are performed.

```python
# Split the data into a training set
training_data = data[:6000]
X_train = training_data['title'].fillna('')
y_train = training_data['label']

# These rows are rows obtained in the future, unavailable at training time
X_new = data[6000:]['title'].fillna('')

from sklearn.pipeline import Pipeline

pipeline = Pipeline([
        ('features', vectorizer),
        ('model', model)   
    ])

# Fit the full pipeline
# This means we perform the steps laid out above
# First we fit the vectorizer,
# And then feed the output of that into the fit function of the model

pipeline.fit(X_train, y_train)

# Here again we apply the full pipeline for predictions
# The text is transformed automatically to match the features from the pipeline
pipeline.predict_proba(X_new)
```

**Check** Add a `MaxAbsScaler` scaling step to the pipeline, which should occur after the vectorization.

#### Merging Feature Sets in Pipelines

Additionally, we want to merge many different feature sets automatically. Here we can use scikit-learn's `FeatureUnion`.

While scikit-learn pipelines help with managing the transformation from raw data, there may be many steps before this takes place in your pipeline. These pipelines are often referred to as _ETL pipelines_ for "Extract, Transform, Load.""

In an _ETL pipeline_, the data is pulled or extracted from some source (like a database), transformed or manipulated, and then "loaded" into whatever system or analysis requires them.

Many data science teams rely on software tools to manage these ETL pipelines. If a transformation step fails, these tools alert you, or ensure that step can be re-run. If these transformation steps need to happen daily or weekly, these tools can manage that timeline.

- One of the most popular Python tools for this is [Luigi](https://github.com/spotify/luigi) developed by Spotify.
- An alternative is [Airflow](https://github.com/airbnb/airflow) by AirBnB.

<a name=""></a>
## Alternative Tools (45 mins)

While most of our class has focused on data science and analytics using Python, there are many other tools out there! Some tools only appear in specific data science roles and may offer different advantages and disadvantages.

### Languages
Aside from Python, other common languages for data scientists include:
- R
- Java & Scala

#### R
"R" is often used in data science. Many features of data analysis with Python have actually been borrowed from R! For example, the Pandas dataframe replicates the functionality of the original R dataframe.

However, R still contains many specialized algorithms. While `statsmodels` and `scikit-learn` combine many of the most popular statistical algorithms, some problems require a more specialized tool. Typically, R has a wider variety of niche algorithms for these cases.

Compared to R, Python has greater speed and an easier ability to tie into other applications. R also has many specialized dataframe operations, but Python code can be faster and more efficient. Python also allows you to connect your analysis to other more useful tools, like web development apps or database services.

#### Java/Scala
Meanwhile, Java/Scala are popular for their link to the _Hadoop ecosystem_. Many larger organizations store their data in a Hadoop system. Most of the adapters that move data in and out these systems are built in Java and Scala.

Therefore, it is sometimes easier to interact with these systems in those languages. However, in most cases, these languages lack the interactivity and ease of use that R and Python provide.

### Modeling Frameworks
While `scikit-learn` is the most popular machine learning framework in Python, there are a few alternatives for specialized use-cases.

For example, most models in `scikit-learn` require datasets to be small enough to fit into memory. Other frameworks can work around this. One example is `xgboost` which provides efficient Random Forest implementations that may train much faster than the models in `scikit-learn`.

Similarly, a library called `Vowpal Wabbit` is often used to train very large linear models, very quickly. This library is developed in C++, with a Python wrapper, and includes many computational tricks to operate on tens of millions of datapoints.

***

<a name="nextsteps"></a>
## Next Steps (20 mins)

Throughout this class, we've focused on statistical knowledge combined with an overview of supervised and unsupervised learning models. But data science is a big field, and for each of these topics, there are many alternative methods!

### Statistical Testing
While it is often not important to have an encyclopedic knowledge of **every possible statistical test**, it may be worth remembering a few common ones and the assumptions they make.

Additionally, it's good to build up a clear sense of distributions and what they look like. Being able to look at a histogram and summarize it by the distribution it resembles makes it easier to discuss your data with others. Here is an example that labels different types of histograms:

![](assets/images/distribution.png)

[](http://blog.cloudera.com/blog/2015/12/common-probability-distributions-the-data-scientists-crib-sheet/)

### Visualization
While most of the plotting in this class was done in Python, these plots are often not the most visually appealing. Visualizing and presenting data is often the best way to transfer information from your work in an effective manner.

To make your plots interactive, you could try using tools like plot.ly or D3.js. We've mentioned plot.ly before, while D3.js is a Javascript library that constructs web-based interactive plots.

[D3 Gallery](https://github.com/mbostock/d3/wiki/Gallery)

### Model Interpretability vs Accuracy
One of the constant trade-offs in data modeling is whether we are more interested in _high predictive accuracy_ or a _high degree of interpretability_.

We saw that linear models are simple, can perform well and offer a concise summary of the impact of various features through the coefficients. However, black-box models such as Random Forests may perform much better (in terms of predictive accuracy) without as much transparency.

In real-world scenarios, you likely to care more about interpretability and insight and prefer simpler models. Logistic and Linear Regression - although simple - are by far the most used tools and important to know well!

When going further in data science, you will see this contrast return again and again. Two methods of advanced analysis perfectly capture this divide.

#### Bayesian Analysis
_Bayesian data analysis_ is a method of analysis that requires you first write down your expectations about the interactions in your world and then attempt to learn how strong those interactions are.

For example, suppose you are analyzing the roll-out of a new educational policy. We want to measure the impact of this policy on some outcome (like test scores).

Similar to our current models, we need to know what else will impact those test scores and build a model to learn the impact of this new policy on those scores.

However, we may want to force additional constraints. For example, we may think that the policy will have a related but different affect in different states.

We can further write down subgroups where the effect may be different because of different reasons (different local resources, demographics, budgets, etc.) and explicitly state how these aspects related to further constrain our model.

These types of Bayesian models are typically small and their main strengths are in interpretability and capturing the amount of uncertainty exists in your data.

Rather than stating that X will change Y by some amount, these models describe a _distribution_, or a range of possible amounts, and attempt to tell what will happen in the best or worst case scenario.

Such models are useful when interpretability and precisely definitions are of utmost importance; for example, when we want a clear definition of how right or wrong we are.  We may want to say that candidate X is likely to win the election, but if we want to quantify the _degree of uncertainty_ for our prediction, then Bayesian models can be useful.

- There are a few tools to build these types of models in Python, one of which is [pymc](http://pymc-devs.github.io/pymc3/). A good reference on this is [Bayesian Methods for Hackers](http://camdavidsonpilon.github.io/Probabilistic-Programming-and-Bayesian-Methods-for-Hackers/).


#### Deep Learning
On the other side of spectrum, powerful models that offer little to no interpretable value are _deep learning_ models.

These models, also known as _neural networks_, are very powerful predictive models, however, they are complex to build and offer little means of extracting the patterns they have learned.

Put simply, these models attempt to operate in a staged fashion. First they perform a dimensionality reduction to extract pattern or representations of the input data. Then these representations are used for the predictive task. This is very similar to a model we saw in this class, using a dimensionality reduction technique followed by a classification technique.

Deep learning models tie these two steps together, attempting to learn the best representation for the task. Additionally, they include many non-linear operations to capture more complex relationships in the data.

Deep learning models are particularly well suited for image or audio analysis.

Python has developed a strong collection of well-written deep learning libraries, which include:
- [Keras](http://keras.io/)
- [lasagne](http://lasagne.readthedocs.org/en/latest/)
- [Tensorflow](https://www.tensorflow.org/)


***

<a name="conclusion"></a>
## Conclusion (10 mins)
- Data science results are often incorporated into a larger final product
- Tracking final products means maintaining models and data pipelines, understanding possible changes overtime, and managing logistical and ethical considerations
- Alternative languages for data science include R or Java/Scala (although Python has many advantages in comparison)
- Visualization skills are vital to communicate and improve your models!
- Advanced machine learning methods you can explore include Bayesian methods and deep learning :)


***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **DUE TODAY**  | [Final Project, Part 4](../../projects/final-projects/04-notebook-rough-draft/readme.md) |
| **UPCOMING PROJECTS**  | [Final Project, Part 5](../../projects/final-projects/05-presentation/readme.md) |


### ADDITIONAL RESOURCES
- [Building Data Pipelines with Python and Luigi](http://marcobonzanini.com/2015/10/24/building-data-pipelines-with-python-and-luigi/)
- [Data Science at Instacart](https://tech.instacart.com/data-science-at-instacart/)
- [Striking a Balance Between Interpretability and Accuracy](https://www.oreilly.com/ideas/predictive-modeling-striking-a-balance-between-accuracy-and-interpretability)
