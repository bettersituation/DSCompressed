/*
This is somewhat confusing.
It would be good to set more considerable priority by split operator only.
*/


#include <stdio.h>
#include <stdlib.h>

struct Stack {
	char s;
	struct Stack* prev;
};

char empty(struct Stack* stack) {
	if (!stack) {
		return 1;
	}
	return 0;
}

void push(struct Stack** stack_ref, char s) {
	struct Stack* new_top = (struct Stack*)malloc(sizeof(struct Stack));
	new_top->s = s;
	new_top->prev = *stack_ref;
	*stack_ref = new_top;
}

char get(struct Stack** stack_ref) {
	struct Stack* top = *stack_ref;
	char s;
	if (empty(*stack_ref)) {
		return '\0';
	}
	s = top->s;
	*stack_ref = top->prev;
	free(top);
	return s;
}

void printStack(struct Stack* stack) {
	while (!empty(stack)) {
		printf("%c", get(&stack));
	}
}

char priority(char s) {
	if (s == ')') {
		return 4;
	}
	if (s == '(') {
		return 3;
	}
	if (s == '*' || s == '/') {
		return 2;
	}
	if (s == '+' || s == '-') {
		return 1;
	}
	if (s == '\0') {
		return -1;
	}
	else {
		return 0;
	}
}

void infixToPostfix(char form[], int size) {
	struct Stack* stack = NULL;
	char cur;
	char prev;
	char cp;
	char pp;
	int i = 0;
	for (i; i < size; ++i) {
		cur = form[i];
		cp = priority(cur);
		prev = get(&stack);
		pp = priority(prev);
		if (cp == 0) {
			if (pp != -1)
				push(&stack, prev);
			printf("%c", cur);
		}
		else if (cp == 1) {
			if (pp == 2) {
				printf("%c", prev);
				while (1) {
					prev = get(&stack);
					pp = priority(prev);
					if (pp != 3)
						printf("%c", prev);
					else
						push(&stack, prev);
						break;
				}
			}
			else if (pp != -1)
				push(&stack, prev);
			push(&stack, cur);
		}
		else if (cp == 2) {
			if (pp != -1)
				push(&stack, prev);
			push(&stack, cur);
		}
		else if (cp == 3) {
			if (pp != -1)
				push(&stack, prev);
			push(&stack, cur);
		}
		else if (cp == 4) {
			if (pp != -1)
				printf("%c", prev);
			while (1) {
				prev = get(&stack);
				pp = priority(prev);
				if (pp != 3)
					printf("%c", prev);
				else
					break;
			}
		}
		else if (cp == -1) {
			if (pp != -1)
				push(&stack, prev);
		}
	}
	printStack(stack);
}

int main(void) {
	char form[] = "a+b*c-((d+e)*g+h)/(i-j*(k+l/m))";
	int size = sizeof(form) / sizeof(form[0]);
	infixToPostfix(form, size);
	return 0;
}