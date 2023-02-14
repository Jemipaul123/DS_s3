#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
}Node;

// function to add two polynomials
struct node* add_polynomials(struct node* phead, struct node* qhead) {
    struct node* rhead = NULL;
    struct node* newnode = NULL;
    struct node* ptr=rhead;struct node* ptr1=phead;struct node* ptr2=qhead;
    while (phead != NULL && qhead != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));

        if (phead->exp == qhead->exp) {
            newnode->coeff = phead->coeff + qhead->coeff;
            newnode->exp = phead->exp;
            newnode->next = NULL;
            phead = phead->next;
            qhead = qhead->next;
        } else if (phead->exp > qhead->exp) {
            newnode->coeff = phead->coeff;
            newnode->exp = phead->exp;
            newnode->next = NULL;
            phead = phead->next;
        } else {
            newnode->coeff = qhead->coeff;
            newnode->exp = qhead->exp;
            newnode->next = NULL;
            qhead = qhead->next;
        }

        if (rhead == NULL) {
            rhead = newnode;
        } else {
            
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }

    while (phead != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->coeff = phead->coeff;
        newnode->exp = phead->exp;
        newnode->next = NULL;

        if (rhead == NULL) {
            rhead = newnode;
        } else {
            
            ptr1->next = newnode;
            ptr1 = ptr1->next;
        }

        phead = phead->next;
    }

    while (qhead != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->coeff = qhead->coeff;
        newnode->exp = qhead->exp;
        newnode->next = NULL;

        if (rhead == NULL) {
            rhead = newnode;
        } else { 
            
            ptr2->next = newnode;
            ptr2 = ptr2->next;
        }

        qhead = qhead->next;
    }

    return rhead;
}

// function to create a new node for a polynomial
struct node* new_node(int coeff, int exp) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}
// function to print a polynomial
void print_polynomial(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        if (head->exp == 0) {
            printf("%d", head->coeff);
        } else if (head->exp == 1) {
            printf("%dx", head->coeff);
        } else {
            printf("%dx^%d", head->coeff, head->exp);
        }

        head = head->next;

        if (head != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
    }
}

// example driver code
int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    int n1, n2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    printf("Enter the terms and coefficients of the first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        struct node* newnode = new_node(coeff, exp);
        if (poly1 == NULL) {
            poly1 = newnode;
        } else {
            struct node* p = poly1;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newnode;
        }
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    printf("Enter the terms and coefficients of the second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        struct node* newnode = new_node(coeff, exp);
        if (poly2 == NULL) {
            poly2 = newnode;
        } else {
            struct node* p = poly2;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newnode;
        }
    }

    printf("Polynomial 1: ");
    print_polynomial(poly1);

    printf("Polynomial 2: ");
    print_polynomial(poly2);

    struct node* result = add_polynomials(poly1, poly2);

    printf("Result: ");
    print_polynomial(result);

    return 0;
}
