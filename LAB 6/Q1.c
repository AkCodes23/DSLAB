#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPrefix(char* exp) {
    char temp[MAX], prefix[MAX];
    int j = 0;

    reverse(exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9')) {
            temp[j++] = exp[i];
        } else if (exp[i] == ')') {
            push(exp[i]);
        } else if (exp[i] == '(') {
            while (stack[top] != ')' && top != -1) {
                temp[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                temp[j++] = pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        temp[j++] = pop();
    }
    temp[j] = '\0';

    reverse(temp);
    strcpy(prefix, temp);

    printf("Prefix Expression: %s\n", prefix);
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    return 0;
}
