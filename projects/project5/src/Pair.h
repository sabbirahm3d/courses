#ifndef PAIR_H
#define PAIR_H

#include <string>

class Pair {

public:

    Pair(std::string city, int coords) {
        this->city = city;
        this->coords = coords;
    }

    std::string getCity() {
        return city;
    }

    int getCoords() {
        return coords;
    }


private:

    std::string city;
    int coords;

};


#endif