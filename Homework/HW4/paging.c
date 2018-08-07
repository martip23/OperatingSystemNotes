#include <stdio.h> 	// For IO operations
#include <time.h>	// To seed rand
#include <stdlib.h> // For rand

int faults = 0;

void printMem(int memory[], int numFrames) {
	for (int i = 0; i < numFrames; i++)
		printf("%d ", memory[i]);
	printf("\n");
	faults++;
}

int isLoaded(int ref, int memory[], int numFrames) {
	int found = 0;
	for (int i = 0; i < numFrames; i++) {
		if (ref == memory[i]) {
			found = 1; break;
		}
	}
	return found;
}

int max (int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min (int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main () {
	int refStringLen = -1, numFrames = -1, memory[30], refString[30];

	printf("Enter the length of the reference string (max 30):");
	scanf(" %d", &refStringLen);

	printf("Enter the number of frames to use (max 30):");
	scanf(" %d", &numFrames);

	srand(time(NULL)); 	// Seed random generator

// Set all frames to 0, sting ends at -1
	for (int i = 0; i < numFrames; i++)
		memory[i] = 0;

// Create reference string 
	for (int i = 0; i < refStringLen; i++) {
			int randInt = ((rand() % 5) + 1);
			if (randInt != refString[i - 1])
				refString[i] = randInt;
			else i--;
	}

// Set bit after last item to 0 or NULL.
	if (refStringLen != 30)
		refString[refStringLen] = -1;

// Print out reference string
	printf("\nThe reference string is:\n");
	int i = 0;
	while ((refString[i] != -1) && (i < 30)) {
		printf("%d ", refString[i]);
		i++;
	}
	printf("\n");

// Optimal algorithm
	printf("\n***OPTIMAL ALRORITHM***\n");
	// While there is an empty frame, and reference not in list
	// place a page into it.
	i = 0; // To iterate through frame
	int j = 0; // To iterate through ref string
	for (j = 0; i < numFrames; j++) { 
		if (refString[j] == -1) // If at the end of ref string, break
			break;
		// If the requested page is not in memory, load it
		else if (!isLoaded(refString[j], memory, numFrames)) { 
			memory[i] = refString[j];
			i++;
			printMem(memory, numFrames);
		} // If in memory, just read it and continue
		else {
			printf("%d found in memory.\n", refString[j]);
		}
	}

	while (j < refStringLen) {
		int outVal;
		// If frame is loaded already, print
		if (isLoaded(refString[j], memory, numFrames)) {
			printf("%d found in memory.\n", refString[j]);
		} else { 
		// Begin page replacement algorithm
			// Iterate through frames and see which will be used last
			int indexToReplace = 0;
			int found = 0;
			for (int k = 0; k < numFrames; k++) {
//				printf("j. = %d", i);
				found = 0;
				int frameVal = memory[k];
				// Iterate through ref string to see last call
				for (int l = j; l < refStringLen; l++) {
					if (frameVal == refString[l]) {
						found = 1;
						if (k == 0)
							indexToReplace = l;
						else {
							indexToReplace = max(indexToReplace, l);
						}
						break;
					}
				}
				if (!found) {
					outVal = frameVal;
					break;
				}
			}
			if (found)
				outVal = refString[indexToReplace];
			for (int l = 0; l < numFrames; l++) {
				if (memory[l] == outVal) {
					memory[l] = refString[j];
					break;
				}
			}
//			printf("j = %d ref = %d\n", i, refString[j]);
			printMem(memory, numFrames);
		}
		j++;
	}
	printf("PAGE FAULTS: %d\n", faults);

// LRU algorithm. Use stack.
	printf("\n***LRU algorithm***\n");
	// While there is an empty frame, and reference not in list
	// place a page into it. Ties do not occur in LRU so it is 
	// not addressed.

// Set all frames to 0, sting ends at -1
	for (int i = 0; i < numFrames; i++)
		memory[i] = 0;
// Reset faults counter
	faults = 0;

	i = 0; // To iterate through frame
	j = 0; // To iterate through ref string
	for (j = 0; i < numFrames; j++) { 
		if (refString[j] == -1) // If at the end of ref string, break
			break;
		// If the requested page is not in memory, load it
		else if (!isLoaded(refString[j], memory, numFrames)) { 
			memory[i] = refString[j];
			i++;
			printMem(memory, numFrames);
		} // If in memory, just read it and continue
		else {
			printf("%d found in memory.\n", refString[j]);
		}
	}

	while (j < refStringLen) {
		int indexToReplace;
		int outVal;
		// If frame is loaded already, print
		if (isLoaded(refString[j], memory, numFrames)) {
			printf("%d found in memory.\n", refString[j]);
		} else { 
		// Begin page replacement algorithm
			indexToReplace = 100;
			int frameVal = -1;
			// iterate through each frame
			for (int k = 0; k < numFrames; k++) {
				frameVal = memory[k];
				// Go backwards from index to find least recently used
				// Deterines least recently used by finding most previous
				// call in the reference string and comparing to determine
				// which was called earliest, or minimum position.
				for (int l = (j-1); l >= 0; l--) {
					if (frameVal == refString[l]) {
						indexToReplace = min (indexToReplace, l);
	//					printf("lowestInd: %d l: %d\n", indexToReplace,l);
						break;
					}
				}
			}
			outVal = refString[indexToReplace];
			for (int l = 0; l < numFrames; l++) {
				if (memory[l] == outVal) {
					memory[l] = refString[j];
					break;
				}
			}
			printMem(memory, numFrames);
		}
		j++;
	}
	printf("PAGE FAULTS: %d\n", faults);

	return 0;
}