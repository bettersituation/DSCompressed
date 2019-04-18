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

void deleteHead(struct Node** head_p) {
	struct Node* tmp = *head_p;
	*head_p = tmp->next;
	free(tmp);
}

void deleteTail(struct Node** head_p) {
	struct Node* tmp = *head_p;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}

	free(tmp->next);
	tmp->next = NULL;
}

void deleteIdx(struct Node** head_p, int idx) {
	int i = 0;
	struct Node* tmp = *head_p;
	struct Node* tmp2;
	while (i < idx - 1) {
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->next->next;
	free(tmp->next);
	tmp->next = tmp2;
}

int main(void) {
	struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* head3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* head4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* head5 = (struct Node*)malloc(sizeof(struct Node));

	head1->data = 1;
	head1->next = head2;

	head2->data = 2;
	head2->next = head3;

	head3->data = 3;
	head3->next = head4;

	head4->data = 4;
	head4->next = head5;

	head5->data = 5;
	head5->next = NULL;

	printList(head1);

	deleteHead(&head1);
	printList(head1);

	deleteTail(&head1);
	printList(head1);

	deleteIdx(&head1, 1);
	printList(head1);

	return 0;
}