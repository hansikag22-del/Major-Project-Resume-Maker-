#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/resume.h"

static void read_line(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  //remove newline
}

//pause the screen after each menu so that user can read output.
void wait_for_key()
{
    printf("\nPress Enter to continue..");
    getchar();
}

//Adds the resume
int add_resume() 
{
    Resume r;

    FILE *fp = fopen(DATAFILE, "ab+");
    if (!fp) 
    {
        printf("Error: Unable to open data file.\n");
        return 0;
    }
    
    //Assign next ID based on file size.
    fseek(fp, 0, SEEK_END);
    r.id = (ftell(fp) / sizeof(Resume)) + 1;

    printf("\nEnter full name: ");
    read_line(r.name, sizeof(r.name));

    printf("Email: ");
    read_line(r.email, sizeof(r.email));

    printf("Phone: ");
    read_line(r.phone, sizeof(r.phone));

    printf("Address: ");
    read_line(r.address, sizeof(r.address));

    printf("Career Objective: ");
    read_line(r.objective, sizeof(r.objective));

    printf("Skills (comma separated): ");
    read_line(r.skills, sizeof(r.skills));

    printf("Education: ");
    read_line(r.education, sizeof(r.education));

    printf("Experience: ");
    read_line(r.experience, sizeof(r.experience));

    printf("Certifications: ");
    read_line(r.certification, sizeof(r.certification));

    printf("Hobbies: ");
    read_line(r.hobbies, sizeof(r.hobbies));

    printf("Languages: ");
    read_line(r.languages, sizeof(r.languages));
    
    //Save data to file
    fwrite(&r, sizeof(r), 1, fp);
    fclose(fp);

    printf("\nResume saved successfully.\n");
    return 1;
}

//Display summary of all stored resumes.
void list_resumes()
{
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp)
    {
        printf("No data found.\n");
        return;
    }
    Resume r;
    printf("\nStored Resumes:\n");
    printf("----------------------\n");

    while(fread(&r, sizeof(r), 1, fp))
    {
        printf("ID: %d | %s | %s\n", r.id, r.name, r.email);
    }

    fclose(fp);
}

//Show full details of resume based on ID entered by the user.
void view_resume()
{
    int id;
    printf("\nEnter resume ID: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp)
    {
        printf("Data file missing.\n");
        return;
    }

    Resume r;
    int found = 0;

    while (fread(&r, sizeof(r), 1, fp))
    {
        if (r.id == id)
        {
            found = 1;
            printf("\n----- RESUME %d -----\n", r.id);
            printf("Name: %s\nEmail: %s\nPhone: %s\nAddress: %s\n\n", r.name, r.email, r.phone, r.address);
            printf("Objective:\n%s\n\n", r.objective);
            printf("Skills:\n%s\n\n", r.skills);
            printf("Experience:\n%s\n", r.experience);
            printf("Certification:\n%s\n", r.certification);
            printf("Hobbies:\n%s\n\n", r.hobbies);
            printf("Languages:\n%s\n\n", r.languages);
            break;
        }
    }

    if (!found)
        printf("Resume not found.\n");

    fclose(fp);
}

//Updates the email for selected resume.
int edit_resume()
{
    int id;
    printf("\nEnter ID to update email: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(DATAFILE, "rb+");
    if (!fp)
    {
        printf("Cannot open the database.\n");
        return 0;
    }

    Resume r;
    long pos;
    int found = 0;

    while ((pos = ftell(fp)), fread(&r, sizeof(r), 1, fp))
    {
        if (r.id == id)
        {
            found = 1;

            printf("Current Email: %s\nNew Email: ", r.email);
            read_line(r.email, sizeof(r.email));

            fseek(fp, pos, SEEK_SET);
            fwrite(&r, sizeof(r), 1, fp);

            printf("Email Updated.\n");
            break;

        }
    }

    fclose(fp);
    return found;
}

//Removes a resume
int delete_resume()
{
    int id;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(DATAFILE, "rb");
    FILE *tmp = fopen("temp.dat", "wb");

    if (!fp || !tmp)
    {
        printf("File error.\n");
        return 0;
    }

    Resume r;
    int removed = 0;

    while (fread(&r, sizeof(r), 1, fp))
    {
        if (r.id == id)
        {
            removed = 1;
            continue;  //skips the ID to delete
        }
        fwrite(&r, sizeof(r), 1, tmp);
    }

    fclose(fp);
    fclose(tmp);

    remove(DATAFILE);
    rename("temp.dat", DATAFILE);

    if (removed)
        printf("Resume deleted.\n");
    else
        printf("ID not found.\n");

    return removed;

}

//Writes selected resume into readable text file.
int export_resume()
{
    int id;
    printf("\nExport which ID? ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp)
    {
        printf("No data.\n");
        return 0;
    }

    Resume r;
    int found = 0;

    while (fread(&r, sizeof(r), 1, fp))
    {
        if (r.id == id)
        {
            found = 1;
            FILE *out = fopen("resume_export.txt", "w");

            fprintf(out, "Name: %s\n", r.name);
            fprintf(out, "Email: %s\n", r.email);
            fprintf(out, "Phone: %s\n", r.phone);
            fprintf(out, "Address: %ss\n\n", r.address);

            fprintf(out, "objective:\n%s\n\n", r.objective);
            fprintf(out, "Skills:\n%s\n\n", r.skills);
            fprintf(out, "Education:\n%s\n\n", r.education);
            fprintf(out, "Experience:\n%s\n", r.experience);
            fprintf(out, "Certification:\n%s\n", r.certification);
            fprintf(out, "Hobbies:\n%s\n\n", r.hobbies);
            fprintf(out, "Languages:\n%s\n\n", r.languages);

            fclose(out);
            break;
        }
    }

    fclose(fp);

    if (found)
       printf("Exported to resume_export.txt\n");
    else
       printf("Resume not found.\n");

    return found;
}