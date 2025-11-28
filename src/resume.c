#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/resume.h"

void print_centered(const char *str, int width) {
    if (!str) return;
    int len = (int)strlen(str);
    int pad = (width - len) / 2;
    if (pad < 0) pad = 0;
    for (int i = 0; i < pad; i++) putchar(' ');
    puts(str);
}

void print_line(int width) {
    for (int i = 0; i < width; i++) putchar('_');
    putchar('\n');
}

int input_validated_int(const char *prompt, int min, int max) {
    int val = min - 1;
    char buf[64];
    while (1) {
        printf("%s (%d-%d): ", prompt, min, max);
        if (!fgets(buf, sizeof(buf), stdin)) return min;
        if (sscanf(buf, "%d", &val) != 1) {
            printf("Please enter a valid number.\n");
            continue;
        }
        if (val < min || val > max) {
            printf("Number out of range. Try again.\n");
            continue;
        }
        break;
    }
    return val;
}

void collect_basic_info(char *name, char *profession, char *phone, char *email, char *address, char *about) {
    printf("Full Name: ");
    fgets(name, 64, stdin); name[strcspn(name, "\n")] = 0;
    printf("Profession: ");
    fgets(profession, 64, stdin); profession[strcspn(profession, "\n")] = 0;
    printf("Phone: ");
    fgets(phone, 32, stdin); phone[strcspn(phone, "\n")] = 0;
    printf("Email: ");
    fgets(email, 64, stdin); email[strcspn(email, "\n")] = 0;
    printf("Address: ");
    fgets(address, 128, stdin); address[strcspn(address, "\n")] = 0;
    printf("About Me (one paragraph): ");
    fgets(about, 512, stdin); about[strcspn(about, "\n")] = 0;
}

void print_resume(
    const char *fullName, const char *profession, const char *phone, const char *email, const char *address, const char *about,
    Entry *edu, int eduCount,
    Entry *jobs, int jobCount,
    char certs[][128], int certCount,
    char projects[][256], int projCount,
    char hobbies[][64], int hobbyCount,
    char skills[][64], int skillCount,
    char langs[][64], int langCount
) {
    print_centered(fullName, WIDTH);
    print_centered(profession, WIDTH);
    char header[512];
    snprintf(header, sizeof(header), "%s | %s | %s", phone, email, address);
    print_centered(header, WIDTH);
    print_line(WIDTH);

    printf("\nABOUT ME\n%s\n", about);
    print_line(WIDTH);

    printf("\nEDUCATION\n");
    for (int i = 0; i < eduCount; i++) {
        printf("%s | %s\n%s\n%s\n\n", edu[i].place, edu[i].years, edu[i].title, edu[i].desc);
    }
    print_line(WIDTH);

    printf("\nWORK EXPERIENCE\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%s | %s\n%s\n%s\n\n", jobs[i].place, jobs[i].years, jobs[i].title, jobs[i].desc);
    }
    print_line(WIDTH);

    if (certCount > 0) {
        printf("\nCERTIFICATIONS\n");
        for (int i = 0; i < certCount; i++) printf("- %s\n", certs[i]);
        print_line(WIDTH);
    }

    if (projCount > 0) {
        printf("\nPROJECTS\n");
        for (int i = 0; i < projCount; i++) printf("- %s\n", projects[i]);
        print_line(WIDTH);
    }

    if (hobbyCount > 0) {
        printf("\nHOBBIES\n");
        for (int i = 0; i < hobbyCount; i++) printf("- %s\n", hobbies[i]);
        print_line(WIDTH);
    }

    printf("\n%-40s%-40s\n", "SKILLS", "LANGUAGES");
    int maxCount = skillCount > langCount ? skillCount : langCount;
    for (int i = 0; i < maxCount; i++) {
        if (i < skillCount) printf("- %-38s", skills[i]); else printf("%40s", "");
        if (i < langCount) printf("- %-38s", langs[i]);
        printf("\n");
    }
    print_line(WIDTH);
}
