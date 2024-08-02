#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, char c)
{
    if (s->top < MAX - 1)
    {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isMatchingPair(char char1, char char2)
{
    return (char1 == '(' && char2 == ')') ||
           (char1 == '{' && char2 == '}') ||
           (char1 == '[' && char2 == ']');
}

bool areParenthesisBalanced(char exp[])
{
    Stack s;
    initStack(&s);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.top == -1 || !isMatchingPair(pop(&s), exp[i]))
            {
                return false;
            }
        }
    }
    return s.top == -1;
}

int main()
{
    char exp[MAX];
    printf("Enter an expression: ");
    gets(exp);

    if (areParenthesisBalanced(exp))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }

    return 0;
}
