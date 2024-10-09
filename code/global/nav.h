#include <stdbool.h>

#ifndef NAV_H
#define NAV_H

int choice_input(const char *type, void *choice);
void nav_input();
void nav_help();
void check_action(int value);
void print_nav();

#endif

