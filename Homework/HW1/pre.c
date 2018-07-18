#include <stdio.h>

int main() {
	int numCourses[12];
	char studentName[12][20];
	
	int i = 0;
	while (!feof(stdin)) {
		scanf(" %s %d", studentName[i], &numCourses[i]);
		i++;
	}
	
	int j = 0;
	
	putc('\n', stdout);
		
	while (j < i) {
		if (numCourses[j] >5) {
			printf("%s \n", studentName[j]);
		}
		j++;
	}
	
	return 0;
}