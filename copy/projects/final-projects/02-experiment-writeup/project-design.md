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
- [MillionSongDataset](http://labrosa.ee.columbia.edu/millionsong/): 
audio features and metadata for one million contemporary popular music tracks
- [musiXmatch Dataset](http://labrosa.ee.columbia.edu/millionsong/musixmatch): 
lyrics mapping to 23.8% of the songs from the Million Song Dataset

The following datasets are being manipulated and/ or scraped manually:
- **charted_**: generated from scraping Wikipedia and Billboard, contains list of all charted songs from 1961 - 2010, along with year
- **charted2_**: generated from scraping Wikipedia and Billboard, contains list of all charted songs from 2011 - 2015, along with year
- charted: charted_ mapped with the lyrics bag of words of the songs extracted from MetroLyrics
- charted2: charted2_ mapped with the lyrics bag of words of the songs extracted from MetroLyrics
- MSD_: 1% (10000) randomly selected songs subset from the MSD, containing only track_id and year
- **mxm**: musiXmatch dataset, contains all 23.8% of the MSD with mapping to their lyrics bag of words
- MSD_mxm: intersection of MSD_ and mxm
- uncharted: randomly selected songs from MSD_mxm, with mapping to their release years and lyrics bag of words (only covers 1961 - 2010)
- uncharted2: ?
- final: final dataset merging both the charted and uncharted sets, containing year, lyrics bag of words, and the other analyses

**Bold** represents completion of dataset

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg th{font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg .tg-s6z2{text-align:center}
</style>
<table class="tg">
  <tr>
    <th class="tg-s6z2" rowspan="2">Attribute</th>
    <th class="tg-s6z2" colspan="2">1961-2010</th>
    <th class="tg-s6z2" colspan="2">2011-2015</th>
  </tr>
  <tr>
    <th class="tg-s6z2">Charted</th>
    <th class="tg-s6z2">Uncharted</th>
    <th class="tg-s6z2">Charted</th>
    <th class="tg-s6z2">Uncharted</th>
  </tr>
  <tr>
    <td class="tg-s6z2">Year</td>
    <td class="tg-s6z2">MillionSongsSubset, intersected charted songs</td>
    <td class="tg-s6z2">MillionSongsSubset, random uncharted songs</td>
    <td class="tg-s6z2">Wikipedia, during list generation</td>
    <td class="tg-s6z2">?</td>
  </tr>
  <tr>
    <td class="tg-s6z2">Lyrics</td>
    <td class="tg-s6z2">musiXmatch + DataWaves, intersected charted songs</td>
    <td class="tg-s6z2">musiXmatch + DataWaves, random uncharted songs</td>
    <td class="tg-s6z2">DataWaves, MetroLyrics</td>
    <td class="tg-s6z2">?</td>
  </tr>
</table>

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
