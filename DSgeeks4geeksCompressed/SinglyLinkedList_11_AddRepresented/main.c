#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* node(int data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void printList(struct Node* head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

void pull(struct Node** head_ref, int new_data) {
	struct Node* head = *head_ref;
	struct Node* new_tail = node(new_data);
	if (head == NULL) {
		*head_ref = new_tail;
	}
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = new_tail;
}

int listToInt(struct Node* head) {
	double res = 0.0;
	double pos = 0.1;
	if (head == NULL) {
		return res;
	}
	while (head != NULL) {
		res *= 0.1;
		res += head->data;
		pos *= 10;
		head = head->next;
	}
	return (int) pos * res;
}

struct Node* intToList(int d) {
	struct Node* head = node(d % 10);
	while (d > 9) {
		d /= 10;
		pull(&head, d % 10);
	}
	return head;
}

int main(void) {
	struct Node* h1 = node(3);
	struct Node* h2 = node(5);
	int d1;
	int d2;
	struct Node* restore;

	push(&h1, 2);
	push(&h1, 1);
	printList(h1);
	d1 = listToInt(h1);
	printf("%d\n", d1);

	push(&h2, 9);
	push(&h2, 3);
	push(&h2, 2);
	printList(h2);
	d2 = listToInt(h2);
	printf("%d\n", d2);

	printf("%d\n", d1 + d2);

	restore = intToList(d1 + d2);
	printList(restore);
	return 0;
}