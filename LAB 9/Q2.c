#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* link;
};

void create_node(int coeff, int pow, struct Node** temp) {
    struct Node* r, * z;
    z = *temp;
    if (z == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = coeff;
        r->pow = pow;
        *temp = r;
        r->link = (struct Node*)malloc(sizeof(struct Node));
        r = r->link;
        r->link = NULL;
    } else {
        r->coeff = coeff;
        r->pow = pow;
        r->link = (struct Node*)malloc(sizeof(struct Node));
        r = r->link;
        r->link = NULL;
    }
}

void polyadd(struct Node* poly1, struct Node* poly2, struct Node* poly) {
    while (poly1->link && poly2->link) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        } else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        } else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        poly->link = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->link;
        poly->link = NULL;
    }
    while (poly1->link || poly2->link) {
        if (poly1->link) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }
        if (poly2->link) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        }
        poly->link = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->link;
        poly->link = NULL;
    }
}

void show(struct Node* node) {
    while (node->link != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->link;
        if (node->coeff >= 0) {
            if (node->link != NULL)
                printf("+");
        }
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    int n, coeff, pow;

    printf("Enter number of terms for 1st polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        create_node(coeff, pow, &poly1);
    }

    printf("Enter number of terms for 2nd polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        create_node(coeff, pow, &poly2);
    }

    poly = (struct Node*)malloc(sizeof(struct Node));
    polyadd(poly1, poly2, poly);

    printf("Added polynomial: ");
    show(poly);

    return 0;
}
