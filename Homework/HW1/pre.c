#include <stdio.h>

int main() {
	int numCourses[12];
	char studentName[12][20];
	
	int i = 0;
	while (!feof(stdin)) {
		scanf(" %s", studentName[i]);
		scanf(" %d", &numCourses[i]);
		i++;
	}
	
	int j = 0;
	
	putc('\n', stdout);
	putc('\n', stdout);
		
	while ((i-1)!= j) {
		printf("%s ", studentName[j]);
		printf("%d\n", numCourses[j]);
		j++;
	}
	return 0;
}