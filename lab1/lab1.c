/*
 * Adrian Pardo 6104101 
 * I  affirm that I wrote this program myself without any help form any
 * other people or sources from the internet.
 *
 * This program displays students grades and calculates their GPA's, Grade Points Earned and Total Credits
*/

#include <stdio.h>

// struct to group all variables required for students grade information
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
	
	// Creating an array of students using the Grades struct
	struct Grades students[3] = {
					{"Luke", "Skywalker", "COP1111", 3, 3.47, "COP2222", 3, 3.22, "COP3333", 3, 2.49, "COP4444", 3, 4.05, "COP5555", 3, 3.12, "COP6666", 3, 2.12},
					{"Obi Wan", "Kenobi", "COP1111", 3, 1.65, "COP2222", 3, 2.28, "COP3333", 3, 3.41, "COP4444", 3, 3.09, "COP5555", 3, 1.99, "COP6666", 3, 1.60},
					{"Kylo", "Ren", "COP1111", 3, 2.45, "COP2222", 3, 3.21, "COP3333", 3, 0.45, "COP4444", 3, 1.00, "COP5555", 3, 2.37, "COP6666", 3, 3.11},
				    };
	
	// Taking the total size of the students array struct and dividing by the size of one student struct to determine the array length
	int studentsLen = (int)( sizeof(students) / sizeof(students[0]) );
	
	// for loop going through every student and printing grades in proper format and calculating gpa for each. Note: Declaring variables inside a for loop wasn't valid C until C99
	int i;
	for (i = 0; i < studentsLen; i++) {
		// Storing totalCredits earned into variable for alter use
		int totalCredits = students[i].course1Credits + students[i].course2Credits + students[i].course3Credits + students[i].course4Credits + students[i].course5Credits + students[i].course6Credits;
		// Printing grade report in proper format
		printf("Student Name: %s %s\n", students[i].fName, students[i].lName);
		printf("Course\t\tCredits\t\t%10s\t\t%s\n", "Grade", "Grade Points Earned");
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course1, students[i].course1Credits, students[i].course1Grade, students[i].course1Grade *  students[i].course1Credits);
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course2, students[i].course2Credits, students[i].course2Grade, students[i].course2Grade * students[i].course2Credits);
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course3, students[i].course3Credits, students[i].course3Grade, students[i].course3Grade * students[i].course3Credits);
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course4, students[i].course4Credits, students[i].course4Grade, students[i].course4Grade * students[i].course4Credits);
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course5, students[i].course5Credits, students[i].course5Grade, students[i].course5Grade * students[i].course5Credits);
		printf("%-7s \t%4d \t\t%10.2lf \t\t%19.2lf\n",  students[i].course6, students[i].course6Credits, students[i].course6Grade, students[i].course6Grade * students[i].course6Credits);
		// Calculating while printing "Grade Points Earned" total as instructed in the assignment
		printf("%-7s \t%4d \t\t\t\t%27.2lf\n\n", "Total", totalCredits, (students[i].course1Grade *  students[i].course1Credits) + (students[i].course2Grade *  students[i].course2Credits) + (students[i].course3Grade *  students[i].course3Credits) + (students[i].course4Grade *  students[i].course4Credits) + (students[i].course5Grade *  students[i].course5Credits) + (students[i].course6Grade *  students[i].course6Credits));
		printf("Current GPA: %.2lf\n\n\n", (students[i].course1Grade + students[i].course1Grade + students[i].course1Grade + students[i].course1Grade + students[i].course1Grade + students[i].course1Grade) / 6.0);
	}
	return 0;
}
