#include <stdio.h>
#include <string.h>
#include "report.h"

#include <stdio.h>
#include <string.h>
#include "report.h"

void printReport(Student st[], int n) {
    float total=0, high=0, low=100;
    int g[8]={0};

    printf("\nID\tName\tTotal\t%%\tGrade\tCGPA\n");

    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%d\t%.2f\t%s\t%.2f\n",
            st[i].roll, st[i].name,
            st[i].total, st[i].percent,
            st[i].grade, st[i].cgpa);

        total += st[i].percent;
        if(st[i].percent > high) high = st[i].percent;
        if(st[i].percent < low) low = st[i].percent;

        if(strcmp(st[i].grade,"O")==0) g[0]++;
        else if(strcmp(st[i].grade,"A+")==0) g[1]++;
        else if(strcmp(st[i].grade,"A")==0) g[2]++;
        else if(strcmp(st[i].grade,"B+")==0) g[3]++;
        else if(strcmp(st[i].grade,"B")==0) g[4]++;
        else if(strcmp(st[i].grade,"C")==0) g[5]++;
        else if(strcmp(st[i].grade,"D")==0) g[6]++;
        else g[7]++;
    }

    printf("\nClass Avg: %.2f", total/n);
    printf("\nHighest: %.2f", high);
    printf("\nLowest: %.2f", low);

    printf("\n\nGrade Distribution:\n");
    printf("O:%d A+:%d A:%d B+:%d B:%d C:%d D:%d F:%d\n",
        g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7]);
}


