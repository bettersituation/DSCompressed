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

struct Node* reverse(struct Node* head, int k) {
	struct Node* curr = head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	int count = 0;

	while ((curr != NULL) && (count < k)) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next != NULL) {
		head->next = reverse(next, k);
	}
	return prev;
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

	printList(head);

	head = reverse(head, 2);
	printList(head);
	
	return 0;
}