#include <string.h>
#include "grade.h"

void calculateGrade(Student *s) {
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
    if(s->cgpa > 10) s->cgpa = 10;
}
