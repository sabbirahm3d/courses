# Project Design Writeup and Approval

### Project Problem and Hypothesis

Heat Replay is a data science project that will attempt to determine if the lyrical content of a song can predict 
if it will hit the Billboard Year-End Hot 100 singles. The project will intersect several datasets to create a final
dataframe that will consist of songs that charted and those that did not chart, with each comprising exactly 50% of 
the set, along with the bag of words version of their lyrics and the analyses on them, such as sentiment analysis, 
frequency of obscene words, frequency of words pertaining to certain themes, total number of unique words, etc. and 
the year they charted. The dataframe will also include the last column 'charted', a binary variable that corresponds
to the chart status of the song. Since the distribution of the charted and uncharted songs will be even, the dataframe
ill be shuffled through some k folds cross validation and then trained through a logistic regression model.

### Drafted structure of features

1. Track information
  1.  Year (int)

2.	Lyrical content
  1.	Frequency of curse words (int)
  2.	Most frequent word (string)
  3.	Density of words (int)
  4.	Number of unique words (int)
  5.  Sentiment analysis (float) (if time allows)

3.	Chart
  1.	Yes (b’1)
  2.	No (b’0)

If this project succeeds, it will be able to determine if the lyrical content affects the popularity of a song. The
features with the most impact in predicting the charting status of a song would probably be the total number of unique
words in the lyrical content.

### Datasets

The following datasets are publicly available:
- [Million Song Dataset](http://labrosa.ee.columbia.edu/millionsong/): 
audio features and metadata for one million contemporary popular music tracks
- [musiXmatch Dataset](http://labrosa.ee.columbia.edu/millionsong/musixmatch): 
lyrics mapping to 77.9% of the songs from the Million Song Dataset

The following datasets are being scraped manually:
- Charted: songs that hit the Billboard Year-End Hot 100 Singles charts scraped from Wikipedia

**For a continuously updated list of datasets to be used, check out the repository for the
[project](https://github.com/kug3lblitz/Heat-Replay/tree/master/src/data).**

### Domain knowledge

I have created and contributed to projects containing a significant amount of natural language processing concepts.
Analysis of the lyrics will be done through these machine learning techniques, so background knowledge in creative
writing or music is not necessary. Prior researches on lyrical analyses have been done, with the most interesting ones
being able to predict the era a song was made in depending on the words of choice or the intelligence level of an artist.
To my understanding, no research exists on predicting if a song will hit the charts based on lyrics.

### Project Concerns

I am not yet sure what models to use for training and testing my data. Creating the datasets themselves
is quite a difficult task, considering the fact that there is plenty of raw and scraped datasets being involved.
The list of songs is at least accurate and can be used against all the other datasets. Generating random song 
names from a given year is also going to be tough, since there is no existing APIs to aid in the process and
thus will have to be scraped manually.

### Outcomes

I am hoping to create several outputs corresponding to the different features in the final dataframe that can
clearly distinguish between the categorical values (charted or uncharted). My model does not have to be very
complicated... it can be several charts visualizing how each features affect the categorization of the songs.
The project needs to be able to represent the data points fairly and that should allow an obvious trend among
the charts.
