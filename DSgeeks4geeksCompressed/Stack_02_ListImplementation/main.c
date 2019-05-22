#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stackNode {
	int data;
	struct stackNode* next;
};

struct stackNode* new_node(int data) {
	struct stackNode* node = (struct stackNode*)malloc(sizeof(struct stackNode));
	node->data = data;
	node->next = NULL;
	return node;
}

int isEmpty(struct stackNode* root) {
	return !root;
}

void push(struct stackNode** root_ref, int data) {
	struct stackNode* node = new_node(data);
	node->next = *root_ref;
	*root_ref = node;
}

int pop(struct stackNode** root_ref) {
	struct stackNode* root = *root_ref;
	int pop_data;
	if (isEmpty(root)) {
		printf("underflow\n");
		return INT_MIN;
	}
	pop_data = root->data;
	*root_ref = root->next;
	free(root);
	return pop_data;
}

int peak(struct stackNode** root_ref) {
	if (isEmpty(*root_ref)) {
		printf("underflow\n");
		return INT_MIN;
	}
	return (*root_ref)->data;
}

int main(void) {
	struct Node* root = NULL;
	pop(&root);
	push(&root, 1);
	push(&root, 2);
	push(&root, 3);
	printf("%d ", peak(&root));
	printf("%d ", pop(&root));
	printf("%d ", pop(&root));
	printf("%d ", pop(&root));
	printf("%d ", pop(&root));
	return 0;
}