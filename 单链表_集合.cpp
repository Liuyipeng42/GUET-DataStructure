#ifndef _LINKSET_H_
#define _LINKSET_H_
#include <iostream>
using namespace std;
typedef int DataType;

struct node {
    DataType element;
    struct node *next;
};
typedef struct node *SET;

void insert(DataType datax, SET set) {
    struct node *last = set;
    while (last->next != NULL) {
        last = last->next;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->element = datax;
    new_node->next = NULL;
    last->next = new_node;
}

SET InitSet(int num) {
    SET set;
    set = new struct node;
    set->next = NULL;
    set->element = num;
    int temp;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        insert(temp, set);
    }
    return set;
}

struct node *create_new_node(int element) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

struct node *copySet(SET set) {
    struct node *new_set = create_new_node(0),
                *n_cursor, *cursor = set->next;
    n_cursor = new_set;
    while (cursor != NULL) {
        struct node *new_node = create_new_node(cursor->element);
        n_cursor->next = new_node;
        n_cursor = new_node;
        cursor = cursor->next;
    }
    return new_set;
}

void printSet(SET set) {
    struct node *cursor = set->next;
    while (cursor != NULL) {
        printf("%d ", cursor->element);
        cursor = cursor->next;
    }
}

struct node *del_node(SET set, DataType element) {
    struct node *cursor = set->next, *previous_node = set;
    while (cursor) {
        if (element == cursor->element) {
            previous_node->next = cursor->next;
            set->element--;
        }
        previous_node = cursor;
        cursor = cursor->next;
    }
    return previous_node;
}

SET setUnion(SET setA, SET setB) {
    struct node *new_set = copySet(setB), *A_cursor = setA->next;
    while (A_cursor) {
        del_node(new_set, A_cursor->element)->next = create_new_node(A_cursor->element);
        new_set->element++;
        A_cursor = A_cursor->next;
    }
    return new_set;
}

SET setExcept(SET setA, SET setB) {
    struct node *new_set = copySet(setA), *B_cursor = setB->next;
    while (B_cursor) {
        del_node(new_set, B_cursor->element);
        B_cursor = B_cursor->next;
    }
    return new_set;
}

SET setIntersect(SET setA, SET setB) {
    struct node *new_set = create_new_node(0),
                *A_cursor = setA->next, *B_cursor, *new_set_cursor = new_set;
    while (A_cursor) {
        B_cursor = setB->next;
        while (B_cursor) {
            if (A_cursor->element == B_cursor->element) {
                struct node *new_node = create_new_node(A_cursor->element);
                new_set_cursor->next = new_node;
                new_set_cursor = new_node;
                new_set->element++;
            }
            B_cursor = B_cursor->next;
        }
        A_cursor = A_cursor->next;
    }
    return new_set;
}

/*
  ???????????? setExcept
  ??????????????????????????????setA ??? setB??????
  ???????????????setA???setB????????????
  ????????????????????????????????????
*/

int main(void) {
    int count;
    cin >> count;
    SET setA = InitSet(count);
    cin >> count;
    SET setB = InitSet(count);
    cout << "?????????";
    printSet(setUnion(setA, setB));
    // printf("\nnum : %d", setUnion(setA, setB)->element);
    cout << "\n?????????";
    printSet(setIntersect(setA, setB));
    // printf("\nnum : %d", setIntersect(setA, setB)->element);
    cout << "\n?????????";
    printSet(setExcept(setA, setB));
    printf("\n");
    // printf("\nnum : %d\n", setExcept(setA, setB)->element);
}

#endif

// 5 91 51 2 32 7 4 21 51 2 16
// ?????????21 16 91 51 2 32 7
// ?????????51 2
// ?????????91 32 7 

// 2 1 100 4 16 101 1 6
// ?????????16 101 6 1 100
// ?????????1
// ?????????100