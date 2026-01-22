#ifndef UTILS_H
#define UTILS_H

#include "student.h"

/* validation */
int isAlphaString(const char *s);
int isAlphaNumString(const char *s);
int isDuplicate(Student st[], int n, const char *roll);

/* file handling */
int readStudents(const char *filename, Student st[], int *n);

/* grading */
void calculateGrade(Student *s);

/* reporting */
void printReport(Student st[], int n);

#endif
