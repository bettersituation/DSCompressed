#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* prev;
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
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->prev = NULL;
	new_head->next = *head_ref;
	if (*head_ref != NULL) {
		(*head_ref)->prev = new_head;
	}
	*head_ref = new_head;
}

void del(struct Node** head_ref, int del_data) {
	struct Node* head = *head_ref;
	struct Node* prev = NULL;
	struct Node* next = NULL;

	while (head != NULL) {
		if (head->data == del_data) {
			prev = head->prev;
			next = head->next;
			free(head);
			if (prev == NULL) {
				next->prev = NULL;
				*head_ref = next;
			}
			if (next == NULL) {
				prev->next = NULL;
			}
			if ((prev != NULL) && (next != NULL)) {
				prev->next = next;
				next->prev = prev;
			}
			break;
		}
		head = head->next;
	}
}

int main(void) {
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	push(&head, 9);
	printList(head);

	del(&head, 4);
	printList(head);

	del(&head, 1);
	printList(head);

	del(&head, 9);
	printList(head);

	return 0;
}