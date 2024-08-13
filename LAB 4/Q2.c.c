#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void fastTranspose(Element a[], Element b[]) {
    int row[MAX], Pos[MAX];
    int numCols = a[0].col;
    int numTerms = a[0].value;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0) {
        for (int i = 0; i < numCols; i++) {
            row[i] = 0;
        }
        for (int i = 1; i <= numTerms; i++) {
            row[a[i].col]++;
        }
        Pos[0] = 1;
        for (int i = 1; i < numCols; i++) {
            Pos[i] = Pos[i - 1] + row[i - 1];
        }
        for (int i = 1; i <= numTerms; i++) {
            int j = Pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    Element a[MAX], b[MAX];
    int numTerms;

    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numTerms);
    a[0].value = numTerms;

    printf("Enter the row, column, and value of each non-zero element:\n");
    for (int i = 1; i <= numTerms; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    fastTranspose(a, b);

    printf("The transposed matrix is:\n");
    for (int i = 0; i <= b[0].value; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}
