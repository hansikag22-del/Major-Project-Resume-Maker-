#include <stdio.h>
#include <string.h>
#include "../include/resume.h"

int main(void) {
    char fullName[64] = "", profession[64] = "", phone[32] = "", email[64] = "", address[128] = "", about[512] = "";

    Entry edu[MAX_ENTRIES];
    Entry jobs[MAX_ENTRIES];
    char certs[MAX_CERTS][128];
    char projects[MAX_PROJS][256];
    char hobbies[MAX_HOBBIES][64];
    char skills[MAX_SKILLS][64];
    char langs[MAX_LANGS][64];

    int eduCount, jobCount, certCount, projCount, hobbyCount, skillCount, langCount;

    puts("Welcome to the Resume Maker! Enter your details.\n");

    collect_basic_info(fullName, profession, phone, email, address, about);

    eduCount = input_validated_int("Number of education entries", 0, MAX_ENTRIES);
    for (int i = 0; i < eduCount; i++) {
        printf("\nEducation %d - Institution/School: ", i+1);
        fgets(edu[i].place, sizeof(edu[i].place), stdin); edu[i].place[strcspn(edu[i].place, "\n")] = 0;
        printf("Years (e.g., 2020-2024): ");
        fgets(edu[i].years, sizeof(edu[i].years), stdin); edu[i].years[strcspn(edu[i].years, "\n")] = 0;
        printf("Degree / Title: ");
        fgets(edu[i].title, sizeof(edu[i].title), stdin); edu[i].title[strcspn(edu[i].title, "\n")] = 0;
        printf("Short description: ");
        fgets(edu[i].desc, sizeof(edu[i].desc), stdin); edu[i].desc[strcspn(edu[i].desc, "\n")] = 0;
    }

    jobCount = input_validated_int("Number of job entries", 0, MAX_ENTRIES);
    for (int i = 0; i < jobCount; i++) {
        printf("\nJob %d - Company: ", i+1);
        fgets(jobs[i].place, sizeof(jobs[i].place), stdin); jobs[i].place[strcspn(jobs[i].place, "\n")] = 0;
        printf("Years (e.g., 2019-2021): ");
        fgets(jobs[i].years, sizeof(jobs[i].years), stdin); jobs[i].years[strcspn(jobs[i].years, "\n")] = 0;
        printf("Job Title: ");
        fgets(jobs[i].title, sizeof(jobs[i].title), stdin); jobs[i].title[strcspn(jobs[i].title, "\n")] = 0;
        printf("Description: ");
        fgets(jobs[i].desc, sizeof(jobs[i].desc), stdin); jobs[i].desc[strcspn(jobs[i].desc, "\n")] = 0;
    }

    certCount = input_validated_int("Number of certifications", 0, MAX_CERTS);
    for (int i = 0; i < certCount; i++) {
        printf("Certification %d: ", i+1);
        fgets(certs[i], sizeof(certs[i]), stdin); certs[i][strcspn(certs[i], "\n")] = 0;
    }

    projCount = input_validated_int("Number of projects", 0, MAX_PROJS);
    for (int i = 0; i < projCount; i++) {
        printf("Project %d: ", i+1);
        fgets(projects[i], sizeof(projects[i]), stdin); projects[i][strcspn(projects[i], "\n")] = 0;
    }

    hobbyCount = input_validated_int("Number of hobbies", 0, MAX_HOBBIES);
    for (int i = 0; i < hobbyCount; i++) {
        printf("Hobby %d: ", i+1);
        fgets(hobbies[i], sizeof(hobbies[i]), stdin); hobbies[i][strcspn(hobbies[i], "\n")] = 0;
    }

    skillCount = input_validated_int("Number of skills", 1, MAX_SKILLS);
    for (int i = 0; i < skillCount; i++) {
        printf("Skill %d: ", i+1);
        fgets(skills[i], sizeof(skills[i]), stdin); skills[i][strcspn(skills[i], "\n")] = 0;
    }

    langCount = input_validated_int("Number of languages", 0, MAX_LANGS);
    for (int i = 0; i < langCount; i++) {
        printf("Language %d: ", i+1);
        fgets(langs[i], sizeof(langs[i]), stdin); langs[i][strcspn(langs[i], "\n")] = 0;
    }

    puts("\n--- GENERATED RESUME ---\n");

    print_resume(fullName, profession, phone, email, address, about,
                 edu, eduCount,
                 jobs, jobCount,
                 certs, certCount,
                 projects, projCount,
                 hobbies, hobbyCount,
                 skills, skillCount,
                 langs, langCount);

    return 0;
}
