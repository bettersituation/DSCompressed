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

void push(struct Node** head_ref, int data) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = data;
	head->next = *head_ref;
	*head_ref = head;
}

void reverseK(struct Node** head_ref, int k) {
	struct Node* first = NULL;
	struct Node* prev_first = NULL;
	struct Node* prev = NULL;
	struct Node* curr = *head_ref;
	struct Node* next;
	int count = 1;
	int op = 0;

	if (k == 1) {
		return;
	}

	if (curr == NULL) {
		return;
	}
	if (curr->next == NULL) {
		return;
	}
	
	next = curr->next;
	
	while (1) {
		if (count == 1) {
			first = curr;
			first->next = NULL;
		}
		prev = curr;
		curr = next;
		next = next->next;
		curr->next = prev;
		count++;

		if (op == 0) {
			*head_ref = curr;
		}

		if (count == k) {
			if (op == 0) {
				prev_first = first;
				op = 1;
			}
			else {
				prev_first->next = curr;
				prev_first = first;
			}
			if (next == NULL) {
				break;
			}
			if (next->next == NULL) {
				prev_first->next = next;
				break;
			}
			curr = next;
			next = curr->next;
			count = 1;
		}

		if (next == NULL) {
			if (op == 0) {
				break;
			}
			else {
				prev_first->next = curr;
				break;
			}
		}
	}
}

int main(void) {
	struct Node* head = NULL;
	int k = 8;

	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	push(&head, 10);
	push(&head, 11);
	push(&head, 14);
	printList(head);

	reverseK(&head, k);
	printList(head);

	return 0;
}