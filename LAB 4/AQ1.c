#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void transposeSparseMatrix(Element a[], Element b[]) {
    int numTerms = a[0].value;
    int numCols = a[0].col;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    int k = 1;
    for (int i = 0; i < numCols; i++) {
        for (int j = 1; j <= numTerms; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

int main() {
    Element a[MAX], b[MAX];
    int num, totalElements;

    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    totalElements = a[0].row * a[0].col;

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &num);
    a[0].value = num;

    if (num > totalElements / 2) {
        printf("Not a sparse matrix\n");
        return 0;
    }

    printf("Enter the row, column, and value of each non-zero element:\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }


    printf("The original matrix is:\n");
    for (int i = 0; i < a[0].row; i++) {
        for (int j = 0; j < a[0].col; j++) {
            int found = 0;
            for (int k = 1; k <= num; k++) {
                if (a[k].row == i && a[k].col == j) {
                    printf("%d ", a[k].value);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }


    transposeSparseMatrix(a, b);


    printf("The transposed matrix is:\n");
    for (int i = 0; i < b[0].row; i++) {
        for (int j = 0; j < b[0].col; j++) {
            int found = 0;
            for (int k = 1; k <= b[0].value; k++) {
                if (b[k].row == i && b[k].col == j) {
                    printf("%d ", b[k].value);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
