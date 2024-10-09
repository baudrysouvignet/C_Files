#include "files.h"

#include "../main.h"
#include "../global/nav.h"


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void delete_files();

void nav_delete_files() {
    const char * cwd = get_pwd();
    printf("Voulez vous supprimer un fichier dans le répertoire (o/n): %s\n", cwd);
    char reponse;
    choice_input(" %c", &reponse);
    if (reponse == 'o') {
        delete_files();
    } else {
        printf("0- Quitter 99- Navigation\n");
        nav_input();
    }
}

char* input_delete_files() {
    char filename[1024] = {0};
    char* fullPath = (char*)malloc(2048 * sizeof(char));
    choice_input(" %s", filename);
    snprintf(fullPath, 2048, "%s%s%s", get_pwd(), get_separator(), filename);
    if(file_exists(fullPath)) {
        return fullPath;
    }
    printf("Le fichier %s n'existe pas, entrée une donnée valide !\n", fullPath);
    return input_delete_files();
}

void delete_files() {
  printf("Choisissez le nom du fichier à supprimer (exemple: text.txt): ");
  char*file_name = input_delete_files();

  int result = remove(file_name);

  if (result == 0) {
    printf("Le fichier a été supprimé avec succès.\n");
  } else {
    printf("Erreur lors de la suppression du fichier %s", file_name);
  }
}