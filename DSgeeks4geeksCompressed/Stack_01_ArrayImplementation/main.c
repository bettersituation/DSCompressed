#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* create(unsigned capacity) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

void push(struct Stack* stack, int data) {
	if (isFull(stack)) {
		printf("overflow\n");
		return;
	}
	stack->array[++stack->top] = data;
}

int pop(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("underflow\n");
		return INT_MIN;
	}
	return stack->array[stack->top--];
}

int peak(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("underflow\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}

int main(void) {
	struct Stack* stack = create(3);
	pop(stack);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	printf("%d\n", peak(stack));
	printf("%d\n", pop(stack));
	return 0;
}