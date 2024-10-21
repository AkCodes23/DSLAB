#include <stdio.h>
#include <string.h>
#define MAX 1000

// Function to add two large numbers
void addLargeNumbers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, sum;
    int i = len1 - 1, j = len2 - 1, k = 0;
    char temp[MAX];

    // Add digits from both numbers starting from the end
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        sum = digit1 + digit2 + carry;
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Reverse the result to get the final answer
    for (int x = 0; x < k; x++)
        result[x] = temp[k - x - 1];
    result[k] = '\0';
}

// Main function
int main() {
    char num1[MAX], num2[MAX], result[MAX];

    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2, result);

    printf("Sum: %s\n", result);

    return 0;
}
