#include "files.h"

#include "../main.h"
#include "../global/nav.h"


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void create_file();

void nav_create_files() {
    const char * cwd = get_pwd();
    printf("Voulez vous créer un fichier dans le répertoire %s (o/n): \n", cwd);
    char reponse;
    choice_input(" %c", &reponse);
    if (reponse == 'o') {
        create_file();
    } else {
        printf("0- Quitter 99- Navigation\n");
        nav_input();
    }

}

void create_file() {
    char pathname[1024 + 20];
    char filename[1024];
    printf("Choisissez le nom du fichier (exemple: text.txt)\n");
    choice_input(" %s", filename);
    snprintf(pathname, sizeof(pathname), "%s%sfiles.txt", get_pwd(), get_separator());
    fopen(filename, "w");
    printf("Fichier crée avec succées");
}