#include <stdio.h>
#include <stdlib.h>
struct node {
    //链表结点类型，包含一个存放整型数据的 data 成员，和指向前驱和后继结点的指针
    int data;
    struct node *llink, *rlink;
};

struct Hnode {
    //双向链表头结点,有两个指针成员，分别指向双向链表的第一个结点和最后一个结点
    struct node *head, *tail;
};

struct Hnode *createDlist() {
    //函数功能：创建一个带头结点的双向链表，tail指向尾结点；head指针指向第一个结点，返回值是指向头结点的指针
    struct Hnode *head = (struct Hnode *)malloc(sizeof(struct Hnode));
    head->head = head;
    head->tail = head;
    return head;
}

void insertDlist(struct Hnode *list, int insData) {
    //在双向链表的表头插入数据
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = insData;
    new_node->rlink = list;
    new_node->llink = list->tail;
    list->tail->rlink = new_node;
    list->tail = new_node;
}

int deleteData(struct Hnode *list, int delData) {
    //在双向链表中删除值为delData的第一个结点，若删除成功返回1，否则返回0
    struct node *now = list->head->rlink;
    while (now != list) {
        if (now->data == delData) {
            now->llink->rlink = now->rlink;
            now->rlink->llink = now->llink;
            free(now);
            return 1;
        }
        now = now->rlink;
    }
    return 0;
}

void printDlist(struct Hnode *list) {
    //输出双向循环链表中各数据元素的值，每输出一个数据元素换行
    struct node *now = list->head->llink;
    while (now != list) {
        printf("%d\n", now->data);
        now = now->llink;
    }
}

int destroyDlist(struct Hnode *list) {
    //释放双向链表占用的存储空间，释放所有结点,返回释放的结点数，不含list本身
    struct node *now = list->head->rlink, *del_node = NULL;
    int count = 0;
    while (now != list->head) {
        del_node = now;
        now = now->rlink;
        free(del_node);
        count++;
    }
    return count;
}

int main() {
    struct Hnode *head = createDlist();
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &data);
        insertDlist(head, data);
    }
    printDlist(head);
    scanf("%d", &data);
    printf("\n%d ", deleteData(head, data));
    printf("\n%d ", destroyDlist(head));

    return 1;
}

// 1.完成创建双向链表；
// 2.在双向链表中指定位置插入数据元素；
// 3.删除双向链表中满足条件的结点
// 4.回收双向链表占用的空间。
// 3
// 11
// 9
// 8
// 12
// 3

// 1
// 5