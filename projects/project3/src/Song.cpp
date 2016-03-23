/* Song serialization and deserialization utilities */

#include "Song.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#define KEY_NAME_CHARS 64
#define VALUE_CHARS 256
#define KEY_DELIMITER ' '

/* Read an arbitrary value from the input stream */
static void readValue(std::istream &stream, 
                      const char *keyName, 
                      char *value,
                      unsigned long valueChars);

/* Read a string from the input stream */
static std::string readStringValue(std::istream &stream, const char *keyName);

/* Read an unsigned long from the input stream */
static unsigned long readULongValue(std::istream &stream, const char *keyName);

std::ostream &operator<<(std::ostream &stream, const Song &song)
{
    stream << "<Title: " << song.title.c_str() << ", "
           << "Artist: " << song.artist.c_str() << ", "
           << "Album: " << song.album.c_str() << ", "
           << "Genre: " << song.genre.c_str() << ", "
           << "Year: " << song.year << ">";

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Song *song)
{
    stream << "<Title: " << song->title.c_str() << ", "
           << "Artist: " << song->artist.c_str() << ", "
           << "Album: " << song->album.c_str() << ", "
           << "Genre: " << song->genre.c_str() << ", "
           << "Year: " << song->year << ">";

    return stream;
}

std::istream &operator>>(std::istream &stream, Song &song)
{
    song.title = readStringValue(stream, "Title:");
    song.artist = readStringValue(stream, "Artist:");
    song.album = readStringValue(stream, "Album:");
    song.genre = readStringValue(stream, "Genre:");
    song.year = readULongValue(stream, "Year:");

    return stream;
}

static std::string readStringValue(std::istream &stream, const char *keyName)
{
    char value[VALUE_CHARS];
    std::memset(value, '\0', sizeof(value));

    readValue(stream, keyName, value, sizeof(value));

    return std::string(value);
}

static unsigned long readULongValue(std::istream &stream, const char *keyName)
{
    char value[VALUE_CHARS];
    std::memset(value, '\0', sizeof(value));

    readValue(stream, keyName, value, sizeof(value));

    return static_cast<unsigned long>(std::atol(value));
}

static void readValue(std::istream &stream, 
                      const char *keyName, 
                      char *value,
                      unsigned long valueChars)
{
    std::string err("Unexpected field: ");
    char key[KEY_NAME_CHARS];

    if (keyName == NULL)
    {
        throw std::invalid_argument("keyName cannot be NULL");
    }

    if (value == NULL)
    {
        throw std::invalid_argument("value cannot be NULL");
    }

    std::memset(key, '\0', sizeof(key));

    /* Ensure we're reading the expected key */
    stream.get(key, sizeof(key), KEY_DELIMITER);
    if (strncmp(key, keyName, strlen(keyName)) != 0)
    {
        throw std::runtime_error(err + key);
    }

    /* Read past the delimiter */
    stream.get();

    /* Get the value */
    stream.getline(value, valueChars);
}

