#include <stdio.h>

// Function to find length of the string
int stringLength(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void stringConcatenate(char *dest, char *src)
{
    int i = 0, j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

// Function to compare two strings
int stringCompare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to insert a substring
void insertSubstring(char *str, char *sub, int pos)
{
    int strLen = stringLength(str);
    int subLen = stringLength(sub);
    for (int i = strLen - 1; i >= pos; i--)
    {
        str[i + subLen] = str[i];
    }
    for (int i = 0; i < subLen; i++)
    {
        str[pos + i] = sub[i];
    }
}

// Function to delete a substring
void deleteSubstring(char *str, int pos, int len)
{
    int strLen = stringLength(str);
    for (int i = pos; i <= strLen - len; i++)
    {
        str[i] = str[i + len];
    }
}

int main()
{
    char str1[100] = "Hello";
    char str2[100] = "World";
    char sub[100] = "Insert";

    printf("Length of str1: %d\n", stringLength(str1));

    stringConcatenate(str1, str2);
    printf("After concatenation: %s\n", str1);

    int cmpResult = stringCompare("Hello", "World");
    printf("String comparison result: %d\n", cmpResult);

    insertSubstring(str1, sub, 5);
    printf("After inserting substring: %s\n", str1);

    deleteSubstring(str1, 5, stringLength(sub));
    printf("After deleting substring: %s\n", str1);

    return 0;
}
