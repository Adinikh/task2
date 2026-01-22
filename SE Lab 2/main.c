#include <stdio.h>
#include "student.h"
#include "fileio.h"
#include "report.h"

int main() {
    Student st[MAX];
    int n;

    if(!readStudents("stu.txt", st, &n)) {
        printf("Input error\n");
        return 1;
    }

    printReport(st, n);
    return 0;
}
