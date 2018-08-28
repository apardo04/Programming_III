/*
 * Adrian Pardo 6104101
 * I  affirm that I wrote this program myself without any help form any
 * other people or sources from the internet.
 */

#include <stdio.h>

 struct Grades {
        char fName[20];
        char lName[20];
        char course1[7];
        int course1Credits;
        float course1Grade;
        char course2[7];
        int course2Credits;
        float course2Grade;
        char course3[7];
        int course3Credits;
        float course3Grade;
        char course4[7];
        int course4Credits;
        float course4Grade;
        char course5[7];
        int course5Credits;
        float course5Grade;
        char course6[7];
        int course6Credits;
        float course6Grade;
 };


int main() {
        printf("Adrian Pardo\nPantherID: 6104101\n\n\n");
//      printf("Course\tCredits\tGrade\tGrade Points Earned\n");
        struct Grades students[3] = {
                                        {"Luke", "Skywalker", "COP1111", 3, 3.45, "COP2222", 3, 3.21, "COP3333", 3, 2.45, "COP4444", 3, 4.00, "COP5555", 3, 3.37, "COP6666", 3, 2.11},
                                        {"Obi Wan", "Kenobi", "COP1111", 3, 1.45, "COP2222", 3, 2.21, "COP3333", 3, 3.45, "COP4444", 3, 3.00, "COP5555", 3, 1.37, "COP6666", 3, 1.11},
                                        {"Kylo", "Ren", "COP1111", 3, 2.45, "COP2222", 3, 3.21, "COP3333", 3, 0.45, "COP4444", 3, 1.00, "COP5555", 3, 2.37, "COP6666", 3, 3.11},
                                    };
        int studentsLen = (int)( sizeof(students) / sizeof(students[0]) );
        // declaring variables inside a for loop wasn't valid C until C99
        int i;
        for (i = 0; i < studentsLen; i++) {
                printf("Student Name: %s %s\n", students[i].fName, students[i].lName);
                printf("Course\t\tCredits\t\tGrade\t\tGrade Points Earned\n");
                printf("%s \t%d \t\t%.2lf \t\t%.2lf\n",  students[i].course1, students[i].course1Credits, students[i].course1Grade, students[i].course1Grade *  students[i].course1Credits);
                printf("%s \t%d \t\t%.2lf \t\t%.2lf\n",  students[i].course2, students[i].course2Credits, students[i].course2Grade, students[i].course2Grade * students[i].course2Credits);
        }
        //printf("Test print\n%s %s %s %lf\n", students[0].fName, students[0].lName, students[0].course1, students[0].course1Grade);
        return 0;
}
          