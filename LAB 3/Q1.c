#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isPalindrome(char str[]) {
    int len = strlen(str);
    Stack s;
    initStack(&s);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
