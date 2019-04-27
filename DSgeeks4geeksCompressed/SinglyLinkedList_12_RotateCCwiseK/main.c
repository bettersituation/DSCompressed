# include<stdio.h>
# include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* getNode(int data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void push(struct Node** head_ref, int new_data) {
	struct Node* new_head = getNode(new_data);
	new_head->next = *head_ref;
	*head_ref = new_head;
}

void printList(struct Node* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void rotateK(struct Node** head_ref, int k) {
	struct Node* mover = *head_ref;
	struct Node* new_head;
	int count = 0;

	while (count != k-1) {
		mover = mover->next;
		count++;
	}
	new_head = mover->next;
	mover->next = NULL;
	
	mover = new_head;
	while (mover->next != NULL) {
		mover = mover->next;
	}
	mover->next = *head_ref;
	*head_ref = new_head;
}

int main(void) {
	struct Node* node = getNode(6);
	
	push(&node, 5);
	push(&node, 4);
	push(&node, 3);
	push(&node, 2);
	push(&node, 1);
	printList(node);

	rotateK(&node, 3);
	printList(node);

	return 0;
}