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

int evaluatePrefix(char* exp) {
    int n = 0;
    while (exp[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        if (exp[i] >= '0' && exp[i] <= '9')
            push(exp[i] - '0');
        else {
            int o1 = pop();
            int o2 = pop();
            switch (exp[i]) {
                case '+': push(o1 + o2); break;
                case '-': push(o1 - o2); break;
                case '*': push(o1 * o2); break;
                case '/': push(o1 / o2); break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePrefix(exp));
    return 0;
}
