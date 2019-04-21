#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = new_data;
	head->next = *head_ref;
	*head_ref = head;
}

struct Node* mergeSorted(struct Node* a, struct Node* b) {
	struct Node dummy;
	struct Node *tail = &dummy;

	dummy.next = NULL;
	while (1) {
		if (a == NULL) {
			tail->next = b;
			break;
		}
		if (b == NULL) {
			tail->next = a;
			break;
		}
		if (a->data < b->data) {
			tail->next = a;
			tail = tail->next;
			a = a->next;
		}
		else {
			tail->next = b;
			tail = tail->next;
			b = b->next;
		}
	}
	return (&dummy)->next;
}

int main(void) {
	struct Node* a = NULL;
	struct Node* b = NULL;
	struct Node* res = NULL;

	push(&a, 6);
	push(&a, 4);
	push(&a, 2);
	printList(a);

	push(&b, 6);
	push(&b, 5);
	push(&b, 3);
	push(&b, 1);
	printList(b);

	res = mergeSorted(a, b);
	printList(res);
}