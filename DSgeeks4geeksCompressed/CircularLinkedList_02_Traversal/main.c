#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct CLL {
	struct Node* tail;
	int count;
};

struct CLL* getList() {
	struct CLL* list = (struct CLL*)malloc(sizeof(struct CLL));
	list->tail = NULL;
	list->count = 0;
	return list;
}

void pushHead(struct CLL** list_ref, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp_node;
	new_node->data = new_data;
	new_node->next = NULL;

	if ((*list_ref)->count == 0) {
		(*list_ref)->tail = new_node;
		new_node->next = new_node;
		((*list_ref)->count)++;
	}
	else {
		tmp_node = (*list_ref)->tail->next;
		(*list_ref)->tail->next = new_node;
		new_node->next = tmp_node;
		(*list_ref)->tail = new_node;
		((*list_ref)->count)++;
	}
}

void printList(struct CLL* list) {
	int c = list->count;
	struct Node* tmp_node = list->tail;
	while (c != 0) {
		tmp_node = tmp_node->next;
		printf("%d ", tmp_node->data);
		c--;
	}
	printf("\n");
}

void printListTravel(struct CLL* list) {
	struct Node* tmp_node = list->tail;
	do {
		tmp_node = tmp_node->next;
		printf("%d ", tmp_node->data);
	} while (tmp_node != list->tail);
	printf("\n");
}

int main(void) {
	struct CLL* list = getList();
	pushHead(&list, 1);
	pushHead(&list, 2);
	pushHead(&list, 3);
	pushHead(&list, 4);
	pushHead(&list, 5);
	printList(list);
	printListTravel(list);
	return 0;
}