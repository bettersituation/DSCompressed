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

void pushHead(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->prev = NULL;
	new_head->next = *head_ref;
	if (*head_ref != NULL) {
		(*head_ref)->prev = new_head;
	}
	*head_ref = new_head;
}

void pushTail(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node = *head_ref;
	new_node->data = new_data;

	if (tmp_node == NULL) {
		new_node->next = NULL;
		new_node->prev = NULL;
		*head_ref = new_node;
	}

	while (tmp_node->next != NULL) {
		tmp_node = tmp_node->next;
	}
	tmp_node->next = new_node;
	new_node->prev = tmp_node;
	new_node->next = NULL;
}

void pushBefore(struct Node** head_ref, int new_data, int after_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node = *head_ref;
	struct Node* after_node;
	new_node->data = new_data;

	while (tmp_node->data != after_data) {
		tmp_node = tmp_node->next;
	}
	after_node = tmp_node;
	tmp_node = tmp_node->prev;
	if (tmp_node == NULL) {
		new_node->prev = tmp_node;
		new_node->next = after_node;
		after_node->prev = new_node;
		*head_ref = new_node;
	}
	else {
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
		new_node->next = after_node;
		after_node->prev = new_node;
	}
}

void pushAfter(struct Node** head_ref, int new_data, int before_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node = *head_ref;
	struct Node* after_node;
	new_node->data = new_data;

	while (tmp_node->data != before_data) {
		tmp_node = tmp_node->next;
	}
	after_node = tmp_node->next;
	if (after_node == NULL) {
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
		new_node->next = after_node;
	}
	else {
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
		new_node->next = after_node;
		after_node->prev = new_node;
	}
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
	pushHead(&head, 1);
	pushHead(&head, 2);
	pushHead(&head, 3);
	pushHead(&head, 4);
	pushHead(&head, 5);
	pushHead(&head, 6);
	pushHead(&head, 7);
	pushHead(&head, 8);
	pushHead(&head, 9);
	printList(head);

	pushTail(&head, 10);
	del(&head, 4);
	printList(head);

	pushBefore(&head, -1, 9);
	pushBefore(&head, 11, 5);
	pushBefore(&head, 12, 10);
	del(&head, 1);
	printList(head);

	pushAfter(&head, -2, -1);
	pushAfter(&head, -12, 10);
	pushAfter(&head, 22, 3);
	del(&head, 9);
	printList(head);

	return 0;
}