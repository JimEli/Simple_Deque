#include "deque.h"

void main(void) {
	int i;
	
	// Create a deque.
	Deque *dq = initDeque();
	if (dq != NULL) {
		// Push some integers onto the deque.
		if (!pushRightDeque(dq, 11))
			puts("Could not push item onto deque!\n");
		if (!pushDeque(dq, 10))
			puts("Could not push item onto deque!\n");
		if (!pushRightDeque(dq, 12))
			puts("Could not push item onto deque!\n");
		if (!pushDeque(dq, 9))
			puts("Could not push item onto deque!\n");
		if (!pushRightDeque(dq, 13))
			puts("Could not push item onto deque!\n");
		if (!pushDeque(dq, 8))
			puts("Could not push item onto deque!\n");
		if (!pushRightDeque(dq, 14))
			puts("Could not push item onto deque!\n");
		if (!pushDeque(dq, 7))
			puts("Could not push item onto deque!\n");

		// Display deque.
		fputs("Deque: ", stdout);
		printDeque(dq);
		printf("\nElements in Deque: %d\n", sizeDeque(dq));

		// Pop integers from deque.
		if (popLeftDeque(dq, &i))
			printf("Popped left = %d\n", i);
		if (popLeftDeque(dq, &i))
			printf("Popped left = %d\n", i);
		if (popLeftDeque(dq, &i))
			printf("Popped left = %d\n", i);
		if (popDeque(dq, &i))
			printf("Popped right = %d\n", i);

		// Display deque.
		fputs("Deque: ", stdout);
		printDeque(dq);
		printf("\nElements in Deque: %d\n", sizeDeque(dq));

		// Destroy deque.
		destroyDeque(dq);
	}

	// Pause for user.
	puts("\nPress Control-C to exit\n");
	while (getchar() != EOF);
}

