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
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

void reverse(struct Node** head_ref) {
	struct Node* prev = NULL;
	struct Node* curr = *head_ref;
	struct Node* next;

	if (curr == NULL) {
		return;
	}
	while (curr->next != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
	*head_ref = curr;
}

int main(void) {
	struct Node* head = NULL;
	
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	printList(head);

	reverse(&head);
	printList(head);
	return 0;
}