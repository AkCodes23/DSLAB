#include <stdio.h>

#define MAX 100

int stack_prec(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int input_prec(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 4;
        case '(':
            return 5;
        default:
            return 0;
    }
}

int is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void infix_to_postfix(char* expression, char* postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (is_operand(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && stack_prec(stack[top]) >= input_prec(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
}

int main() {
    char expression[MAX], postfix[MAX];
    int i;

    printf("Enter an infix expression: ");
    i = 0;
    while ((expression[i++] = getchar()) != '\n');
    expression[i-1] = '\0';

    infix_to_postfix(expression, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
