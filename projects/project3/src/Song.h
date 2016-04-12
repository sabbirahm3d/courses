/* File:    Song.h
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Song structure declaration. Stores metadata relevant to songs.
 * Songs may be serialized and deserialized.
 */


#ifndef SONG_H
#define SONG_H

#include <string>
#include <istream>
#include <ostream>


struct Song {

    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    unsigned long year;

    /* Insert the given song into the specified output stream */
    friend std::ostream &operator<<(std::ostream &stream, const Song &song);

    /* Insert the given song into the specified output stream */
    friend std::ostream &operator<<(std::ostream &stream, const Song *song);

    /* Deserialize a song from the given input stream */
    friend std::istream &operator>>(std::istream &stream, Song &song);

};


#endif