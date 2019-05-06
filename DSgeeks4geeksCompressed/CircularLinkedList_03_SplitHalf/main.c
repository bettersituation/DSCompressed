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
		printf("%d", tmp->data);
	} while (tmp != tail);
	printf("\n");
}

struct Node* splitHalf(struct Node** tail_ref) {
	struct Node* slow = *tail_ref;
	struct Node* fast = *tail_ref;
	struct Node* tmp;
	if (slow == NULL) {
		return NULL;
	}
	if (slow->next == slow) {
		*tail_ref = NULL;
		return slow;
	}
	do {
		slow = slow->next;
		fast = fast->next;
		if (fast == *tail_ref) {
			tmp = fast->next;
			fast->next = slow->next;
			slow->next = tmp;
			return slow;
		}
		fast = fast->next;
		if (fast == *tail_ref) {
			tmp = fast->next;
			fast->next = slow->next;
			slow->next = tmp;
			return slow;
		}
	} while (1);
}

int main(void) {
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n6 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* ns;
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n1;

	ns = splitHalf(&n6);
	printList(ns);
	printList(n6);
	return 0;
}