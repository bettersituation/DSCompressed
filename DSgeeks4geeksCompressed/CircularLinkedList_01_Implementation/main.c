#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct CircularLinkedList {
	struct Node* node;
	int count;
};

struct CircularLinkedList* getCircularLinkedList(void) {
	struct CircularLinkedList* list = (struct CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));
	list->node = NULL;
	list->count = 0;
	return list;
}

void push(struct CircularLinkedList** list_ref, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node;
	new_node->data = new_data;

	if ((*list_ref)->node == NULL) {
		new_node->next = new_node;
		(*list_ref)->node = new_node;
		(*list_ref)->count = 1;
	}
	else {
		tmp_node = (*list_ref)->node->next;
		(*list_ref)->node->next = new_node;
		new_node->next = tmp_node;
		(*list_ref)->node = new_node;
		((*list_ref)->count)++;
	}
}

void del(struct CircularLinkedList** list_ref, int del_data) {
	struct Node* prev_node = (*list_ref)->node;
	struct Node* next_node = NULL;
	int c = (*list_ref)->count;

	while (c != 0) {
		if (prev_node->next->data == del_data) {
			next_node = prev_node->next->next;
			free(prev_node->next);
			prev_node->next = next_node;
			(*list_ref)->node = prev_node;
			((*list_ref)->count)--;
			break;
		}
		prev_node = prev_node->next;
		c--;
	}
}

void printList(struct CircularLinkedList* list) {
	struct Node* loop_node = list->node;
	int c = list->count;
	while (c != 0) {
		loop_node = loop_node->next;
		printf("%d ", loop_node->data);
		c--;
	}
	printf("\n");
}

int main(void) {
	struct CircularLinkedList* list = getCircularLinkedList();
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 4);
	printList(list);

	del(&list, 4);
	printList(list);

	push(&list, 4);
	push(&list, 5);
	printList(list);

	del(&list, 3);
	printList(list);

	return 0;
}