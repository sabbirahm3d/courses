#include "BackupHash.h"

big_int BackupHash::Hash(std::string city, int size) {

    big_int c = RandomInt(1, PRIME2);
    int sum = 0;

    for (unsigned int i = 0; i < city.size(); ++i) {
        sum += (int) (c * sum + city[i]) % PRIME2;
    }

    return (big_int) sum % size;

}


big_int BackupHash::RandomInt(int lower, big_int upper) {

    srand(0);
    return rand() % upper + lower;

}


big_int BackupHash::HashFunc(int value, int size) {

    big_int a = RandomInt(1, PRIME1);
    big_int b = RandomInt(0, PRIME1 - 1);
//    std::cout << a << " " << b << std::endl;

    return ((big_int) (a * value + b) % PRIME1) % size;

}
