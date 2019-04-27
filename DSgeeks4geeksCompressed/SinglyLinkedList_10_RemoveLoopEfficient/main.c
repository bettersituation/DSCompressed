#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* node(int data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
}

void printList(struct Node* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_head;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

struct Node* detectLoop(struct Node* head) {
	struct Node* slow = head;
	struct Node* fast = head;

	if (fast == NULL) {
		return NULL;
	}
	if (fast->next == NULL) {
		return NULL;
	}

	while (1) {
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast) {
			return fast;
		}
		if (fast->next == NULL) {
			return NULL;
		}
		if (fast->next->next == NULL) {
			return NULL;
		}
	}
}

void disconnectLoop(struct Node** head_ref) {
	struct Node* liner = *head_ref;
	struct Node* circular = detectLoop(*head_ref);

	if (circular == NULL) {
		return;
	}
	while (liner->next != circular->next) {
		liner = liner->next;
		circular = circular->next;
	}
	circular->next = NULL;
}

int main(void) {
	struct Node* n1 = node(1);
	struct Node* n2 = node(2);
	struct Node* n3 = node(3);
	struct Node* n4 = node(4);
	struct Node* n5 = node(5);
	struct Node* n6 = node(6);
	struct Node* n7 = node(7);
	struct Node* n8 = node(8);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;

	n8->next = n6;

	disconnectLoop(&n1);
	printList(n1);

	return 0;
}