#include <stdio.h>

/**
This program takes a name and number of computer science courses taken
in one line. The program then outputs the names of students who have
taken more than 5 classes. CTRL+D, EOF, will stop the input.
**/

int main() {
	int numCourses[12];
	char studentName[12][20];
	
	int i = 0;
	printf("\nEnter name and classes taken. This program will output students \n");
	printf("who have taken more than 5 classes. Press \"CTRL+D\" to end input\n");
	printf("Eg: Patrick 8\n\n");

	// Take name of student and integer, add to respective arrays.
	while (!feof(stdin)) {
		scanf(" %s %d", studentName[i], &numCourses[i]);
		i++;
	}
	
	int j = 0;
	
	putc('\n', stdout);
		
	// Iterate through each entry. If number is > 5, print the name.
	while (j < (i - 1)) {
		if (numCourses[j] >5) {
			printf("%s \n", studentName[j]);
		}
		j++;
	}
	
	return 0;
}