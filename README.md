Project Overview

This project is a Resume Maker written in C.
It allows users to create, store, view, edit, delete, and export resumes,through a simple text-based menu.
The resume data is saved in a binary file (resumes.dat), and users can export any resume into a readable .txt file.

This project demonstrates concepts like:-

1.File handling in C
2.Working with structures
3.Dynamic data storage using binary files
4.Modular c programming using multiple .c and .h files
4.Basic CRUD operations (Create, Read, Update, Delete)

Project Structure
Resume-Maker/
│
├── src/
│   ├── main.c
│   └── resume.c
│
├── include/
│   └── resume.h
│
├── docs/
│   └── (project report)
│
├── assets/
│   └── (images or diagrams)
│
├── resumes.dat         (auto-created binary database)
├── resume_export.txt   (created when exporting a resume)
└── README.md

Features
1. Add Resume
Enter details such as name, contact information, objective, skills, education, certifications, hobbies, languages, etc.
2. List All Resumes
Displays saved resumes with ID, name, and email.
3. View a Resume
Shows full details of a selected resume by ID.
4. Edit Resume
Currently allows updating the email address of a resume.
5. Delete Resume
Removes a resume from the system using its ID.
6. Export Resume
Exports the selected resume into resume_export.txt.

How to Compile and Run
1.Using VS Code
2.Open the project folder
3.Install C/C++ extension
4.Create a build task (if needed)
5.Run main.c

Sample Menu Output
=== Resume Maker ===
1. Add Resume
2. List Resumes
3. View Resume
4. Edit Resume
5. Delete Resume
6. Export Resume
7. Exit
Choose:

Data Storage
All resume data is stored in a binary file named:
resumes.dat
This file is created automatically on the first run.
When the user exports a resume, a text file is generated:
resume_export.txt

Technologies Used
1.C Programming Language
2.GCC Compiler
3.File Handling and Structures
4.Modular Code Architecture

Author:-
Hansika Gupta
Btech-CSE 1st Year
