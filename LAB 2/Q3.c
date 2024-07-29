#include <stdio.h>

struct Time
{
    int hour;
    int min;
    int sec;
};

struct Time addTime(struct Time t1, struct Time t2)
{
    struct Time t;
    t.sec = t1.sec + t2.sec;
    t.min = t1.min + t2.min + t.sec / 60;
    t.sec = t.sec % 60;
    t.hour = t1.hour + t2.hour + t.min / 60;
    t.min = t.min % 60;
    return t;
}

struct Time diffTime(struct Time t1, struct Time t2)
{
    struct Time t;
    t.sec = t1.sec - t2.sec;
    t.min = t1.min - t2.min;
    t.hour = t1.hour - t2.hour;

    if (t.sec < 0)
    {
        t.sec += 60;
        t.min--;
    }
    if (t.min < 0)
    {
        t.min += 60;
        t.hour--;
    }
    return t;
}

void readTime(struct Time *t)
{
    printf("Enter time (hour minute second): ");
    scanf("%d %d %d", &t->hour, &t->min, &t->sec);
}

void displayTime(struct Time t)
{
    printf("Time: %02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

int main()
{
    struct Time t1, t2, sum, diff;

    printf("Enter first time:\n");
    readTime(&t1);

    printf("Enter second time:\n");
    readTime(&t2);

    sum = addTime(t1, t2);
    diff = diffTime(t1, t2);

    printf("\nSum of times: ");
    displayTime(sum);

    printf("Difference of times: ");
    displayTime(diff);

    return 0;
}
