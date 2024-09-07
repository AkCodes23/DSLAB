#include <stdio.h>
#include <string.h>
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void preToInfix(char* prefix, char infix[][100]) {
    int length = strlen(prefix);
    int top = -1;
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            char op1[100], op2[100];
            strcpy(op1, infix[top--]);
            strcpy(op2, infix[top--]);

            char temp[100];
            sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);

            strcpy(infix[++top], temp);
        } else {
            char operand[2] = {prefix[i], '\0'};
            strcpy(infix[++top], operand);
        }
    }
}
int main() {
    char prefix[30];
    char infix[30][30];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    preToInfix(prefix, infix);
    printf("Infix : %s\n", infix[0]);

    return 0;
}
