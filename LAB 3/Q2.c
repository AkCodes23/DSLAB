#include <stdio.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top < MAX - 1)
    {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->data[(s->top)--];
    }
    return -1;
}

void convertToBase(int number, int base)
{
    Stack s;
    initStack(&s);
    while (number > 0)
    {
        push(&s, number % base);
        number /= base;
    }

    while (s.top >= 0)
    {
        int digit = pop(&s);
        if (digit < 10)
        {
            printf("%d", digit);
        }
        else
        {
            printf("%c", 'A' + digit - 10);
        }
    }
    printf("\n");
}

int main()
{
    int number, base;
    printf("Enter a decimal number: ");
    scanf("%d", &number);
    printf("Enter the base to convert to: ");
    scanf("%d", &base);

    if (base < 2 || base > 36)
    {
        printf("Base should be in the range 2-36\n");
        return 1;
    }

    printf("The number in base %d is: ", base);
    convertToBase(number, base);

    return 0;
}
