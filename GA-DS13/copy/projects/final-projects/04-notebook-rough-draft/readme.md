# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Final Project, Part 4: Modeling Performance

### PROMPT

Our goal for this project is to develop a working technical document that can be shared amongst your peers. Similar to any other technical project, it should surface your work and approach in a human readable format. Your project should push the reader to ask for more insightful questions, and avoid issues like, "what does this line of code do?"

From a presentation perspective, think about the machine learning applications of your data. Use your model to display correlations, feature importance, and unexplained variance. Document your research with a summary, explaining your modeling approach as well as the strengths and weaknesses of any variables in the process.

You should provide insight into your analysis, using best practices like cross validation or any applicable prediction metrics (ex: MSE for regression; Accuracy/AUC for classification). Remember, there are many metrics to choose from, so be sure to explain why the one you've used is reasonable for your problem.

Look at how your model performs compared to a dummy model, and articulate the benefit gained by using your specific model to solve this problem. Finally, build visualizations that explain outliers and the relationships of your predicted parameter and independent variables. You might also identify areas where new data could help improve the model in the future.

**Goal:** Detailed IPython technical notebook with a summary of your statistical analysis, model, and evaluation metrics

---

### DELIVERABLES

#### IPython Report Draft

- **Requirements:**
  - Create an IPython Notebook with code, visualizations, and markdown
  - Summarize your exploratory data analysis.
  - Explain your choice of validation and prediction metrics.
  - Frame source code so it enhances your notebook explanations.
  - Include a separate python module with helper functions
    - Consider it like an appendix piece; although unlike an appendix, it'll be necessary for your project to function!
  - Visualize relationships between your Y and your two strongest variables, as determined by some scoring measure (p values and coefficients, gini/entropy, etc).
  - Identify areas where new data could help improve the model

- **Bonus:**
    - Many modeling approaches are all about fine-tuning the algorithm parameters and trying to find a specific value. Show how you optimized for this value, and the costs/benefits of doing so.

- **Submission:**
  - Completed code (`.py` or `.ipynb` file) and results (`.pdf` or `html` file) over Slack DM to instructor. Please compress multiple files into a single zip file for submission. In most cases we will not have access to your data and it is important for you to share your results in a format that persists. It is easy to download a completed IPython notebook with plots as a pdf or html file.

---

### TIMELINE

| Deadline | Deliverable| Description |
|:-:|---|---|
| Lesson 8 |  Part 1 - Lightning Presentation  | Present 3 Problem Statements   |
| Lesson 14 | Part 2 - Experiment Writeup  |  Research Design Problem Statement & Outline   |
| Lesson 16 | Part 3 - Exploratory Analysis  | Dataset Approval and Exploratory Analysis   |
| Lesson 18 | Part 4 - Notebook Draft  |  IPython Notebook & Model Draft  |
| Lesson 20 | Part 5 - Presentation  | Present Your Final Report   |

---

### EVALUATION
Your project will be assessed using the following standards:

1. Refine the Data

#### Rubric: [Click here for the complete rubric](./final-project-4-rubric.md).

Requirements for these standards will be assessed using the scale below:

    Score | Expectations
    ----- | ------------
    **0** | _Incomplete._
    **1** | _Does not meet expectations._
    **2** | _Meets expectations, good job!_
    **3** | _Exceeds expectations, you wonderful creature, you!_

While your total score may serve as a helpful gauge of whether you've met project goals, __specific standards scores are more important__ since they can show you where to focus your efforts in the future!

---

### RESOURCES

#### Suggestions for Getting Started

- Two common ways to start models:
    -  "Kitchen Sink Strategy": throw all the variables in and subtract them out, one by one.
    -  "Single Variable Strategy": start with the most important variable and slowly add in while paying attention to performance)
        - It may be worth exploring both to understand your data and problem. How slow is building and predicting the model with all the variables? How much improvement is made with each variable added?
- Recall that your variables maybe need transformation in order to be most useful.
- Algorithms have different requirements (say, random forest vs logistic regression), and one may work better for your data than another.
- Strike a balance between writing, code, and visual aids. Your notebook should feel like a blogpost with some code in it. Force yourself to write and visualize more than you think!

#### Specific Tips

- This deliverable combines unit Projects 3 and 4 from earlier in the course; however, now you will be using your own data! But feel free to refer to any resources and feedback provided during those projects.

#### Past Projects

- You can find previous General Assembly Presentations and Notebooks at the [GA Gallery](https://gallery.generalassemb.ly/DS?metro=).

#### Additional Links

- [SKLearn's documentation on metrics](http://scikit-learn.org/stable/modules/classes.html)
- [SKLearn's model evaluation](http://scikit-learn.org/stable/modules/model_evaluation.html)

---
