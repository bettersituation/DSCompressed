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

struct Node* mergeSorted(struct Node* a, struct Node* b) {
	struct Node head;
	struct Node* tail = &head;

	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	while (1) {
		if (a->data < b->data) {
			tail->next = a;
			tail = tail->next;
			a = a->next;
		}
		else {
			tail->next = b;
			tail = tail->next;
			b = b->next;
		}
		if (a == NULL) {
			tail->next = b;
			return (&head)->next;
		}
		if (b == NULL) {
			tail->next = a;
			return (&head)->next;
		}
	}
}

void splitNode(struct Node** head_ref, struct Node** mid) {
	struct Node* mover = *head_ref;
	while (mover->next != *mid) {
		mover = mover->next;
	}
	mover->next = NULL;
}

struct Node* getMidNode(struct Node* head) {
	struct Node* slow = head;
	struct Node* fast = head;

	if (slow == NULL) {
		return slow;
	}
	slow = slow->next;
	fast = fast->next;

	if (fast == NULL) {
		return slow;
	}

	while ((fast->next != NULL) && (fast->next->next != NULL)) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

struct Node* mergeSorting(struct Node* head) {
	struct Node* mid;

	while (1) {
		mid = getMidNode(head);

		if (mid == NULL) {
			return head;
		}

		splitNode(&head, &mid);
		if ((head->next == NULL) && (mid->next == NULL)) {
			return mergeSorted(head, mid);
		}
		else if (head->next != NULL) {
			return mergeSorted(mergeSorting(head), mid);
		}
		else {
			return mergeSorted(head, mergeSorting(mid));
		}
	}
}

int main(void) {
	struct Node* a = NULL;
	struct Node* b = NULL;
	struct Node* c = NULL;
	struct Node* res;
	struct Node* res2;

	push(&a, 5);
	push(&a, 3);
	push(&a, 1);
	printList(a);

	push(&b, 6);
	push(&b, 4);
	push(&b, 2);
	printList(b);

	res = mergeSorted(a, b);
	printList(res);

	push(&c, 5);
	push(&c, 3);
	push(&c, 1);
	push(&c, 6);
	push(&c, 4);
	push(&c, 2);
	printList(c);

	res2 = mergeSorting(c);
	printList(res2);
}