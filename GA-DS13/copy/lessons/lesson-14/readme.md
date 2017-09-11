---
title: Latent Variable NLP
duration: "3:00"
creator:
    name: Arun Ahuja
    city: NYC
---


# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Latent Variables and Natural Language Processing
DS | Lesson 14 | [Slides](./assets/slides/slides-14.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Understand what _latent_ variables are
- Understand the uses of _latent variables_ in language processing
- Use the _word2vec_ and _LDA_ algorithms of `gensim`

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Install `gensim` with `pip install gensim`
- Recall and apply _unsupervised learning_ techniques
- Recall probability distributions, specifically discrete multinomial distributions
- Recall NLP essentials, including experience with `spacy`
- _BONUS_: If you are interested in accessing the Twitter API, you'll need to setup Twitter API credentials. [Here are instructions](./code/twitter-instructions.md)

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Review [Final Project, pt. 3](../../projects/final-projects/03-exploratory-analysis/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-14.md)
- Read through the starter/solution code.
- Pull the "stumbleupon" dataset from Lesson 13.
- Add to the "Additional Resources" section for this lesson
- Setup Twitter API credentials for accessing and receiving tweets. Instructions [can be found here](./code/twitter-instructions.md)

> Note: The demo and starter code for this lesson is written in Python 3.4, not 2.7. This bug fix has been flagged and will be patched shortly. In the meantime, please reload Anacondas for Python 3.4 to correctly run the code for this lesson.

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 5 min  | [Opening](#opening)  | Latent Variable Models |
| 50 mins  | [Introduction](#introduction-nlp)   |  Latent Variables In Text Processing  |
| 30 mins  | [Demo](#demo-lda)  | Latent Dirichlet Allocation in gensim |
| 20 mins  | [Introduction](#introduction-word2vec)   | word2vec  |
| 20 mins  | [Demo](#demo-word2vec)  | word2vec in gensim |
| 45 mins  | [Independent Practice](#ind-practice)  | Twitter Lab  |
| 10 mins  | [Conclusion](#conclusion)  | Lesson Review  |

---

<a name="Opening"></a>
## Opening

This lesson will continue on natural language processing with an emphasis on _latent variable models_.

In our data science workflow, we will often be MINING datasets with a large amount of text or unstructured data. In our last class, we saw many techniques for MINING this data, including pre-processing and building linguistic rules to uncover patterns. We could also create _classifiers_ from this unstructured data. In this class, we'll continue with methods for MINING or REFINING our understanding of text data by attempting to uncover structure or organization inherent in the text.

Many of the advances in natural language processing have been about using data to learn the rules of grammar and language and then using those tools to extract information or build classification algorithms from the text. We saw these tools in our last class, including:

- _Tokenization_ to break apart pieces of text
- _Stemming_ or _lemmatization_ to understand bases or roots of words
- _Parsing_ and _tagging_ to understand each piece of the sentences.

Each of these are based on a classical or theoretical understanding of language - essentially, attempting to re-create the rules that guide language.

_Latent variable models_ are different in that instead of attempting to recreate rules of language, we'll try to understand language based on **how** the words are used. For example, we won't attempt to learn that 'bad' and 'badly' are related because they share the same root, but instead we'll determine that they are related because they are often used in the same way often or near the same words.

We'll use _unsupervised_ learning techniques (discovering patterns or structure) to extract the information.

Rather than inferring that 'Python' and 'C++' are both programming languages because they are often a noun preceded by the verb 'program' or 'code', we'll infer a category by identifying that they are often used in the same way. We won't need to guide them with particular phrases to look for parts of speech.


<a name="introduction-nlp"></a>
## Introduction: Latent Variable Models (55 mins)

_Latent variable models_ are models in which we assume that the data we are observing has some hidden, underlying structure that we can't see, and which we'd like to learn. These hidden, underlying structure are the _latent_ variables we want our model to understand.

Text processing is a common application of latent variable models. Again, in the classical sense we know that language is built by a set of pre-structured grammar rules and vocabulary; however, we also we know that we break those rules pretty often and create new words that get added into our vocabulary (see: selfie).

Instead of attempting to learn the rules of 'proper' grammar, we instead look to uncover the hidden structure and ignore preexisting rules (which might not even describe our syntax anyway). Sometimes, the hidden structure we uncover _are_ the basic rules of our language, but sometimes they may also unveil something new.

These techniques are commonly used for recommending news articles or mining large troves of data data and trying to find commonalities. Topic modeling, a method we will discuss in today's class, is used in the [NY times recommendation engine](http://open.blogs.nytimes.com/2015/08/11/building-the-next-new-york-times-recommendation-engine/?_r=0). They attempt to map their articles to a latent space (or underlying structure) of topics using the content of the article.

![Frick Museum](./assets/images/frick_museum2.png)

[Lyst](http://developers.lyst.com/2014/11/11/word-embeddings-for-fashion/), an online fashion retailer, uses latent representations of clothing descriptions to find similar clothing. If we can map phrases like 'chelsea boot' or 'felted hat' to some underlying structure, we can use that new structure to find similar products.


### Dimensionality Reduction in Text Representation

Our previous 'representation' of a set of text documents (articles) for classification was a matrix with one row per document and one column per word (or _n-gram_).

![Word Factorization Matrix](./assets/images/word-matrix-factorization.png)

While this does sum up most of the information, it does drop a few things - mostly structure and order. Additionally, many of the columns may be dependent on each other (or correlated).

For example, an article that contains the word 'IPO' is also likely to contain the work 'stock' or 'NASDAQ'.  Therefore, those columns are repetitive and both of those columns likely represent the same 'concept' or idea. For classification, we may not care if the document has the word 'IPO' or 'NASDAQ' or 'stocks', but just that it has financial-related words.

One way to do this is with regularization - `L1` or `lasso` regularization tends to remove repetitive features by bringing their learned coefficients to 0.

Another is to perform `dimensionality reduction` - where we first identify the correlated columns and then replace them with a column that represents the concept they have in common. For instance, we could replace the 'IPO', 'stocks', and 'NASDAQ' column with a single - 'HasFinancialWords' column.

There are many techniques to do this automatically and most follow a very similar approach:

1. Identify correlated columns
2. Replace them with a new column that encapsulates the others

The techniques vary in how they define correlation and how much of the relationship between the original and new columns you need to save.

There are many dimensionality techniques built into `scikit-learn`. One of the most common is **PCA** or **Principal Components Analysis**. Like most of the models we've seen, dimensionality techniques can vary between _linear_ or _non-linear_, meaning that they pick up linear or non-linear correlations between columns.

**PCA** when applied to text data is sometimes known as **LSI** or **Latent Semantic Indexing**.

### Mixture Models and Language Processing

Mixture models (and specifically **LDA** or **Latent Dirichlet Allocation**) take this concept further and generate more structure around the documents. Instead of just replacing correlated columns, we create clusters of common words and generate probability distributions to explicitly state how related words are.

To understand this better, let's imagine a new way to generate text:

1. Start writing a document
    1. First choose a topic (sports, news, science)
        1. Choose a word from that topic
    2. Repeat
2. Repeat for the next document

What this 'model' of text is assuming is that each document is some _mixture_ of topics. It may be mostly science, but may contain some business information. The _latent_ structure we want to uncover are the topics (or concepts) that generated that text.

![Latent Dirichlet Allocation](./assets/images/lda-mixture-graphic.jpg)

_Latent Dirichlet Allocation_ is a model that assumes this is the way text is generated and then attempts to learn two things:

    1. What is the _word distribution_ of each topic?
    2. What is the _topic distribution_ of each document?

The _word distribution_ is a multinomial distribution for each topic representing what words are most likely from that topic.

Let's say we have 3 topics: sports, business, science.
For each topic, we uncover the words most likely to come from them:

```
sports: [football: 0.3, basketball: 0.2, baseball: 0.2, touchdown: 0.02 ... genetics: 0.0001]

science: [genetics: 0.2, drug: 0.2, ... baseball: 0.0001]

business: [stocks: 0.1, ipo: 0.08,  ... baseball: 0.0001]
```

For each word and topic pair, we learn some `P ( word | topic) `

The _topic distribution_ is a multinomial distribution for each document representing which topics are most likely to be in that document. For all documents, we then have a distribution over {sports, science, business}

```
ESPN article: [sports: 0.8, business: 0.2, science: 0.0]
Bloomberg article: [business: 0.7, science: 0.2, sports: 0.1]
```

For each topic and document pair, we learn some `P ( topic | document) `

![LDA Topic Allocation](./assets/images/lda-topic-distribution.jpg)

Topic models are useful for organizing a collection of documents and uncovering the main underlying concepts.

There are many variants as well, that attempt to incorporate more structure into the 'model'

 - Supervised Topic Models
    - Guide the process with pre-decided topics
 - Position-dependent topic models
    - Ignore which words occur in what document but instead focus on _where_ they occur
 - Variable number of topics
    - Test a different number of topics to find the best model

**Check:** Take any recent news-article and brainstorm which 3 topics this story is most likely made up of. Next, brainstorm which words are most likely derived from which of those 3 topics.


<a name="demo-lda"></a>
## Demo: LDA in gensim (30 mins)

```python
import gensim
```

`gensim` is another library of language processing tools focused on latent variable models of text.

We begin by first translating our set of documents (articles) into the same matrix representation, with a row per document and a column per feature (word or n-gram).

```python
from sklearn.feature_extraction.text import CountVectorizer

cv = CountVectorizer(binary=False,
                     stop_words='english',
                     min_df=3)

docs = cv.fit_transform(data.body.dropna())

# Build a mapping of numerical ID to word
id2word = dict(enumerate(cv.get_feature_names()))
```

We want our model to learn:
- Which columns are correlated (i.e. likely come from the same topic)? This is the _word distribution_.
- Which topics are in each document? This is the _topic distribution_.

```python
from gensim.models.ldamodel import LdaModel
from gensim.matutils import Sparse2Corpus

# First we convert our word-matrix into gensim's format
corpus = Sparse2Corpus(docs, documents_columns = False)

# Then we fit an LDA model
lda_model = LdaModel(corpus=corpus, id2word=id2word, num_topics=15)
```

In the model above, we need to explicitly specify the number of topics we want the model to uncover. This is a critical step but unfortunately there is not a lot of guidance on the best way to select it. Having domain knowledge about your data may help.

Once we have `fit` this model, like other unsupervised learning techniques, most of our validation techniques are mostly about interpretation.

- Did we learn reasonable topics?
- Do the words that make up a topic make sense?

We can evaluate this by viewing the top words for each topic:

`gensim` has a `show_topics` function for this.

```python

num_topics = 25
num_words_per_topic = 5
for ti, topic in enumerate(lda.show_topics(num_topics = num_topics, num_words_per_topic = n_words_per_topic)):
    print("Topic: %d" % (ti))
    print (topic)
    print()
```

While some of the concepts may not make sense, some may represent clear concepts:

```
0.009*cup + 0.009*recipe + 0.007*make + 0.007*food + 0.006*sugar
```
is a topic mostly related to cooking and recipes.

As is:

```
0.013*butter + 0.010*baking + 0.010*dough + 0.009*cup + 0.009*sugar
```

while:

```
0.013*fashion + 0.006*like + 0.006*dress + 0.005*style
```
is a topic mostly related to fashion and style.

**Check:** Demonstrate the code you used to generate the topics above. Hypothesize other topic interpretations.


<a name="introduction-word2vec"></a>
## Introduction: Word2Vec (20 mins)

`Word2Vec` is another unsupervised model for latent variable natural language processing. It is a model that was [originally released by Google](https://code.google.com/p/word2vec/) and further [improved at Stanford](http://nlp.stanford.edu/projects/glove/)

This model creates *word vectors*, which are multi-dimensional representations of words. This is similar to having a distribution of concepts or topics that the word is associated with.

If we take our usual document-word matrix (from `CountVectorizer`) and take its transpose (by flipping it on it's side), instead of talking about words as features of a document, we can talk about _documents as features of a specific word_. In other words, how do we define or characterize a single word?

We can do this by:

1) Defining it's dictionary definition, or
2) Enumerating all the ways we might use it.

For example, given the word 'Paris', we have many contexts or uses we may find it in:

```
['_ is the capital of', '_, France', 'the capital city _', 'the restaurant in _',]
```

and a bunch of contexts we _don't_ expect to find it:

```
['can I have a _', 'there's too much _ on this' ... and millions more]
````

We could make a "feature" or column for each of these contexts. So we could *represent* the word 'Paris' as 1-hot vector of all possible contexts it appears in. This would be very sparse. Of all the millions of ways we might use a word, we will only use 'Paris' in a very, very small number of them.

Additionally, the first few represent the *same* concept (or multiple concepts):

1. Paris is a city like thing, so it contains shops and restaurants
1. Paris is a capital city

What we want to do is apply **dimensionality reduction** to find a few concepts per word (instead of looking for _all_ of the possible contexts).

In **LDA**, we could do this by identifying the topics a word was most likely to come from.

In **word2vec**, we will traditionally replace the overlapping contexts by some concept that represents both of them.

Like other dimensionality reduction techniques, our goal is to identify correlated columns and replace them with a new column that represents the columns we replaced.

For example, we can replace columns ['_ is a city', '_ is a capital', 'I flew into _ today'] with a single column - 'IsACity' column.


`word2vec` was originally presented as a deep learning model, but is more closely related to standard dimensionality reduction techniques. A common feature of `word2vec` is being able to ask which words are similar to each other? If we have data on multiple languages, a system like word2vec could also be used for translation.

![Word2Vec translation](./assets/images/word2vec-translation.png)

> **Check:** After reviewing the anologies, brainstorm some word vector math. For example, consider the prototypical example of 'King' - 'Man' = 'Queen'


<a name="demo-word2vec"></a>
## Demo: Word2Vec in `gensim` (20 min)

`word2vec` is also available in `gensim`.

We will build a `word2vec` model using the body text of the articles available in the StumbleUpon dataset.

```python
# Setup the body text
text = data.body.dropna().map(lambda x: x.split())

from gensim.models import Word2Vec
model = Word2Vec(text, size=100, window=5, min_count=5, workers=4)
```
Here:
- `size` represents how many concepts or topics we should use
- `window` represents how many words surrounding a sentence we should use as our original features
- `min_count` is the number of times that context or word must appear
- `workers` is the number of CPU cores to use to speed up model training

The model has a `most_similar` function that helps find the words most similar to the one you queried. This will return words that are often used in the same context.

```python
model.most_similar(positive=['cookie', 'brownie'])
```

It can easily identify words related to those from this dataset (remember, most of the articles in this dataset are food or cooking related).


<a name="independent-practice"></a>
## Independent Practice (45 min)

In this exercise, we will compare some of the classical NLP tools from the last class with these more modern latent variable techniques. We will do this by comparing information extraction techniques on Twitter using the two methods.

> Instructor Note: If you want students to capture their own collection of tweets using the Twitter API,[ use the following instructions](./code/twitter-instructions.md). It requires some setup and a Twitter account.

> If not - you can use a [pre-existing file of captured tweets](./assets/dataset/captured-tweets.txt) relating tech companies and Middle Eastern companies.

**Bonus**: Want to collect your own tweets? Here are some instructions. We'll use the Twitter API to build a collection of tweets to learn from. After that, we'll filter future tweets based on some established conditions.

To collect tweets, we run the following code. Each tweet comes in as a Python dictionary, which contains many fields of metadata. The one we are most interested in is `text` which has the actual text of the tweet.

The `retrieve_tweets` function takes a topic, to limit the tweets we receive to that topic.

```python
import twitter

tweets = twitter.retrieve_tweets(topic = 'google')

num_tweets_to_collect = 2000
tweets_text = []

n = 0
for tweet in tweets:
   tweet_text = tweet['text']
   tweets_text.append(tweet_text)

    n = n + 1

    if n == num_tweets_to_collect:
       break
```

You can collect your own tweets, or use [the existing collection found here](./assets/dataset/captured-tweets.txt).

#### Loading the data

```python
tweets = [tweet for tweet in open('../../assets/dataset/captured-tweets.txt', 'r')]
```

#### Setting up spacy

```python
from spacy.en import English
nlp_toolkit = English()
```

Now we'd like to do a few things:

1. Use `spacy` to write a function to filter tweets down to those where Google is announcing a product. How might we do this? One way might be to identify verbs, where 'Google' is the noun and there is some action like 'announcing'

    a. Write a function that can take a sentence parsed by `spacy` and identify if it mentions a company named 'Google'. Remember, `spacy` can find entities and code them as `ORG` if they are a company.

        i. **BONUS**: Make this function work for any company

    b. Write a function that can take a sentence parsed by `spacy` and return the verbs of the sentence (preferably lemmatized)

    c. For each tweet, parse it using `spacy` and print it out if the tweet has 'release' or 'announce' as a verb.

    d. Write a function that identifies countries. HINT: the entity label for countries is GPE (or "GeoPolitical Entity")

    e. Re-run (d) to find country tweets that discuss 'Iran' announcing or releasing.

2. Build a `word2vec` model of the tweets we have collected using `gensim`

    a. First take the collection of tweets and tokenize them using `spacy`

        i. Think about how this should be done. Should you only use upper-case or lower-case? Should you remove punctuations or symbols?

    b. Build a `word2vec` model

        i. Test the window size as well - this is how many surrounding words need to be used to model a word. What do you think is appropriate for Twitter?

    c. Test your word2vec model with a few similarity functions.

        i. Find words similar to 'Syria'

        ii. Find words similar to 'war'

        iii. Find words similar to "Iran"

        iv. Find words similar to 'Verizon'

    d. Adjust the choices in (b) and (c) as necessary

3. Filter tweets to those that mention 'Iran' or similar entities and 'war' or similar entities.

    a. Do this using just `spacy`

    b. Do this using `word2vec` similarity scores


<a name="conclusion"></a>
## Conclusion (10 mins)

Concept Review:

- Latent variable models attempt to uncover structure from text.
- Dimensionality reduction is focused on replacing correlated columns.
- Topic modeling (or LDA) uncovers the topics that are most common to each document and then the words most common to those topics.
- Word2Vec builds a representation of a word from the way it was used originally.
- Both techniques avoid learning grammar rules and instead rely on large datasets. They learn based on how the words are used, making them very flexible.

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **DUE TODAY**  | [Final Project, Deliverable 2](../../projects/final-projects/02-experiment-writeup/readme.md) |
| **UPCOMING PROJECTS**  | [Final Project, Deliverable 3](../../projects/final-projects/03-exploratory-analysis/readme.md) |

### ADDITIONAL RESOURCES
- [Five Takeaways on the State of Natural Language Processing](http://www.wise.io/tech/five-takeaways-on-the-state-of-natural-language-processing)

#### LDA (Latent Dirichlet Allocation)
- [Introduction to LDA](http://blog.echen.me/2011/08/22/introduction-to-latent-dirichlet-allocation/)
- [Gensim LDA documentation](https://radimrehurek.com/gensim/models/lda.html)

#### Word2Vec
- [Gensim Word2Vec documentation](https://radimrehurek.com/gensim/models/word2vec.html)
- [How Google Converted Language Translation Into a Problem of Vector Space Mathematics](http://www.technologyreview.com/view/519581/how-google-converted-language-translation-into-a-problem-of-vector-space-mathematics/)
- [A word is worth a thousand vectors](http://multithreaded.stitchfix.com/blog/2015/03/11/word-is-worth-a-thousand-vectors/)
- [Word Embeddings For Fashion](http://developers.lyst.com/2014/11/11/word-embeddings-for-fashion/)
- [Building the Next New York Times Recommendation Engine](http://open.blogs.nytimes.com/2015/08/11/building-the-next-new-york-times-recommendation-engine/?_r=0)
