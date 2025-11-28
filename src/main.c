//This file contains the main menu loop for the program.

#include <stdio.h>
#include <stdlib.h>
#include "../include/resume.h"

int main() {
    int choice;

    while (1) {   //The menu will keep running until the user chooses Exit
        printf("\n=== Resume Maker ===\n");
        printf("1. Add Resume\n");
        printf("2. List Resumes\n");
        printf("3. View Resume\n");
        printf("4. Edit Resume\n");
        printf("5. Delete Resume\n");
        printf("6. Export Resume\n");
        printf("7. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);
        getchar();   //clears leftover newline so input works smoothly

        switch (choice) {
            case 1: add_resume(); break;
            case 2: list_resumes(); break;
            case 3: view_resume(); break;
            case 4: edit_resume(); break;
            case 5: delete_resume(); break;
            case 6: export_resume(); break;
            case 7: exit(0);   //program exit
            default:
               printf("Invalid choice.\n");
        }

        wait_for_key();  //pause so user can read output befor menu appears again
    }

    return 0;
}
