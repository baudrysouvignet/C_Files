#include "../main.h"
#include "nav.h"

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>


#include "../files/files.h"

#include <unistd.h>

#define RED "\033[31m"
#define RESET "\033[0m"

int choice_input(const char *type, void *choice);
void nav_input();
void nav_help();
void check_action(int value);
void print_nav();

void nav_input() {
    int choice;
    choice_input(" %d", &choice);

    if (choice == 0) return;
    if (choice == 99) {
        nav_help();
    } else {
        check_action(choice);
    }
}



void nav_help() {
    print_nav();
    nav_input();

}

void print_nav() {
    printf("=====================NAVIGATION=====================\n");
    printf("0 - Quitter\n");
    printf("99 - Navigation\n");
    printf("1 - Créer un fichier\n");
    printf("2 - Renomer un fichier\n");
    printf("3 - Supprimer un fichier\n");
    printf("====================================================\n");
}

int choice_input(const char *type, void *choice) {
    int result = scanf(type, choice);
    if (result != 1) {
        print_nav();
        printf(RED "Erreur: Saisir une option disponible dans la navigation :\n" RESET);
        clean_buffer();
        return 0;

    }
    return 1;
}

void check_action(int value) {
    switch (value) {
        case 1:
            nav_create_files();
        case 2:
            nav_rename_files();
        case 3:
            nav_delete_files();
        default:
    }
}
