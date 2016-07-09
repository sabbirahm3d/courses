---
title: Natural Language Processing (NLP) and Text Classification
duration: "3:00"
creator:
    name: Arun Ahuja
    city: NYC
---

# ![](https://ga-dash.s3.amazonaws.com/production/assets/logo-9f88ae6c9c3871690e33280fcf557f33.png) Natural Language Processing and Text Classification
DS | Lesson 13 | [Slides](./assets/slides/slides-13.md)

### LEARNING OBJECTIVES
*After this lesson, you will be able to:*

- Define natural language processing
- List common tasks associated with:
  - use-cases
  - tokenization
  - tagging
  - parsing
- Demonstrate how to classify text or documents using `scikit-learn`

### STUDENT PRE-WORK
*Before this lesson, you should already be able to:*

- Experience with sckit-learn classifiers, specifically Random Forests and Decision trees
- Install `spacy` with `pip install spacy` (or use Anaconda)
- Run the `spacy` download data command

  ```python
  python -m spacy.en.download --force all
  ```

### INSTRUCTOR PREP
*Before this lesson, instructors will need to:*

- Remind students about [Final Project, pt. 2](../../projects/final-projects/02-experiment-writeup/readme.md)
- Copy and modify the [lesson slide deck](./assets/slides/slides-13.md)
- Read through datasets and starter/solution code
- Add to the "Additional Resources" section for this lesson
- Install `spacy` with `pip install spacy` (or use Anaconda)
- Run the `spacy` download data command

  ```python
  python -m spacy.en.download --force all
  ```

### LESSON GUIDE
| TIMING  | TYPE  | TOPIC  |
|:-:|---|---|
| 10 min  | [Opening](#opening)  | Decision Trees and Random Forests |
| 30 mins  | [Introduction](#introduction-nlp)   | Natural Language Processing (NLP)  |
| 30 mins  | [Demo](#demo-spacy)  | NLP with spacy in Python  |
| 30 mins  | [Introduction](#introduction-classification)   | Text Classification  |
| 30 mins  | [Demo](#demo-text-sklearn)  | Text Classification with scikit-learn |
| 30 mins  | [Independent Practice](#ind-practice)  | Text Classification with scikit-learn  |
| 10 mins  | [Conclusion](#conclusion)  |   |

---

<a name="opening"></a>
## Review: Decision Trees and Random Forests  (10 mins)
Recall definitions of Decision Trees and Random Forests from previous lesson.

**Check:** What are some important features of decision trees and random forests?

  - Decision trees are weak learners that are easy to overfit
  - Random forests are strong models that made up a collection of decision trees
    - They are non-linear (while logistic regression is linear)
    - They are mostly black-boxes (no coefficients, but we do have a measure of feature importance)
    - They can be used for classification or regression

<a name="introduction-nlp"></a>
## Introduction: Natural Language Processing (30 mins)

### What is Natural Language Processing? (NLP)

Natural language processing is the task of extracting meaning and information from text documents. There are many types of information we might want to extract; these include simple classification tasks, such as deciding what category a piece of text falls into or what tone it has, as well as more complex tasks like translating or summarizing text.

Most AI assistant systems are typically powered by fairly advanced NLP engines. A system like Siri uses voice-to-transcription to record a command and then various NLP algorithms to identify the question asked and possible answers.

For any of these tasks, from classification to translation, a fair amount pre-processing is required to make the text digestible for our algorithms. Typically we need to add some structure to the text (unstructured data) before we can make decisions based on it.


### Tokenization

Tokenization is the task of separating a sentence into it's constituent parts, or **tokens**. How do we know what the "words" are in a particular sentence? While this may seem easy (for example, we can separate words using spaces or pauses) it becomes more complex when we consider unusual punctuation (common in social media) or different language conventions.

For example, can you spot any potential difficulties with this sentence?
_The L.A. Lakers won the NBA championship in 2010, defeating the Boston Celtics._


To perform a proper analysis, we need to be able to identify that:

- The periods in _L.A._ don't mark the end of a sentence but an abbreviation.
- _L.A. Lakers_ and _Boston Celtics_ are one concept.
- _"2010"_ is the word used, not _"2010,"_


### Lemmatization and Stemming

Abbreviations, proper nouns, and dates can pose a problem, but there are many other language features that also have to be broken down. Consider the terms 'bad' and 'badly' or 'different' and 'differences'. How can we describe the relationships between these terms?

Stemming and lemmatization are two solutions to this type of problem. Once we've identified the **tokens** of our sample text, we can use these tools to identify common roots.

**Stemming** is a crude process of removing common endings from sentences:

- Stemming removes endings with `s`, `es`, `ly`, `ing`, and `ed`.

This is useful so that we can treat the word `happy` and `happily` similarly.

There are many well-known stemmer functions that can import many of these common endings, most notably the [Porter stemmer](http://tartarus.org/martin/PorterStemmer/).

**Lemmatization** is a more refined version that attempts to accomplish the same goal as stemming, but does so by using specific language and grammar rules. A lemmatizer relies on a large collection of pre-defined grammar rules to perform this type of task.

For example, we can identify that "bad" and "badly" are similar using stemming.  However, this heuristic won't be able to tell that "better" and "best" are similar. That's where lemmatization comes in handy.

**Check:** Can you think of other problem words or phrases that might require these tools?

### Parsing and Tagging

Another classic NLP problem involves _parsing_ text and _tagging_. In order to understand the various elements of a sentence, we need to **tag** important topics and **parse** their dependencies. Our goal is to successfully identify the actors and actions in the text in order to make informed decisions.

For example if we are processing financial news, we might need to identify which companies are involved and any actions they are taking. We would then be able to create an alert when a specific company releases a new product.  

Alternatively, if we are writing an assistant application, we might need to identify specific command phrases in order to determine what is being asked. For instance, given the phrase: 'Siri, what time is my next appointment?' what needs to be tagged and what needs to be parsed?

Tagging and parsing is in fact made up of a few overlapping sub-problems:

  - "Parts of speech" tagging:
    - What are the parts of speech in a sentence? Which is the noun, verb, adjective, etc?
  - Chunking:
    - Can we identify the pieces of the sentence that go together in meaningful chunks? For instance, noun or verb phrases?
  - Named entity recognition:
    - Can we identify *specific* proper nouns? Can we pick out people and locations?

As you can see, NLP requires a large number of overlapping rules and dictionaries; however, the potential benefits are enormous.

**Check:** How might NLP be applied within your current jobs or final projects? What are some potential use-cases?

***

<a name="demo-spacy"></a>
## Demo / Codealong: Natural Language Processing with 'spacy' (30 mins)

Most techniques for NLP involve pre-processing large collections of annotated text in order to learn specific language rules. There are many of these systems in-use for English and other popular languages, although some languages tend to have fewer tools available. Each tool typically requires a large amount of data in order to learn general rules and patterns for its task. Many also require large databases of special use-cases, since languages like English are full of inconsistencies and slang.

Two popular NLP toolkits in Python are `nltk` and `spacy`. `nltk` is the most popular, but it hasn't kept up with advances and isn't very well maintained. `spacy` is more modern, but isn't available for commercial-use.

We'll be using `spacy` in this class, although `nltk` has a similar interface and functionality. Most of the utilities and individual tasks we'll be performing also have their own specialized tools available as well.

Let's start by attempting to process some of the titles.

First, we'll load our NLP toolkit by specifying the language:

  ```python
  from spacy.en import English

  nlp_toolkit = English()
  ```

  This toolkit has 3 pre-processing engines:

    - a tokenizer: to identify the word tokens
    - a tagger: to identify the concepts described by the words
    - a parser: to identify the phrases and links between the different words

Each of these pre-processing tasks can be overridden with a specific tool you have (you may want a specialized tokenizer that looks for stock quotes or Instagram posts instead of news headlines). You could also write your own tokenizer or tagger for those tasks and use them in place of the default ones `spacy` provides. For now, we'll use the defaults.

The first title is:

- [_IBM Sees Holographic Calls, Air Breathing Batteries_](http://www.bloomberg.com/news/articles/2010-12-23/ibm-predicts-holographic-calls-air-breathing-batteries-by-2015)

 From this we may wish to extract that the article references a company and that the company is referencing a new possible product: air-breathing batteries.

 ```python

 title = "IBM sees holographic calls, air breathing batteries"
 parsed = nlp_toolkit(title)

 for (i, word) in enumerate(parsed):
    print("Word: {}".format(word))
    print("\t Phrase type: {}".format(word.dep_))
    print("\t Is the word a known entity type? {}".format(word.ent_type_  if word.ent_type_ else "No"))
    print("\t Lemma: {}".format(word.lemma_))
    print("\t Parent of this word: {}".format(word.head.lemma_))
```

The `nlp_toolkit` here runs each of the individual pre-processing tools: first it tokenizes the sentence, then it identifies the components, and finally it builds an interpretation of the sentence.

Output:

```
Word: IBM
   Phrase type: nsubj
   Is the word a known entity type? ORG
   Lemma: ibm
   Parent of this word: see
Word: sees
   Phrase type: ROOT
   Is the word a known entity type? No
   Lemma: see
   Parent of this word: see
Word: holographic
   Phrase type: amod
   Is the word a known entity type? No
   Lemma: holographic
   Parent of this word: call
Word: calls
   Phrase type: dobj
   Is the word a known entity type? No
   Lemma: call
   Parent of this word: see
Word: ,
   Phrase type: punct
   Is the word a known entity type? No
   Lemma: ,
   Parent of this word: call
Word: air
   Phrase type: compound
   Is the word a known entity type? No
   Lemma: air
   Parent of this word: breathing
Word: breathing
   Phrase type: compound
   Is the word a known entity type? No
   Lemma: breathing
   Parent of this word: battery
Word: batteries
   Phrase type: conj
   Is the word a known entity type? No
   Lemma: battery
   Parent of this word: call
```

In this output:

- "IBM" is identified as an organization (ORG).
- We identify a phrase 'holographic calls'
- We identify a compound noun phrase at the end - 'air breathing batteries'.
- We can that 'see' is at a root as it is the action 'IBM' is taking.
- Additionally, we can see that 'batteries' was lemmatized to 'battery'.

We can also use this to find all titles that discuss an organization.

```python
def references_organization(title):
  parsed = nlp(title)
  return any([word.ent_type_ == 'ORG' for word in parsed])

data['references_organization'] = data['title'].fillna('').map(references_organization)

data[data['references_organization']][['title']].head()
```

**Check:** Write a function to identify titles that have mention an organization (ORG) and person (PERSON).

Solution:

```python
def references_organization_and_person(title):
    parsed = nlp(title)
    has_org = any([word.ent_type_ == 'ORG' for word in parsed])
    has_person = any([word.ent_type_ == 'PERSON' for word in parsed])
    return has_org and has_person

data['references_organization_and_person'] = data['title'].fillna('').map(references_organization_and_person)  
data[data['references_organization_and_person']][['title']].head()
```

### Common Problems in NLP

It's important to keep in mind that each of these subtasks are still very difficult because of the complexity of language. Most often we are looking for heuristics to search through large amounts of text data. There is still a lot of active research being done in each of these areas.

In the last few years, there has been less focus on the rule-based systems seen here. Instead, researchers are looking for more flexible approaches. While older techniques first attempt to uncover the rules of the language and then use those rules to understand text, modern approaches do not attempt to _parse_ or understand the structure of a sentence first. Instead, they just rely on which words are being used. We'll see an example of these modern approaches in the next class.

***

<a name="introduction-classification"></a>
## Introduction: Text Classification (30 mins)

Text classification is the task of predicting what category or topic a piece of text is from. For example, we may want to identify whether an article is a sports or a business story.  We may also want to identify whether an article is positive or negative in sentiment.

Typically this is done by using the text as the features input for the model, and - as in previous classifications - using the label (sports or business, positive or negative) as the target output for it to train on.

When we want to include the text as features, we usually create a _binary_ feature for each word. Then each feature boils down to: "does this piece of text contain that word?"

To do this, we must first create a vocabulary, in order to account for all the possible words in our universe. We will do this in a data-driven way, which usually means taking in all of the words that appear in our corpus. We'll then filter them based on occurrence or usefulness.

In doing so, we'll have many encoding or representation questions along the way, such as:

  - Does the order of words matter?
  - Does punctuation matter?
  - Upper or lower case? Should we treat 'Python' as different from 'python'?

The answer to each of these is problem dependent, but all of them will affect our modeling problem.

**Check:** What do you think? Does word order matter? Case? Punctuation? Discuss and explain your reasoning.

Solution:

- [ ] Yes, order of words may matter.
  - This is especially true when trying to predict positive or negative sentiment.
- [ ] Yes, punctuation may matter.
  - In sentiment prediction, saying "amazing!!!" may result in a different tone than "amazing."
- [ ] Yes, letter case may matter.
  - Upper-case words or phrases are usually proper nouns. For instance, "Python" is more likely to refer to a programming language, while "python" may refer to either the programming language or a type of snake.


Note: Classification using words from the text as features is known as **bag-of-words** classification.

**Check:** What is "bag-of-words" classification stand for and when should it be used? What are some benefits to this approach?

***

<a name="demo-text-sklearn"></a>
## Demo / Codealong: Text Processing in scikit-learn (30 mins)

> Instructor Note: Have students open and walk through the [starter code](./code/starter-code/starter-code-13.ipynb) notebook here.

Scikit-learn has many pre-processing utilities that simplify many of the tasks required to convert text into features for a model. These can be found in the `sklearn.preprocesing.text` package.

We will use the StumbleUpon web crawl dataset again and perform a text classification text. Instead of using other features of the webpages, we will use the text content itself to predict whether or not the webpage is 'evergreen'.


#### CountVectorizer

There are built-in utilities to pull out features from text in `scikit-learn` - most importantly, `CountVectorizer`. It converts a collection of text into a matrix of features. Each row will be a sample (an article or piece of text) and each column will be a text feature (usually a count or binary feature per word).

`CountVectorizer` takes a column of text and creates a new dataset - one row per piece of text (i.e. one row per title) and generates a feature for **every** word in the all of the titles.

**REMEMBER**: Using all of the words can be very useful, but we also need to remember to use regularization to avoid overfitting. Otherwise, using rare words may result in the model learning something that isn't generalizable.

For example, if we are attempting to predict sentiment and see an article that has the word "bessst!", we may link this word to positive sentiment. However, very few articles may ever use this word, so it isn't actually very useful for our model.

```python
from sklearn.feature_extraction.text import CountVectorizer

vectorizer = CountVectorizer(max_features = 1000,
                             ngram_range=(1, 2),
                             stop_words='english',
                             binary=True)
```


`CountVectorizer` arguments:

- `ngram_range` - a range of of length of phrases to use
    - `(1,1)` means use all single words
    - `(1,2)` all contiguous pairs of words
    - `(1,3)` all triples etc.
- `stop_words='english'`
    - Stop words are non-content words (e.g. 'to', 'the', 'it', 'at'). They aren't helpful for prediction (most of the time) so this parameter removes them.
- `max_features=1000`
    - Maximum number of words to consider (uses the first N as most frequent)
- `binary=True`
    - To use a dummy column as the entry (1 or 0, as opposed to the count). This is useful if you think a word appearing 10 times is not more important than whether the word appears at all.

Like models or estimators in `scikit-learn`, vectorizers follow a similar interface:  

  - We create a vectorizer object with the parameters of our feature space.
  - We `fit` a vectorizer to learn the vocabulary
  - We `transform` a set of text into that feature space.

There is a distinction between `fit` and `transform` when it comes to splitting datasets into 'training' and 'test' sets. We want to fit (i.e. learn our vocabulary) from our training set. Since choosing features is a part of our model building process, we **should not** look at our test set to do this.

Whenever we want to make predictions, we will need to create a new data point that contains **exactly** the same columns as our model. If feature 234 in our model represents the word 'cheeseburger', then we need to make sure our test or future example also has 'cheeseburger' as feature 234. We can use `transform` to perform this conversion on the test set (and any future dataset) in the same way.

```python

titles = data['title'].fillna('')

from sklearn.feature_extraction.text import CountVectorizer

vectorizer = CountVectorizer(max_features = 1000,
                             ngram_range=(1, 2),
                             stop_words='english',
                             binary=True)

- Use `fit` to learn the vocabulary of the titles
vectorizer.fit(titles)

- Use `tranform` to generate the sample X word matrix - one column per feature (word or n-grams)
X = vectorizer.transform(titles)
```

#### Random Forest Prediction Model
Build a random forest model to predict the "evergreeness" of a website using the title features

```python
from sklearn.ensemble import RandomForestClassifier

model = RandomForestClassifier(n_estimators = 20)

- Use `fit` to learn the vocabulary of the titles
vectorizer.fit(titles)

- Use `transform` to generate the sample X word matrix - one column per feature (word or n-grams)
X = vectorizer.transform(titles)
y = data['label']

from sklearn.cross_validation import cross_val_score

scores = cross_val_score(model, X, y, scoring='roc_auc')
print('CV AUC {}, Average AUC {}'.format(scores, scores.mean()))
```

#### Term Frequency - Inverse Document Frequency (TF-IDF)

An alternative representation of the _bag-of-words_ approach from `CountVectorizer` is a TF-IDF representation. TF-IDF stands for **Term Frequency - Inverse Document Frequency**.

As opposed to using the count of words as features, TF-IDF uses the product of two intermediate values, the _Term Frequency_ and the _Inverse Document Frequency_.

The Term Frequency is equivalent to `CountVectorizer` features, or the number of times (i.e. 'count') that a word appears in the document. This is our most basic representation of text.

To define Inverse Document Frequency, first let's define Document Frequency. **Document Frequency** is the % of documents that a particular word appears in. For example, you could assume `the` appears in 100% of documents, while words like `Syria` would have relatively low document frequency.  

**Inverse Document Frequency** is simply `1 / Document Frequency` (although sometimes this is altered to `log(1 / Document Frequency)`).

Looking at our final term:
  Term Frequency * Inverse Document Frequency = Term Frequency / Document Frequency.  

The intuition behind a TF-IDF representation is that words that have high weight are those that either appear frequently in this document or appear rarely in other documents (therefore unique to this document).

This is a good alternative to using a static set of stop-words.

```python
from sklearn.feature_extraction.text import TfidfVectorizer
vectorizer = TfidfVectorizer()
```

`TfidfVectorizer` follows the same `fit` and `fit_transform` interface of `CountVectorizer`.

**Check:** What does TF-IDF stand for? What does this function do and why is it useful?

**Check:** Use `TfidfVectorizer` to create a feature representation of the stumbleupon titles.

> Instructor Note: You can find the solutions in the [solution code notebook](./code/solution-code/solution-code-13.ipynb).

***

<a name="ind-practice"></a>
## Independent Practice: Text Classification in scikit-learn (30 mins)

Tie together the text features of the title with one more feature sets from the previous random forest model. Train this model to see if this improves the AUC.
- Use the `body` text instead of the `title` text - is this an improvement?
- Use `TfIdfVectorizer` instead of `CountVectorizer` - is this an improvement?

**Check:** Were you able to prepare a model that uses both quantitative features and text features? Does this model improve the AUC?

***

<a name="conclusion"></a>
## Conclusion (5 mins)

Let's review:

- Natural language processing is the task of pulling meaning and information from text
- This typically involves solving many subproblems, including: tokenizing, cleaning (stemming and lemmatization) and parsing.
- After we have structured our text, we can identified features for other tasks, including: classification, summarization, and translation.
- In `scikit-learn` we use vectorizers to create text features for classification, such as `CountVectorizer` or `TfIdfVectorizer`

***

### BEFORE NEXT CLASS
|   |   |
|---|---|
| **UPCOMING PROJECTS**  | [Final Project, Part 2](../../projects/final-projects/02-experiment-writeup/readme.md) |

### ADDITIONAL RESOURCES
- [Natural Language Understanding: Foundations and State of the Art](icml.cc/2015/tutorials/icml2015-nlu-tutorial.pdf)
- [Text Mining Online](http://textminingonline.com/)
