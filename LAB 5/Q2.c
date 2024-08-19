#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char *postfix) {
    char *e = postfix;
    int n1, n2, num;
    while (*e != '\0') {
        if (*e >= '0' && *e <= '9') {
            num = *e - '0';  // Convert char to int
            push(num);
        } else {
            n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+':
                    push(n2 + n1);
                    break;
                case '-':
                    push(n2 - n1);
                    break;
                case '*':
                    push(n2 * n1);
                    break;
                case '/':
                    push(n2 / n1);
                    break;
            }
        }
        e++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result of evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}
