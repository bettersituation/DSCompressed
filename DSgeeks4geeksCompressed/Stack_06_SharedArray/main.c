#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Stack {
	int* data;
	int null_pos;
	int top;
	int move;
};

struct Stack* create(int* arr, int null_pos, int move) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->data = arr;
	stack->null_pos = null_pos;
	stack->top = null_pos;
	stack->move = move;
	
	return stack;
}

int empty(struct Stack* stack) {
	if (stack->null_pos == stack->top) {
		return 1;
	}
	return 0;
}

void push(struct Stack** stack_ref, struct Stack* compared_stack, int data) {
	struct Stack* stack = *stack_ref;
	if (stack->top + stack->move == compared_stack->top) {
		puts("OVERFLOW!!");
		return;
	}
	stack->top += stack->move;
	stack->data[stack->top] = data;
}

int pop(struct Stack** stack_ref) {
	struct Stack* stack = *stack_ref;
	if (empty(stack)) {
		printf("UNDERFLOW!!");
		return INT_MIN;
	}
	int data = stack->data[stack->top];
	stack->top -= stack->move;
	return data;
}

void print_arr(int arr[], int size) {
	int i = 0;
	for (i; i < size; ++i) {
		printf("%d", arr[i]);
	}
}

int main(void) {
	int arr[5] = { 1, 2, 3, 5, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	struct Stack* stack1 = create(arr, -1, 1);
	struct Stack* stack2 = create(arr, size, -1);

	printf("empty %d\n", empty(stack1));
	
	push(&stack1, stack2, 1);
	push(&stack1, stack2, 2);
	push(&stack1, stack2, 3);
	push(&stack2, stack1, -2);
	push(&stack2, stack1, -3);
	printf("good\n");
	push(&stack1, stack2, 4);
	printf("pop %d\n", pop(&stack1));
	push(&stack1, stack2, 5);
	push(&stack2, stack1, -5);
	printf("pop %d\n", pop(&stack2));
	push(&stack1, stack2, 1);

	print_arr(arr, size);
	return 0;
}