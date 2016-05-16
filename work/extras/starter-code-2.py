
# coding: utf-8

# # Lesson 2 Lab:  Practical Pandas

# _This is a quiz given in Roger Peng's [Coursera](https://www.coursera.org) class [Computing for Data Analysis](https://www.coursera.org/course/compdata).  _
#
# _Sourced from [Research Computing MeetUp's](https://github.com/ResearchComputing/Meetup-Fall-2013) Python course._
#

# In[1]:

import pandas as pd
import os

data = pd.read_csv(os.path.join('..', '..', 'assets', 'dataset', 'ozone.csv'))


# In[2]:

print data.head()


# Print the column names of the dataset to the screen, one column name per
# line.

# In[7]:

for i in data.columns.values:
    print i


# Extract the first 2 rows of the data frame and print them to the console. What does the output
# look like?

# In[ ]:


# How many observations (i.e. rows) are in this data frame?

# In[ ]:


# Extract the last 2 rows of the data frame and print them to the console. What does the output
# look like?

# In[ ]:


# What is the value of Ozone in the 47th row?

# In[ ]:


# How many missing values are in the Ozone column of this data frame?

# In[ ]:


# What is the mean of the Ozone column in this dataset? Exclude missing values (coded as NA)
# from this calculation.

# In[ ]:


# Extract the subset of rows of the data frame where Ozone values are above 31 and Temp values
# are above 90. What is the mean of Solar.R in this subset?

# In[ ]:


# What is the mean of "Temp" when "Month" is equal to 6?

# In[ ]:


# What was the maximum ozone value in the month of May (i.e. Month = 5)?

# In[ ]:


# # Next Steps
#
# **Recommended Resources**
#
# Name | Description
# --- | ---
# [Official Pandas Tutorials](http://pandas.pydata.org/pandas-docs/stable/tutorials.html) | Wes & Company's selection of tutorials and lectures
# [Julia Evans Pandas Cookbook](https://github.com/jvns/pandas-cookbook) | Great resource with eamples from weather, bikes and 311 calls
# [Learn Pandas Tutorials](https://bitbucket.org/hrojas/learn-pandas) | A great series of Pandas tutorials from Dave Rojas
# [Research Computing Python Data PYNBs](https://github.com/ResearchComputing/Meetup-Fall-2013/tree/master/python) | A super awesome set of python notebooks from a meetup-based course exclusively devoted to pandas
