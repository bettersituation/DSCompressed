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

void headInsert(struct Node** head, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

void midInsert(struct Node** node, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*node)->next;
	(*node)->next = new_node;
}

void midInsertIdx(struct Node** node, int idx, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node = *node;
	int i = 0;
	while (1) {
		if ((idx - 1) == i) {
			break;
		}
		tmp_node = (*node)->next;
		i++;
	}

	new_node->data = new_data;
	new_node->next = tmp_node->next;
	tmp_node->next = new_node;
}

void tailInsert(struct Node** node, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node = *node;
	while (tmp_node->next != NULL) {
		tmp_node = tmp_node->next;
	}
	new_node->data = new_data;
	new_node->next = NULL;

	tmp_node->next = new_node;
}

int main(void) {
	struct Node* l1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* l2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* l3 = (struct Node*)malloc(sizeof(struct Node));

	l1->data = 1;
	l1->next = l2;

	l2->data = 2;
	l2->next = l3;

	l3->data = 3;
	l3->next = NULL;

	headInsert(&l1, 0);
	printList(l1);

	midInsert(&l2, -3);
	printList(l1);

	midInsertIdx(&l1, 2, 10);
	printList(l1);

	tailInsert(&l1, 99);
	printList(l1);

	return 0;
}