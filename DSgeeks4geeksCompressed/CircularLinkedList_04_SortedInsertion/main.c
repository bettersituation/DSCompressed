#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* tail) {
	struct Node* tmp = tail;
	if (tmp == NULL) {
		return;
	}
	do {
		tmp = tmp->next;
		printf("%d ", tmp->data);
	} while (tmp != tail);
	printf("\n");
}

void sortedInsert(struct Node** tail_ref, int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* next = *tail_ref;
	struct Node* prev = *tail_ref;
	new_node->data = data;
	if (next == NULL) {
		new_node->next = new_node;
		*tail_ref = new_node;
		return;
	}
	next = next->next;
	if (prev->data <= data) {
		prev->next = new_node;
		new_node->next = next;
		*tail_ref = new_node;
		return;
	}
	while (1) {
		if (next->data >= data) {
			prev->next = new_node;
			new_node->next = next;
			return;
		}
		prev = next;
		next = next->next;
	}
}

int main(void) {
	struct Node* tail = NULL;
	sortedInsert(&tail, 1);
	sortedInsert(&tail, 10);
	sortedInsert(&tail, 5);
	sortedInsert(&tail, 15);
	sortedInsert(&tail, 15);
	sortedInsert(&tail, 5);
	sortedInsert(&tail, -3);
	sortedInsert(&tail, -3);
	printList(tail);
	return 0;
}