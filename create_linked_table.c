#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int n;
    struct N *next;
} num;

num *create_table(int number);
void output(num *p);

int main() {
    int number;
    scanf("%d", &number);
    output(create_table(number));
}

num *create_table(int number) {
    num *prevp, *courp, *head;
    prevp = (num *)malloc(sizeof(num));
    head = prevp;
    prevp->n = 0;
    prevp->next = NULL;
    int n = 0, data;
    while (n < number) {
        courp = (num *)malloc(sizeof(num));
        scanf("%d", &data);
        courp->n = data;
        courp->next = NULL;
        prevp->next = courp;
        prevp = courp;
        n++;
    }
    return head;
}

void output(num *p) {
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->n);
    }
}