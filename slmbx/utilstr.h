//
// Created by sabbir on 3/22/18.
//

#ifndef UTILSTR_H
#define UTILSTR_H


unsigned char *u_strcpy(unsigned char *dest, const unsigned char *src) {

    unsigned char *ret = dest;
    while ((*dest++ = *src++));
    return ret;

}

unsigned int u_strlen(const unsigned char *str) {

    unsigned int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return ++i;

}


#endif // UTILSTR_H
