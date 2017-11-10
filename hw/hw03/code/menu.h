/*
 * menu.h
 *
 * This file contains the prototypes for the functions used to provide high
 * level interfaces to the data structures in the project.
 *
 * */

#ifndef MENU_H
#define MENU_H

#include "database.h"

// ------------------ FUNCTION PROTOTYPES ------------------

int display_menu();

char *get_letter_grade(float);

void print_db(database_t *);

float calculate_grade(list_of_grades_t *);

void search_name(database_t *);

void search_by_grade(database_t *);

void add_data(database_t *);

void remove_data(database_t *);

void close_db(database_t *);

void remove_cr(char *);

int init_db(database_t *, char *);


#endif // MENU_H
