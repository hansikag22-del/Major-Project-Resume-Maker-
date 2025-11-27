#ifndef RESUME_H
#define RESUME_H

#define WIDTH 80
#define MAX_ENTRIES 3
#define MAX_SKILLS 6
#define MAX_LANGS 6
#define MAX_CERTS 3
#define MAX_PROJS 3
#define MAX_HOBBIES 5

void printCentered(const char *str, int width);
void printLine(int width);
int inputValidatedInt(const char *prompt, int min, int max);

void createResume();

#endif
