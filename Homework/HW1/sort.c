#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** This program takes in several names and alphabetizes them. The program
	considers lowercase as smaller than uppercase. CTRL+D to stop input.
**/

int main() {

	printf("\nEnter names to alphabetize. This program will output names in  \n");
	printf("alphabetical order with lowercase before uppercase. Press \"CTRL+D\" to end input\n");
	printf("Seperate names by enter.\n\n");
	
	const int MAX_NAMES = 12;
	const int MAX_CHAR = 20;
	char nameList[MAX_NAMES][MAX_CHAR];
	int n = 0;

	// Take a list of names until CTRL+D
	while (!feof(stdin)) {
		scanf(" %s", nameList[n]);
		n++;
	}

	putc('\n', stdout);

	// If only one item, do this.
	if (n == 1) 
		printf("%s \n", nameList[0]);
	else {

		// Take item i to be the lowest
		int i;
		for (i = 0; i < n; i++) {
			char tempWord[MAX_CHAR];

			int j;
			for (j = i + 1; j < (n - 1); j++) {

				// Compare 1st character of i and j (which is i + i, ++)
				int k;
				for (k = 0; k < MAX_CHAR; k++) {

					// These operations subtract 90 from char to prioritize
					// the lowercase characters.
					bool leftLowerCase = false;
					bool rightLowerCase = false;
					if (nameList[i][k] > 96){
						nameList[i][k] -= 90;
						leftLowerCase = true;
					}
					if (nameList[j][k] > 96){
						nameList[j][k] -= 90;
						rightLowerCase = true;
					}
					if (nameList[i][k] == '\0'){
						if (leftLowerCase == true)
							nameList[i][k] += 90;
						if (rightLowerCase == true)
							nameList[j][k] += 90;
						break;
					}

					// After each operation, end character, less than, greater
					// than, or equal too, be sure to set the ascii back to 
					// lowercase if it was changed.
					if (nameList[j][k] == '\0'){
						if (leftLowerCase == true)
							nameList[i][k] += 90;
						if (rightLowerCase == true)
							nameList[j][k] += 90;
						strcpy(tempWord, nameList[i]);
						strcpy(nameList[i], nameList[j]);
						strcpy(nameList[j], tempWord);
						break;					}

					if (nameList[i][k] < nameList[j][k]) {
						if (leftLowerCase == true)
							nameList[i][k] += 90;
						if (rightLowerCase == true)
							nameList[j][k] += 90;
						break;
					}
					else if (nameList[i][k] > nameList[j][k]) {	
						if (leftLowerCase == true)
							nameList[i][k] += 90;
						if (rightLowerCase == true)
							nameList[j][k] += 90;
						strcpy(tempWord, nameList[i]);
						strcpy(nameList[i], nameList[j]);
						strcpy(nameList[j], tempWord);
						break;
						}
					else {
						if (leftLowerCase == true)
							nameList[i][k] += 90;
						if (rightLowerCase == true)
							nameList[j][k] += 90;
						continue;
					}
				}
			}
		}
	}
	int j;
	for(j = 0; j < (n - 1); j++) {
		printf("%s \n", nameList[j]);
	}
	return 0;
}
