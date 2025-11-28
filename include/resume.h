#ifndef RESUME_H
#define RESUME_H

//This header file contains struture defination for storing resume details across the project.

#define MAX_TEST 500  //Maximum size for long text
#define DATAFILE "resumes.dat"  // File where all resume records are stored

//creating a structure to store all details entered by user
typedef struct {
    int id;   //Unique ID assigned

    //Personal Information
    char name[100];
    char email[100];
    char phone[50];
    char address[200];

    //Resume Content
    char objective[MAX_TEST];   //User's carrer objective
    char skills[MAX_TEST];      //User's skills
    char education[MAX_TEST];   // Education history of user
    char experience[MAX_TEST];  //Work or internship experience of user
    char certification[MAX_TEST];  //Extra certifications
    char hobbies[MAX_TEST];        //Hobbies or interests
    char languages[MAX_TEST];      //Languages known
} Resume;


//Function Declaration
int add_resume();   //Adds a new resume and save it to file
void list_resumes(); //Show all stored resumes with information
void view_resume();  //Display full resume details for given ID
int edit_resume();   //Edits a field(here email)
int delete_resume();  //Deletes a resume by ID
int export_resume();   //Exports a selected resume to text file
void wait_for_key();   //Pause until user presses enter

#endif  //End
