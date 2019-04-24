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

void push(struct Node** head_ref, int data) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = data;
	head->next = *head_ref;
	*head_ref = head;
}

struct Node* detectLoop(struct Node** head_ref) {
	struct Node* slow = *head_ref;
	struct Node* fast = *head_ref;
	
	if (slow == NULL) {
		return NULL;
	}
	if (slow->next == NULL) {
		return NULL;
	}
	while (1) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return slow;
		}
		if (fast->next == NULL) {
			return NULL;
		}
		if (fast->next->next == NULL) {
			return NULL;
		}
	}
}

void removeLoop(struct Node** head_ref) {
	struct Node* inloop_node = detectLoop(head_ref);
	struct Node* move_node = inloop_node;
	struct Node* stand_node = *head_ref;
	if (inloop_node == NULL) {
		return;
	}
	while (1) {
		move_node = inloop_node;
		do {
			if (stand_node == move_node->next) {
				move_node->next = NULL;
				return;
			}
			move_node = move_node->next;
		} while (move_node != inloop_node);
		stand_node = stand_node->next;
	}
}

int main(void) {
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n6 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n7 = (struct Node*)malloc(sizeof(struct Node));

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n1;

	//printList(n1);
	removeLoop(&n1);
	printList(n1);

	return 0;
}