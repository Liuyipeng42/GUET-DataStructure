#include <stdio.h>
#include <stdlib.h>

struct node {
    //链表结点类型，包含一个存放整型数据的 data
    //成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};

//第一关代码
struct node *createRlist() {
    //函数功能：创建一个有一个节点的空循环链表，返回值为头指针
    struct node *head_node = (struct node *) malloc(sizeof(struct node));
    head_node->data = -1;
    head_node->next = head_node;
    return head_node;
}

void printRlist(struct node *list) {
    //从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素空一格
    struct node *now = list->next->next;
    while (now != list->next) {
        printf("%d ", now->data);
        now = now->next;
    }
}


void insertOrder(struct node *list, int insData) {
    //在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序。
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = insData;
    struct node *now = list->next->next, *last = list->next;
    while (now != list && now->data < insData) {
        last = now;
        now = now->next;
    }
    if (now == list && now->data < insData) {
        new_node->data = list->data;
        list->data = insData;
        last->next = new_node;
        new_node->next = now;
    } else {
        last->next = new_node;
        new_node->next = now;
    }
}

int deleteData(struct node *list, int delData) {
    //在单向递增有序循环链表（表头指针list）中删除所有值为delData的结点,返回值为删除结点的个数
    struct node *now = list->next->next, *last = list->next, *l_last=list;
    int count = 0;
    while (now != list) {
        if (now->data == delData) {
            last->next = now->next;
            count++;
        }
        if(now->next == list)
            l_last = last;
        last = now;
        now = now->next;
    }
    if (now != list && now->data == delData) {
        now->data = last->data;
        l_last->next = list;
        count++;
    }
    return count;
}

int destroyRlist(struct node *list) {
    //从第一个结点开始释放循环链表各结点占用的空间,返回值为最后一个结点的值
    struct node *now = list->next->next, *del_node;
    int last_data = 0;
    while (now != list) {
        del_node = now;
        now = now->next;
        free(del_node);
    }
    last_data = list->data;
    free(list);
    return last_data;
}

// 6 5 2 1 2 2 7 2
// 1 2 2 2 5 7
// 3
// 7
// 1.与一般链表相比，单循环链表的尾结点指针指向头结点（下图中绿色标记的为链表头结点结点）。
// 2.为了访问方便第一个结点和尾结点，将头指针指向尾结点。如下图所示。

int main() {
    struct node *head = createRlist();
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf(" %d", &data);
        insertOrder(head, data);
    }
    printRlist(head);
    scanf("%d", &data);
    printf("\n%d ", deleteData(head, data));

    printf("\n%d ", destroyRlist(head));

    return 0;
}

