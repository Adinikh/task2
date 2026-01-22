#include <stdio.h>
#include "utils.h"

int main()
{
    Student st[MAX];
    int n;

    if(!readStudents("stu.txt", st, &n))
    {
        printf("Error reading student data\n");
        return 1;
    }

    printReport(st, n);
    return 0;
}
