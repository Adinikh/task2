#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

/* ---------- Validation ---------- */

int isAlphaString(const char *s)
{
    for(int i = 0; s[i]; i++)
        if(!isalpha(s[i]))
            return FALSE;
    return TRUE;
}

int isAlphaNumString(const char *s)
{
    for(int i = 0; s[i]; i++)
        if(!isalnum(s[i]))
            return FALSE;
    return TRUE;
}

int isDuplicate(Student st[], int n, const char *roll)
{
    for(int i = 0; i < n; i++)
        if(strcmp(st[i].roll, roll) == 0)
            return TRUE;
    return FALSE;
}

/* ---------- Grade ---------- */

void calculateGrade(Student *s)
{
    float p = s->percent;

    if(p >= 90) strcpy(s->grade, "O");
    else if(p >= 85) strcpy(s->grade, "A+");
    else if(p >= 75) strcpy(s->grade, "A");
    else if(p >= 65) strcpy(s->grade, "B+");
    else if(p >= 60) strcpy(s->grade, "B");
    else if(p >= 55) strcpy(s->grade, "C");
    else if(p >= 50) strcpy(s->grade, "D");
    else strcpy(s->grade, "F");

    s->cgpa = p / 10.0;
    if(s->cgpa > 10)
        s->cgpa = 10;
}

/* ---------- File Read ---------- */

int readStudents(const char *filename, Student st[], int *n)
{
    FILE *fp = fopen(filename, "r");
    if(!fp)
        return FALSE;

    fscanf(fp, "%d", n);

    for(int i = 0; i < *n; i++)
    {
        fscanf(fp, "%s %s", st[i].roll, st[i].name);

        if(!isAlphaNumString(st[i].roll)) return FALSE;
        if(isDuplicate(st, i, st[i].roll)) return FALSE;
        if(!isAlphaString(st[i].name)) return FALSE;

        st[i].total = 0;
        int fail = 0;

        for(int j = 0; j < SUB; j++)
        {
            fscanf(fp, "%d", &st[i].marks[j]);

            if(st[i].marks[j] < 0 || st[i].marks[j] > 100)
                return FALSE;

            if(st[i].marks[j] < 50)
                fail = 1;

            st[i].total += st[i].marks[j];
        }

        st[i].percent = st[i].total / (float)SUB;
        calculateGrade(&st[i]);

        if(fail)
        {
            strcpy(st[i].grade, "F");
            st[i].cgpa = 0.0;
        }
    }

    fclose(fp);
    return TRUE;
}

/* ---------- Report ---------- */

void printReport(Student st[], int n)
{
    float sum = 0, high = 0, low = 100;
    int g[8] = {0};

    printf("\nID\tName\tTotal\t%%\tGrade\tCGPA\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\t%s\t%d\t%.2f\t%s\t%.2f\n",
               st[i].roll, st[i].name,
               st[i].total, st[i].percent,
               st[i].grade, st[i].cgpa);

        sum += st[i].percent;
        if(st[i].percent > high) high = st[i].percent;
        if(st[i].percent < low)  low = st[i].percent;

        if(strcmp(st[i].grade,"O")==0) g[0]++;
        else if(strcmp(st[i].grade,"A+")==0) g[1]++;
        else if(strcmp(st[i].grade,"A")==0) g[2]++;
        else if(strcmp(st[i].grade,"B+")==0) g[3]++;
        else if(strcmp(st[i].grade,"B")==0) g[4]++;
        else if(strcmp(st[i].grade,"C")==0) g[5]++;
        else if(strcmp(st[i].grade,"D")==0) g[6]++;
        else g[7]++;
    }

    printf("\nClass Avg: %.2f", sum / n);
    printf("\nHighest: %.2f", high);
    printf("\nLowest: %.2f", low);

    printf("\n\nGrade Distribution:\n");
    printf("O:%d A+:%d A:%d B+:%d B:%d C:%d D:%d F:%d\n",
           g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7]);
}
