#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


struct Stack {
	char data;
	struct Stack* prev;
};

int empty(struct Stack* stack) {
	if (stack == NULL) {
		return 1;
	}
	return 0;
}

void push(struct Stack** stack_ref, char data) {
	struct Stack* new_top = (struct Stack*)malloc(sizeof(struct Stack));
	new_top->data = data;
	new_top->prev = *stack_ref;
	*stack_ref = new_top;
}

char pop(struct Stack** stack_ref) {
	if (empty(*stack_ref)) {
		printf("pop underflow error\n");
		return CHAR_MIN;
	}
	struct Stack* top_stack = *stack_ref;
	char top_char = top_stack->data;
	*stack_ref = top_stack->prev;
	free(top_stack);
	return top_char;
}

char peak(struct Stack* stack) {
	if (empty(stack)) {
		printf("peak underflow error\n");
		return CHAR_MIN;
	}
	char top_char = stack->data;
	return top_char;
}

void reverse(char s[]) {
	struct Stack* stack = NULL;
	int n = strlen(s);
	int i;
	for (i = 0; i < n; ++i) {
		push(&stack, s[i]);
	}

	for (i = 0; i < n; ++i) {
		s[i] = pop(&stack);
	}
}


int main(void) {
	char s[] = "sdwefwa234";
	reverse(s);
	printf("%s", s);
}