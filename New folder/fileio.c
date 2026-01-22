#include <string.h>
#include <stdio.h>
#include "fileio.h"
#include "validation.h"
#include "grade.h"

int readStudents(const char *filename, Student st[], int *n) {
FILE *fp = fopen(filename, "r");
    if(!fp) return FALSE;
fscanf(fp, "%d", n);

    for(int i=0; i<*n; i++) {
        fscanf(fp, "%s %s", st[i].roll, st[i].name);

        if(!isAlphaNumString(st[i].roll)) return FALSE;
        if(isDuplicate(st, i, st[i].roll)) return FALSE;
        if(!isAlphaString(st[i].name)) return FALSE;

        st[i].total = 0;
       int fail = 0;

for(int j = 0; j < SUB; j++) {
    fscanf(fp, "%d", &st[i].marks[j]);

    if(st[i].marks[j] < 0 || st[i].marks[j] > 100)
        return FALSE;

    if(st[i].marks[j] < 50)
        fail = 1;

    st[i].total += st[i].marks[j];
}


        st[i].percent = st[i].total / (float)SUB;
calculateGrade(&st[i]);

if(fail) {
    strcpy(st[i].grade, "F");
    st[i].cgpa = 0.0;
}

    }
    fclose(fp);
    return TRUE;
}
