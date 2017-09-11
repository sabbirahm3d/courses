## Instructions for capturing tweets


### Setting up Twitter API credentials

1. Go to https://apps.twitter.com/
2. Sign In, and then follow the instructions below:
3. Press "Create New App"
4. Fill in form (you can enter your website or any website in the 'website' field i.e. http://google.com)
5. Press 'Create application'
6. Press 'Manage keys ...'
1. Press 'Create access tokens'
8. Find and save four values
    - Consumer Key
    - Consumer Secret
    - Access Token Key
    - Access Token Secret

### Running the code

1. Install TwitterAPI: `pip install TwitterAPI`
2. Substitute the four values saved from 'Setting up Twitter API credentials' in `twitter.py` in

```python
access_token_key = "<ENTER ACCESS TOKEN KEY>"
access_token_secret = "<ENTER ACCESS TOKEN SECRET>"

api_key = "<ENTER CONSUMER KEY>"
api_secret = "<ENTER CONSUMER SECRET>"

```

3. Run `python capture-tweets.py <topic>` to save tweets to file called `captured-tweets.txt` related to `<topic>`. I.e.: `python capture-tweets.py Google` or `python capture-tweets.py Iran`