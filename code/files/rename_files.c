#include "files.h"

#include "../main.h"
#include "../global/nav.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void rename_file();

void nav_rename_files() {
    const char * cwd = get_pwd();
    printf("Voulez vous modifier le nom d'un fichier dans le répertoire (o/n): %s\n", cwd);
    char reponse;
    choice_input(" %c", &reponse);
    if (reponse == 'o') {
        rename_file();
    } else {
        printf("0- Quitter 99- Navigation\n");
        nav_input();
    }
}


char* input_rename_file() {
    char filename[1024] = {0};
    char* fullPath = (char*)malloc(2048 * sizeof(char));
    choice_input(" %s", filename);

    if (fullPath == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    snprintf(fullPath, 2048, "%s%s%s", get_pwd(), get_separator(), filename);
    return fullPath;
}

char* input_old_file_create_files() {
    char* fullPath= input_rename_file();
    bool exist = file_exists(fullPath);
    if (exist) {
        return fullPath;
    }
    printf("Le fichier %s n'existe pas, entrée une donnée valide !\n", fullPath);
    return input_rename_file();
}

void rename_file() {
    printf("Choisissez le nom du fichier à modifier (exemple: text.txt): ");
    char* old_name= input_old_file_create_files();

    printf("Choisissez le nouveau nom du fichier (exemple: text.txt): ");
    char* new_name = input_rename_file();
    if (new_name == NULL) {
        free(old_name);
        return;
    }

    int result = rename(old_name, new_name);

    if (result == 0) {
        printf("Le fichier a été renommé avec succès.\n");
    } else {
        printf("Erreur lors du renommage du fichier %s vers %s \n", old_name, new_name);
    }
    free(old_name);
    free(new_name);
}