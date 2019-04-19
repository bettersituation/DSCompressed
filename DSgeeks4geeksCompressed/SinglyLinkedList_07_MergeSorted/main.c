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

void insertHead(struct Node** head_ref, int data) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = data;
	head->next = *head_ref;
	*head_ref = head;
}

void insertTail(struct Node** head_ref, int data) {
	struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tmp = *head_ref;
	tail->data = data;
	tail->next = NULL;
	if (tmp == NULL) {
		*head_ref = tail;
		return;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = tail;
}

struct Node* mergeSorted(struct Node** ref1, struct Node** ref2) {
	struct Node* ref1_curr = *ref1;
	struct Node* ref1_next;
	struct Node* ref2_curr = *ref2;
	struct Node* ref2_next;
	struct Node* res = NULL;

	if (ref1_curr == NULL) {
		return *ref2;
	}
	if (ref2_curr == NULL) {
		return *ref1;
	}

	ref1_next = ref1_curr->next;
	ref2_next = ref2_curr->next;

	while (1) {
		if (ref1_curr->data < ref2_curr->data) {
			insertTail(&res, ref1_curr->data);
			if (ref1_next == NULL) {
				while (ref2_curr != NULL) {
					insertTail(&res, ref2_curr->data);
					ref2_curr = ref2_curr->next;
				}
				return res;
			}
			ref1_curr = ref1_next;
			ref1_next = ref1_next->next;
		}
		else {
			insertTail(&res, ref2_curr->data);
			if (ref2_next == NULL) {
				while (ref1_curr != NULL) {
					insertTail(&res, ref1_curr->data);
					ref1_curr = ref1_curr->next;
				}
				return res;
			}
			ref2_curr = ref2_next;
			ref2_next = ref2_next->next;
		}
	}
}

int main(void) {
	struct Node* node1 = NULL;
	struct Node* node2 = NULL;
	struct Node* res;
	
	insertTail(&node1, 7);
	printList(node1);

	insertHead(&node2, 10);
	insertHead(&node2, 8);
	insertHead(&node2, 6);
	insertHead(&node2, 4);
	insertHead(&node2, 2);
	printList(node2);

	res = mergeSorted(&node1, &node2);
	printList(res);
}