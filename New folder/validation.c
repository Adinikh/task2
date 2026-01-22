#include <ctype.h>
#include <string.h>
#include "validation.h"

int isAlphaString(const char *s) {
    for(int i=0; s[i]; i++)
        if(!isalpha(s[i])) return FALSE;
    return TRUE;
}

int isAlphaNumString(const char *s) {
    for(int i=0; s[i]; i++)
        if(!isalnum(s[i])) return FALSE;
    return TRUE;
}

int isDuplicate(Student st[], int n, const char *roll) {
    for(int i=0; i<n; i++)
        if(strcmp(st[i].roll, roll) == 0)
            return TRUE;
    return FALSE;
}
