#include <stdio.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        stack[++top][i] = str[i];
        i++;
    }
    stack[top][i] = '\0';
}

void pop(char *str) {
    int i = 0;
    while (stack[top][i] != '\0') {
        str[i] = stack[top][i];
        i++;
    }
    str[i] = '\0';
    top--;
}

void postfixToInfix(char *postfix) {
    char *e = postfix, operand1[MAX], operand2[MAX], temp[MAX];
    while (*e != '\0') {
        if ((*e >= 'A' && *e <= 'Z') || (*e >= 'a' && *e <= 'z') || (*e >= '0' && *e <= '9')) {
            char operand[2] = {*e, '\0'};
            push(operand);
        } else {
            pop(operand2);
            pop(operand1);
            sprintf(temp, "(%s%c%s)", operand1, *e, operand2);
            push(temp);
        }
        e++;
    }
    printf("Fully parenthesized infix expression: %s\n", stack[top]);
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    postfixToInfix(exp);
    return 0;
}
