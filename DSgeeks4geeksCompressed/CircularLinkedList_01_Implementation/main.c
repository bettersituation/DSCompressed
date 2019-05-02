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

void pushTail(struct CircularLinkedList** list_ref, int new_data) {
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

void pushHead(struct CircularLinkedList** list_ref, int new_data) {
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
		((*list_ref)->count)++;
	}
}

void pushAfter(struct CircularLinkedList** list_ref, int new_data, int before_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node;
	struct Node* after_node;
	new_node->data = new_data;

	if ((*list_ref)->node == NULL) {
		new_node->next = new_node;
		(*list_ref)->node = new_node;
		(*list_ref)->count = 1;
	}
	else {
		tmp_node = (*list_ref)->node;
		while (1) {
			if (tmp_node->data == before_data) {
				break;
			}
			tmp_node = tmp_node->next;
		}
		after_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->next = after_node;
		if (tmp_node == (*list_ref)->node) {
			(*list_ref)->node = new_node;
		}
		((*list_ref)->count)++;
	}
}

void pushBefore(struct CircularLinkedList** list_ref, int new_data, int after_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node;
	struct Node* after_node;
	new_node->data = new_data;

	if ((*list_ref)->node == NULL) {
		new_node->next = new_node;
		(*list_ref)->node = new_node;
		(*list_ref)->count = 1;
	}
	else {
		tmp_node = (*list_ref)->node;
		while (1) {
			if (tmp_node->next->data == after_data) {
				break;
			}
			tmp_node = tmp_node->next;
		}
		after_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->next = after_node;
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
			if (prev_node->next == (*list_ref)->node) {
				(*list_ref)->node = prev_node;
			}
			free(prev_node->next);
			prev_node->next = next_node;
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
	pushTail(&list, 1);
	pushTail(&list, 2);
	pushTail(&list, 3);
	pushTail(&list, 4);
	printList(list);

	pushHead(&list, 0);
	printList(list);

	pushAfter(&list, 1, 0);
	printList(list);

	pushAfter(&list, -5, 4);
	printList(list);

	pushAfter(&list, 3, 2);
	printList(list);

	pushBefore(&list, -1, 0);
	printList(list);

	pushBefore(&list, -2, 3);
	printList(list);

	pushBefore(&list, -10, -5);
	printList(list);

	del(&list, 3);
	printList(list);

	return 0;
}