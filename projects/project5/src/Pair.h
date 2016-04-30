#ifndef PAIR_H
#define PAIR_H

#include <string>

class Pair {

public:

    Pair(std::string city, std::string coords) :
            m_city(city), m_coords(coords) { }

    std::string GetCity() { return m_city; }

    std::string GetCoords() { return m_coords; }


private:

    std::string m_city;
    std::string m_coords;

};


#endif