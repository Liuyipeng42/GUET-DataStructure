#ifndef _LAB1_H_
#define _LAB1_H_
#include <stdio.h>
#include <iostream>

using namespace std;

struct node {
    int exp;
    int coef;
    struct node *next;
};

typedef struct node *PNODE;

void printPoly(PNODE poly) {
    struct node *cursor = poly;
    int coef, exp, first = 1;
    while (cursor->next) {
        cursor = cursor->next;
        coef = cursor->coef;
        exp = cursor->exp;
        if (coef < 0 || first == 1) {
            printf("%dx^%d", cursor->coef, cursor->exp);
            first = 0;
        } else if (coef > 0) {
            printf("+%dx^%d", cursor->coef, cursor->exp);
        }
    }
}

struct node *create_link() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->coef = 0;
    head->exp = 0;
    head->next = NULL;
    return head;
}

struct node *create_new_node(int coef, int exp) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

PNODE createPoly(void) {
    struct node *head = create_link(), *last_node;
    last_node = head;
    int coef = 1, exp;
    while (coef) {
        scanf("%d %d", &coef, &exp);
        // if (coef == 0) break;
        struct node *new_node = create_new_node(coef, exp);
        last_node->next = new_node;
        last_node = new_node;
    }
    return head;
}

void insert_node(PNODE poly, int coef, int exp) {
    struct node *cursor = poly, *last_node = poly;
    if (cursor->next == NULL) {
        struct node *new_node = create_new_node(coef, exp);
        cursor->next = new_node;
        return;
    }
    cursor = cursor->next;

    while (cursor->next != NULL && cursor->exp < exp) {
        last_node = cursor;
        cursor = cursor->next;
    }

    if (cursor->exp == exp) {
        cursor->coef += coef;
    } else {
        struct node *new_node = create_new_node(coef, exp);
        if (cursor->exp > exp) {
            new_node->next = cursor;
            last_node->next = new_node;
        } else if (cursor->exp < exp) {
            cursor->next = new_node;
        }
    }
}

PNODE addPoly(PNODE left_poly, PNODE right_poly) {
    struct node *l_cursor = left_poly;
    struct node *new_poly = create_link();
    while (l_cursor->next) {
        l_cursor = l_cursor->next;
        insert_node(new_poly, l_cursor->coef, l_cursor->exp);
    }

    struct node *r_cursor = right_poly;
    while (r_cursor->next) {
        r_cursor = r_cursor->next;
        insert_node(new_poly, r_cursor->coef, r_cursor->exp);
    }
    return new_poly;
}

int main(void) {
    PNODE polyAddLeft, polyAddRight, polyAddResult;

    polyAddLeft = createPoly();

    polyAddRight = createPoly();

    polyAddResult = addPoly(polyAddLeft, polyAddRight);
    printPoly(polyAddResult);
    printf("\n");
}

#endif

// 5 0 2 1 3 5 -2 7 0 0 12 1 2 7 13 15 0 0
// 5x^0+14x^1+3x^5+13x^15

// 6 -1 5 0 7 9 0 0 -15 -2 9 9 18 12 0 0
// -15x^-2+6x^-1+5x^0+16x^9+18x^12