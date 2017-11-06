#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _DEQUE_H_
#define _DEQUE_H_

struct Node_ {
	int data;
	struct Node_ *node;
};
typedef struct Node_ Node;

struct Deque_ {
	Node *right; // top
	Node *left;  // bottom
};
typedef struct Deque_ Deque;

// Function definitions.
Deque *initDeque(void);
bool pushDeque(Deque *, int);
bool pushRightDeque(Deque *, int);
bool popDeque(Deque *, int *);
bool popLeftDeque(Deque *, int *);
void printDeque(Deque *);
int sizeDeque(Deque *);
void destroyDeque(Deque *);

#endif
