#include <stdio.h> // For I/O operations
#include <pthread.h> // For thread operations
#include <unistd.h> // For sleep

#define ITEMS_AVAILABLE 1000

// Global variable to store shirts left
int shirtsLeft = ITEMS_AVAILABLE;
int shirtsTaken = 0;


void *salesmanA() {
	while (shirtsLeft > 0) {
		// Fraction of pile this salesperson takes
		int DIVIDE_BY = 3;
		char SALESMAN_ID = 'A';
		// Ceiling divison
		int shirtCount = (shirtsLeft + DIVIDE_BY - 1) / DIVIDE_BY;
		shirtsTaken += shirtCount;
		printf("Salesman %c took %d shirts.\n", SALESMAN_ID, shirtCount);
		shirtsLeft -= shirtCount;
//		sleep(1);
	}
}

void *salesmanB() {
	while (shirtsLeft > 0) {
		// Fraction of pile this salesperson takes
		int DIVIDE_BY = 4;
		char SALESMAN_ID = 'B';
		// Ceiling divison
		int shirtCount = (shirtsLeft + DIVIDE_BY - 1) / DIVIDE_BY;
		shirtsTaken += shirtCount;
		printf("Salesman %c took %d shirts.\n", SALESMAN_ID, shirtCount);
		shirtsLeft -= shirtCount;
//		sleep(1);
	}
}

void *salesmanC() {
	while (shirtsLeft > 0) {
		// Fraction of pile this salesperson takes
		int DIVIDE_BY = 5;
		char SALESMAN_ID = 'C';
		// Ceiling divison
		int shirtCount = (shirtsLeft + DIVIDE_BY - 1) / DIVIDE_BY;
		shirtsTaken += shirtCount;
		printf("Salesman %c took %d shirts.\n", SALESMAN_ID, shirtCount);
		shirtsLeft -= shirtCount;
//		sleep(1);
	}
}

int main () {

	printf("Starting with %d shirts\n", ITEMS_AVAILABLE);
	pthread_t threadA, threadB, threadC;

//	pthread_setconcurrency(3);

	pthread_create(&threadA, NULL, salesmanA, NULL);
	pthread_create(&threadB, NULL, salesmanB, NULL);
	pthread_create(&threadC, NULL, salesmanC, NULL);

	pthread_join(threadA, NULL);
	pthread_join(threadB, NULL);
	pthread_join(threadC, NULL);

	printf("\nTook %d shirts.\n", shirtsTaken);
//	printf("\n%d shirts left.\n", shirtsLeft);

	return 0;
}
