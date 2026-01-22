#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100
#define SUB 5

#define TRUE 1
#define FALSE 0

typedef struct
{
    char roll[20];
    char name[30];
    int marks[SUB];
    int total;
    float percent;
    char grade[3];
    float cgpa;
} Student;

#endif
