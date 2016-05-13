/* File:    Pair.h
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Declaration and implementation of the Pair structure. This class holds the
 * city names paired with the coordinates provided by the input file.
 */

#ifndef PAIR_H
#define PAIR_H

#include <string>
#include <iostream>

struct Pair {

    /* ******************** Constructors ******************** */

    /* Pair() - Overloaded constructor
     * Holds the city name and its corresponding location */

    Pair(std::string city, std::string coords) :
            m_city(city), m_coords(coords) { }


    /* ******************** Overloaded operator ******************** */

    /* operator<< - Overloaded output
     * Dumps content of the mapped pair */

    friend std::ostream &operator<<(std::ostream &out, const Pair *pair) {

        out << pair->m_city << " -> (" << pair->m_coords << ")" << std::endl;

        return out;

    }

    /* ******************** Member attributes ******************** */
    std::string m_city, m_coords;

};


#endif