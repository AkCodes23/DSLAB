#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    top++;
    int i = 0;
    while (str[i] != '\0') {
        stack[top][i] = str[i];
        i++;
    }
    stack[top][i] = '\0';
}

char* pop() {
    return stack[top--];
}

void prefixToPostfix(char* exp) {
    int n = 0;
    while (exp[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        if (exp[i] >= 'a' && exp[i] <= 'z') {
            char op[2] = {exp[i], '\0'};
            push(op);
        } else {
            char* o1 = pop();
            char* o2 = pop();
            char temp[MAX];
            int j = 0;
            int k = 0;
            while (o1[k] != '\0') temp[j++] = o1[k++];
            k = 0;
            while (o2[k] != '\0') temp[j++] = o2[k++];
            temp[j++] = exp[i];
            temp[j] = '\0';
            push(temp);
        }
    }
    printf("Postfix Expression: %s\n", pop());
}

int main() {
    char exp[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    prefixToPostfix(exp);
    return 0;
}
