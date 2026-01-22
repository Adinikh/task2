# Module Specification

## Student Result Processing System

This document describes the **module-wise specification** of the *Student Result Processing System* developed as part of **Task-2 (Software Engineering Lab)**. Each module is designed to ensure **high cohesion, low coupling, reusability, and interoperability**.

---

## 1. Module: `isAlphaString()`

**Module Name:** isAlphaString
**File:** `validation.c`

### Input

* `char *s` – Name string

### Pre-condition

* Input string should not be `NULL`

### Logic

* Traverse the string character by character
* Use `isalpha()` to check each character

### Output

* Returns `TRUE` if all characters are alphabets
* Returns `FALSE` otherwise

### Code Snippet

```c
int isAlphaString(const char *s) {
    for(int i = 0; s[i]; i++) {
        if(!isalpha(s[i])) return FALSE;
    }
    return TRUE;
}
```

---

## 2. Module: `isAlphaNumString()`

**Module Name:** isAlphaNumString
**File:** `validation.c`

### Input

* `char *s` – Roll number string

### Pre-condition

* Input string should not be `NULL`

### Logic

* Check each character using `isalnum()`

### Output

* Returns `TRUE` if string is alphanumeric
* Returns `FALSE` otherwise

### Code Snippet

```c
int isAlphaNumString(const char *s) {
    for(int i = 0; s[i]; i++) {
        if(!isalnum(s[i])) return FALSE;
    }
    return TRUE;
}
```

---

## 3. Module: `isDuplicate()`

**Module Name:** isDuplicate
**File:** `validation.c`

### Input

* Student array
* Roll number

### Pre-condition

* Student records must be loaded

### Logic

* Compare the roll number with existing student records

### Output

* Returns `TRUE` if duplicate roll exists
* Returns `FALSE` otherwise

### Code Snippet

```c
int isDuplicate(Student st[], int n, const char *roll) {
    for(int i = 0; i < n; i++) {
        if(strcmp(st[i].roll, roll) == 0)
            return TRUE;
    }
    return FALSE;
}
```

---

## 4. Module: `readStudents()`

**Module Name:** readStudents
**File:** `fileio.c`

### Input

* File name (`stu.txt`)
* Student array

### Pre-condition

* Input file should exist and be readable

### Logic

* Read student data from file
* Validate roll number, name, and marks
* Calculate total and percentage
* Call `calculateGrade()`
* Apply subject-wise fail rule (if any subject < 50 → Grade F)

### Output

* Returns `TRUE` if file processed successfully
* Returns `FALSE` otherwise

### Code Snippet

```c
int readStudents(const char *filename, Student st[], int *n) {
    FILE *fp = fopen(filename, "r");
    if(!fp) return FALSE;

    fscanf(fp, "%d", n);

    for(int i = 0; i < *n; i++) {
        int fail = 0;
        fscanf(fp, "%s %s", st[i].roll, st[i].name);

        st[i].total = 0;
        for(int j = 0; j < SUB; j++) {
            fscanf(fp, "%d", &st[i].marks[j]);
            if(st[i].marks[j] < 50) fail = 1;
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
```

---

## 5. Module: `calculateGrade()`

**Module Name:** calculateGrade
**File:** `grade.c`

### Input

* Student percentage

### Pre-condition

* Percentage must be calculated

### Logic

* Assign grade based on percentage range
* Calculate CGPA as `percentage / 10`

### Output

* Grade and CGPA updated in student structure

### Code Snippet

```c
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
}
```

---

## 6. Module: `printReport()`

**Module Name:** printReport
**File:** `report.c`

### Input

* Student array
* Number of students

### Pre-condition

* Student data must be processed

### Logic

* Display student details in tabular format
* Compute class average, highest, and lowest
* Display grade distribution

### Output

* Formatted report printed on console

### Code Snippet

```c
void printReport(Student st[], int n) {
    printf("\nID\tName\tTotal\t%%\tGrade\tCGPA\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%.2f\t%s\t%.2f\n",
               st[i].roll, st[i].name, st[i].total,
               st[i].percent, st[i].grade, st[i].cgpa);
    }
}
```

---

## 7. Module: `writeCSV()`

**Module Name:** writeCSV
**File:** `report.c`

### Input

* Student array
* Number of students

### Pre-condition

* Student data must be available

### Logic

* Write student details into CSV format

### Output

* `student_results.csv` file generated

### Code Snippet

```c
void writeCSV(Student st[], int n) {
    FILE *fp = fopen("student_results.csv", "w");
    fprintf(fp, "Roll,Name,Total,Percentage,Grade,CGPA\n");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%s,%s,%d,%.2f,%s,%.2f\n",
                st[i].roll, st[i].name,
                st[i].total, st[i].percent,
                st[i].grade, st[i].cgpa);
    }
    fclose(fp);
}
```

---

## 8. Module: `main()`

**Module Name:** main
**File:** `main.c`

### Input

* None (reads from file)

### Pre-condition

* All modules should be available

### Logic

* Invoke file reading, processing, reporting, and CSV generation modules

### Output

* Complete execution of Student Result Processing System

### Code Snippet

```c
int main() {
    Student st[MAX];
    int n;

    if(!readStudents("stu.txt", st, &n)) {
        printf("File error\n");
        return 1;
    }

    printReport(st, n);
    writeCSV(st, n);
    return 0;
}
```

---

## Conclusion

This modular design improves **maintainability, reusability, testability, and interoperability**, satisfying the objectives of **Task-2** and Software Engineering best practices.
