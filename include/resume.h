#ifndef RESUME_H
#define RESUME_H

#define MAX_TEST 500
#define DATAFILE "resumes.dat"

typedef struct {
    int id;
    char name[100];
    char email[100];
    char phone[50];
    char address[200];
    char objective[MAX_TEST];
    char skills[MAX_TEST];
    char education[MAX_TEST];
    char experience[MAX_TEST];
    char certification[MAX_TEST];
    char hobbies[MAX_TEST];
    char languages[MAX_TEST];
} Resume;

int add_resume();
void list_resumes();
void view_resume();
int edit_resume();
int delete_resume();
int export_resume();
void wait_for_key();

#endif
