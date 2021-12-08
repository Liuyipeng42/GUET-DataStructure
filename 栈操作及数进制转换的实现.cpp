#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
using namespace std;

typedef int DataType;

struct node {
    DataType element;
    struct node *next;
};

typedef struct node *Node;
typedef struct node *Top;

int isEmpty(Top s) { return (s->next == NULL); }

Top createStack(void) {
    Top stack = (Top)malloc(sizeof(struct node));
    stack->next = NULL;
    return stack;
}

void push(DataType x, Top s) {
    Node new_node = (Node)malloc(sizeof(struct node));
    new_node->element = x;
    new_node->next = s->next;
    s->next = new_node;
}

DataType pop(Top s) {
    if (isEmpty(s) != 1) {
        DataType element = s->next->element;
        s->next = s->next->next;
        return element;
    } else {
        return -1;
    }
}

void convert10to2(int x) {
    Top stack = createStack();
    while (x > 0) {
        push(x%2, stack);
        x = x / 2;
    }
    while (isEmpty(stack) != 1) {
        printf("%d", pop(stack));
    }
}

int main(void) {
    int x;
    cin >> x;
    convert10to2(x);
    printf("\n");
}

// int main() {
//     int num, element;
//     Top stack = createStack();
//     scanf("%d", &num);
//     for (int i = 0; i < num; i++) {
//         scanf("%d", &element);
//         push(element, stack);
//     }
//     while (isEmpty(stack) != 1) {
//         printf("%d\n", pop(stack));
//     }
// }

#endif

// 10
// 1010
// 125
// 1111101