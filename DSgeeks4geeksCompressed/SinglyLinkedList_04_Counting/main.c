#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void insertHead(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

int count(struct Node* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

int main(void) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
	head->data = 0;
	head->next = NULL;

	insertHead(&head, 4);
	printf("%d\n", count(head));
	
	insertHead(&head, 1);
	printf("%d", count(head));
}