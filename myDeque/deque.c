#include "deque.h"

// Initialize elements of structure.
Deque *initDeque(void) {
	Deque *d = (Deque *)malloc(sizeof(Deque));
	if (d == NULL)
		return NULL;

	d->right = d->left = NULL;
	return d;
}

// Add item at begining of deque.
bool pushDeque(Deque *d, int item) {
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
		return false;
	temp->data = item;
	temp->node = NULL;

	if (d->right == NULL)
		d->right = d->left = temp;
	else {
		temp->node = d->right;
		d->right = temp;
	}

	return true;
}

// Delete item from end of deque.
bool popDeque(Deque *d, int *item) {
	Node *temp = d->right;
	if (d->left == NULL) 
		return false;
	else {
		Node *rleft = NULL;

		while (temp != d->left) {
			rleft = temp;
			temp = temp->node;
		}
		Node *q = d->left;
		*item = q->data;
		free(q);
		d->left = rleft;
		d->left->node = NULL;
		if (d->left == NULL)
			d->right = NULL;
		return true;
	}
}

// Add item at the end of deque.
bool pushRightDeque(Deque *d, int item) {
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
		return false;
	temp->data = item;
	temp->node = NULL;

	if (d->right == NULL)
		d->right = temp;
	else
		d->left->node = temp;
	d->left = temp;

	return true;
}

// Delete item from begining of deque.
bool popLeftDeque(Deque *d, int *item) {
	Node *temp = d->right;

	if (temp == NULL) 
		return false;
	else {
		temp = d->right;
		*item = temp->data;
		d->right = temp->node;
		free(temp);

		if (temp == NULL)
			d->left = NULL;
		return true;
	}
}

// Prints contents of deque.
void printDeque(Deque *d) {
	Node *temp = d->right;

	while (temp != NULL) {
		if (temp->node == NULL) 
			printf("%d ", temp->data);
		else
			printf("%d ", temp->data);
		temp = temp->node;
	}
}

// Count the number of items in deque.
int sizeDeque(Deque *d) {
	int count = 0;
	Node *temp = d->right;

	while (temp != NULL) {
		temp = temp->node;
		count++;
	}
	return count;
}

// Delete deque.
void destroyDeque(Deque *d) {
	if (d->right == NULL)
		return;

	while (d->right != NULL) {
		Node *temp = d->right;
		d->right = d->right->node;
		free(temp);
	}

	free(d);
}
