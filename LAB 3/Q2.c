#include <stdio.h>

#define MAX 100

void initStack(int *top)
{
    *top = -1;
}

void push(int *stack, int *top, int value)
{
    if (*top < MAX - 1)
    {
        stack[++(*top)] = value;
    }
}

int pop(int *stack, int *top)
{
    if (*top >= 0)
    {
        return stack[(*top)--];
    }
    return -1;
}

void convertToBase(int number, int base)
{
    int stack[MAX];
    int top;
    initStack(&top);
    while (number > 0)
    {
        push(stack, &top, number % base);
        number /= base;
    }

    while (top >= 0)
    {
        int digit = pop(stack, &top);
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
