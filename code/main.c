#include <stdio.h>


#include "files/files.h"
#include "global/nav.h"

#include <unistd.h>

#define RED "\033[31m"
#define RESET "\033[0m"

void clean_buffer();
const char * get_pwd();
const char * get_separator();

void clean_buffer() {
    while (getchar() != '\n');
}

int main() {
    printf("Vous etes dans le dossier%s\n", get_pwd());
    printf("0- Quitter 99- Navigation\n");
    nav_input();
}

const char * get_separator() {
    const char *separator = "/";
#ifdef _WIN32
    separator = "\\";
#endif
    return separator;
}

const char *get_pwd() {
    static char pwd[1024]; // Déclaration d'un tableau statique
    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        return pwd;
    } else {
        printf(RED "Erreur récupération du dossier courant\n" RESET);
        return NULL;
    }
}

bool file_exists(const char *path) {
    FILE * fichier = fopen(path, "r+");
    if (fichier == NULL){
        return false;
    }else{
        fclose(fichier);
        return true;
    }
}