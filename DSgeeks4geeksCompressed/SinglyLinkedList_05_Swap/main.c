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

void insertHead(struct Node** head_ref, int new_data) {
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
	new_head->data = new_data;
	new_head->next = *head_ref;
	*head_ref = new_head;
}

void swapAtHead(struct Node** head_ref, int d) {
	struct Node* tmp = *head_ref;
	struct Node* tmp1 = (*head_ref)->next;
	struct Node* tmp2;

	while (tmp->next->data != d) {
		tmp = tmp->next;
	}
	tmp2 = tmp;
	(*head_ref)->next = tmp->next->next;
	tmp->next->next = tmp1;
	tmp = *head_ref;
	*head_ref = tmp2;
}

void swap(struct Node** head_ref, int d1, int d2) {
	struct Node* tmp1 = *head_ref;
	struct Node* tmp2 = *head_ref;
	struct Node* tmp3;
	struct Node* tmp4;

	if (tmp1->data == d1) {
		while (tmp2->next->data != d2) {
			tmp2 = tmp2->next;
		}
		if (tmp1 != tmp2) {
			tmp3 = tmp2->next;
			tmp4 = tmp1->next;
			tmp1->next = tmp2->next->next;
			tmp2->next->next = tmp4;
			tmp2->next = tmp1;
			*head_ref = tmp3;
		}
		else {
			tmp3 = tmp2->next;
			tmp1->next = tmp2->next->next;
			tmp3->next = tmp1;
			*head_ref = tmp3;
		}
		return;
	}

	if (tmp1->data == d2) {
		while (tmp2->next->data != d1) {
			tmp2 = tmp2->next;
		}
		if (tmp1 != tmp2) {
			tmp3 = tmp2->next;
			tmp4 = tmp1->next;
			tmp1->next = tmp2->next->next;
			tmp2->next->next = tmp4;
			tmp2->next = tmp1;
			*head_ref = tmp3;
		}
		else {
			tmp3 = tmp2->next;
			tmp1->next = tmp2->next->next;
			tmp3->next = tmp1;
			*head_ref = tmp3;
		}
		return;
	}

	while (tmp1->next->data != d1) {
		tmp1 = tmp1->next;
	}

	while (tmp2->next->data != d2) {
		tmp2 = tmp2->next;
	}

	if (tmp1->next == tmp2) {
		tmp3 = tmp2->next;
		tmp2->next = tmp3->next;
		tmp1->next = tmp3;
		tmp3->next = tmp2;
		return;
	}

	if (tmp2->next == tmp1) {
		tmp3 = tmp1->next;
		tmp1->next = tmp3->next;
		tmp2->next = tmp3;
		tmp3->next = tmp1;
		return;
	}

	tmp3 = tmp2->next->next;
	tmp4 = tmp2->next;

	tmp2->next->next = tmp1->next->next;
	tmp2->next = tmp1->next;
	tmp1->next->next = tmp3;
	tmp1->next = tmp4;
}

int main(void) {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 0;
	head->next = NULL;

	insertHead(&head, 1);
	insertHead(&head, 2);
	insertHead(&head, 3);
	insertHead(&head, 4);
	insertHead(&head, 5);
	insertHead(&head, 6);
	insertHead(&head, 7);
	insertHead(&head, 8);

	printList(head);

	swap(&head, 8, 4);
	printList(head);
}