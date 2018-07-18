#include <stdio.h>

int main() {
	
	const int MAX_NAMES = 12;
	const int MAX_CHAR = 20;
	char nameList[MAX_NAMES][MAX_CHAR];
	char sortedList[MAX_NAMES][MAX_CHAR];
	
	int i = 0;
	while (!feof(stdin)) {
		scanf(" %s", name[i]);
		i++;
	}
	putc('\n', stdout);

	if (i == 1) 
		printf("%s UNSORTED", name[0]);
	else {
		char smallestWord[20];
		for (int j = 0; j < (i - 1); j++) {
			for (int k = (j + 1); k < (i - 1); k++) {
				for (int l = 0; l < MAX_CHAR; l++) {
					bool leftLowerCase = false;
					bool rightLowerCase = false;
					if (nameList[j][l] > 96){
						nameList[j][l] -= 90;
						leftLowerCase = true;
					}
					if (nameList[k][l] > 96){
						nameList[j][l] -= 90;
						rightLowerCase = true;
					}
				}
			}
		}
	}
	for(int j = 0; j < (i-1); j++) {
		printf("%s SORTED\n", sortedList[j]);
	}
	putc('\n', stdout);
	return 0;
}