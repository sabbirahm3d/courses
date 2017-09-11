from TwitterAPI import TwitterAPI

access_token_key = "<ENTER ACCESS TOKEN KEY>"
access_token_secret = "<ENTER ACCESS TOKEN SECRET>"

api_key = "<ENTER CONSUMER KEY>"
api_secret = "<ENTER CONSUMER SECRET>"

_debug = 0


api = TwitterAPI(api_key, api_secret, access_token_key, access_token_secret)

'''
Construct, sign, and open a twitter request
using the hard-coded credentials above.
'''

def retrieve_tweets(topic, 
                    url="https://stream.twitter.com/1/statuses/filter.json", 
                    method="GET", ):
    """

    Params:
    topic - must be in this format "#topic" or '@handle"
    Returns
    """
    response = api.request('statuses/filter', {'track': topic})
    if response.status_code != 200:
        raise ValueError("Unable to retrieve tweets, please check your API credentials")
    for x in response:
        try:
            yield x
        except UnicodeError as unicode_error:
            continue
