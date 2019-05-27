#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct Stack {
	char data;
	struct Stack* prev;
};

char empty(struct Stack* stack) {
	if (stack == NULL) {
		return 1;
	}
	return 0;
}

void push(struct Stack** stack_ref, char s) {
	struct Stack* top = (struct Stack*)malloc(sizeof(struct Stack));
	top->data = s;
	top->prev = *stack_ref;
	*stack_ref = top;
}

char pop(struct Stack** stack_ref) {
	if (empty(*stack_ref)) {
		return '\0';
	}

	struct Stack* top = *stack_ref;
	char top_s = top->data;
	*stack_ref = (*stack_ref)->prev;
	free(top);
	return top_s;
}

char isNum(char s) {
	switch (s) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return 1;
		default:
			return 0;
	}
}

char toNum(char s) {
	switch (s) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}

char isOp(char s) {
	switch (s) {
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}

int calcOp(char op, char a, char b) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			printf("/ not permit because character op implementaion");
			return INT_MIN;
	}
}

int postfixCalc(char exp[]) {
	int size = sizeof(exp) / sizeof(exp[0]) * 2;
	int i = 0;
	struct Stack* stack = NULL;

	char a;
	char b;
	char c;
	for (i; i < size; ++i) {
		if (isNum(exp[i])) {
			push(&stack, toNum(exp[i]));
		}
		else if (isOp(exp[i])) {
			b = pop(&stack);
			a = pop(&stack);
			c = calcOp(exp[i], a, b);
			push(&stack, c);
		}
		else if (exp[i] == '\0') {
			c = pop(&stack);
		}
	}
	if (empty(stack)) {
		return c;
	}
	printf("error");
	return INT_MIN;
}

int main(void) {
	char exp[] = "231*+9-";
	int c = postfixCalc(exp);
	printf("%d", c);
	return 0;
}