---
title: Data Science at Scale (Big Data) - Flex Lesson
duration: "1:30"
creator:
    name: Jim Simpson
    city: DC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Data Science at Scale (Big Data)
DS | Lesson 11 | [Slides](./assets/slides/slides-11.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Define Big Data and its challenges
- Understand the Hadoop and Spark ecosystem
- Apply transformations and actions to RDDs
- Build models at scale using Spark MLlib

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- You will need access to a Hadoop+Spark cloud infrastructure for this lesson. We will be using the [Databricks Community Edition (CE)](https://databricks.com/product/faq/community-edition) for our cluster. Sign up for a FREE account beforehand at: [https://databricks.com/ce](https://databricks.com/ce)

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Gather materials needed for class
- Complete Prep work required
- Prepare any specific instructions

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Lesson Objectives  |
| 20 min  | [Introduction](#introduction)   | Intro to Big Data |
| 15 min  | [Demo](#demo1)  | Simple Word Count  |
| 20 min  | [Independent Practice](#ind-practice)  | Word Length Count |
| 25 min  | [Demo](#demo2)  | MLlib Logistic Regression |
| 5 min  | [Conclusion](#conclusion)  | Tunr & HW Review  |

---
<a name="opening"></a>
## Opening (5 min)

- Homework/Pre-work Discussion & Questions
- Review Current Lesson Objectives


<a name="introduction"></a>
# What is Big Data?

Big Data is data that is too big to process or store on a single machine

Processing Challenge:
- Data is growing faster than CPU speeds

Storage Challenge:
- Data is growing faster than single-machine storage


#### Solution

Distributed Computing
- Also known as Cloud Computing
- Also known as Cluster Computing

Use a large number of commodity HW
- Not expensive premium hardware
- Easy to add capacity
- Easy to mix and match HW
- Cheaper per CPU/disk


#### Distributed Computing Challenges

Big Data HW challenges:
- Slow machines
    - Uneven capacity and performance
- HW failures
    - Hard drives, memory, etc all fails
- Increased latency
    - Network speeds slower than bus speeds

Big Data SW challenge:
- How do you program and distribute work


#### Distributed Computing Programming
Map Reduce
- Divide and Conquer

Apache Spark
- Scalable, efficient analysis of Big Data

<a name="conclusion"></a>
## Conclusion (5 mins)

- What is Big Data and what are its challenges?
- What are the differences between Map Reduce and Spark?
- What are the differences between Spark RDDs and Spark DataFrames?

***

### BEFORE NEXT CLASS


### ADDITIONAL RESOURCES

- [Apache Spark Docs](http://spark.apache.org/docs/latest/index.html)
- [Databricks Guide](https://docs.cloud.databricks.com/docs/latest/databricks_guide/index.html)
- [Cloudera Blog](http://blog.cloudera.com)
