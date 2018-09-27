/*
 * Adrian Pardo 6104101 
 * I  affirm that I wrote this program myself without any help form any
 * other people or sources from the internet.
 *
*/

#include <stdio.h>

// struct to group all variables required for students grade information
struct Dob {
	char month[9];
	int day;
	int year;
};

struct Student {
 	char fName[30];
 	char lName[30];
	char id[7];
	struct Dob dob;
	char standing[8];
	float gpa;
};

int main() {
	// Creating an array of students using the Grades struct
	struct Student student0 = {"Adrian", "Pardo", "112233", "January", 01, 1990, "Junior", 3.65};
	//struct student *sptr = student0;
	printf("Name: %s %s\nStudent ID: %s\nDOB: %s %d %d\nStanding: %s\nGPA: %.2lf\n", student0.fName, student0.lName, student0.id, student0.dob.month, student0.dob.day, student0.dob.year, student0.standing, student0.gpa);
	struct Student *sptr0 = &student0;

	printf("\n\n\n%s %s\nStudent ID: %s\nDOB: %s %d %d\nStanding: %s\nGPA: %.2lf\n", sptr0->fName, sptr0->lName, sptr0->id, sptr0->dob.month, sptr0->dob.day, sptr0->dob.year, sptr0->standing, sptr0->gpa);
	return 0;
}
