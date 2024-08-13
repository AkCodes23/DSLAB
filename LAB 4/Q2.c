#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void fast(Element a[], Element b[]) {
    int row[MAX], Pos[MAX];
    int Cols = a[0].col;
    int num = a[0].value;

    b[0].row = Cols;
    b[0].col = a[0].row;
    b[0].value = num;

    if (num > 0) {
        for (int i = 0; i < Cols; i++) {
            row[i] = 0;
        }
        for (int i = 1; i <= num; i++) {
            row[a[i].col]++;
        }
        Pos[0] = 1;
        for (int i = 1; i < Cols; i++) {
            Pos[i] = Pos[i - 1] + row[i - 1];
        }
        for (int i = 1; i <= num; i++) {
            int j = Pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    Element a[MAX], b[MAX];
    int num;

    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &num);
    a[0].value = num;

    printf("Enter the row, column, and value of each non-zero element:\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    fast(a, b);

    printf("The transposed matrix is:\n");
    for (int i = 0; i <= b[0].value; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}
