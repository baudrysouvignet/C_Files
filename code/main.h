#include <stdbool.h>

#ifndef MAIN_H
#define MAIN_H

int choice_input(const char *str, void *choice);
const char * get_separator();
const char * get_pwd();
void clean_buffer();
bool file_exists(const char *path);

#endif
