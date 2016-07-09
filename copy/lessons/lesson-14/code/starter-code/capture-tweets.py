from __future__ import print_function
import sys

import twitter

if __name__ == '__main__':
    results = twitter.retrieve_tweets(topic=sys.args[1])
    out = open('captured-tweets.txt', 'ab')
    # The tweet is stored with key 'text',
    i = 0
    for result in results:
        # Filter to english tweets
        if result['lang'] == 'en':
            out.write((result['text'] + "\n").encode('utf-8'))
            i += 1
        # Defaulting to capturing 5000, this takes a long time...
        if i == 5000:
            exit()