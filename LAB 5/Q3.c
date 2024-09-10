#include <stdio.h>

#define MAX 100

char* stack[MAX];
int top = -1;

void push(char* value) {
    stack[++top] = value;
}

char* pop() {
    if (top == -1) {
        return NULL;
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

char* postfixToInfix(char* postfix) {
    char temp[MAX][MAX];
    int len = 0;

    while (postfix[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            temp[i][0] = c;
            temp[i][1] = '\0';
            push(temp[i]);
        } else if (isOperator(c)) {
            char* operand2 = pop();
            char* operand1 = pop();
            int j = 0;
            temp[i][j++] = '(';
            for (int k = 0; operand1[k] != '\0'; k++, j++) {
                temp[i][j] = operand1[k];
            }
            temp[i][j++] = c;
            for (int k = 0; operand2[k] != '\0'; k++, j++) {
                temp[i][j] = operand2[k];
            }
            temp[i][j++] = ')';
            temp[i][j] = '\0';
            push(temp[i]);
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    char* infix = postfixToInfix(postfix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
