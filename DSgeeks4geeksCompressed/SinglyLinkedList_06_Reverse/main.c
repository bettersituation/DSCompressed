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

void insertHead(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

void insertTail(struct Node** head_ref, int new_data) {
	struct Node* new_tail = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp = *head_ref;
	new_tail->data = new_data;
	new_tail->next = NULL;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_tail;
}

void reverse(struct Node** head_ref) {
	struct Node* tail = *head_ref;
	struct Node* prev = *head_ref;
	struct Node* curr = prev->next;
	
	if ((*head_ref)->next == NULL) {
		return;
	}

	while (tail->next != NULL) {
		tail = tail->next;
	}

	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	curr->next = prev;

	while (1) {
		prev = *head_ref;
		curr = prev->next;
		while (curr->next->next != curr) {
			prev = curr;
			curr = curr->next;
		}
		curr->next = prev;
		if (prev == *head_ref) {
			prev->next = NULL;
			break;
		}
	}
	*head_ref = tail;
}

int main(void) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 0;
	head->next = NULL;
	insertTail(&head, 1);
	insertTail(&head, 2);
	insertTail(&head, 3);
	insertTail(&head, 4);
	insertTail(&head, 5);
	insertTail(&head, 6);
	printList(head);

	reverse(&head);
	printList(head);
}