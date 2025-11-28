#ifndef RESUME_H
#define RESUME_H

#include <stdio.h>

#define WIDTH 80
#define MAX_ENTRIES 5
#define MAX_SKILLS 12
#define MAX_LANGS 8
#define MAX_CERTS 8
#define MAX_PROJS 8
#define MAX_HOBBIES 8

typedef struct {
    char place[128];
    char years[64];
    char title[128];
    char desc[256];
} Entry;

void print_centered(const char *str, int width);
void print_line(int width);
int input_validated_int(const char *prompt, int min, int max);
void collect_basic_info(char *name, char *profession, char *phone, char *email, char *address, char *about);
void print_resume(
    const char *fullName, const char *profession, const char *phone, const char *email, const char *address, const char *about,
    Entry *edu, int eduCount,
    Entry *jobs, int jobCount,
    char certs[][128], int certCount,
    char projects[][256], int projCount,
    char hobbies[][64], int hobbyCount,
    char skills[][64], int skillCount,
    char langs[][64], int langCount
);

#endif // RESUME_H

