#include <stdio.h>
#include <stdlib.h>
//第一关代码

//此处填写代码，定义链表结点类型，包含一个存放整型数据的 data
//成员，和一个指向下一个结点的next成员
struct node {
    int data;
    struct node *next;
};

//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
struct node *mycreateList() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head) {
        head->data = 0;
        head->next = NULL;
        return head;
    }
}

//第二关代码
void myinsertHead(struct node *head, int insData) {
    /*在此处完成任务，实现在head为表头的链表的头插数据元素insData的功能*/
    // begin
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = insData;
    if (head->next) {
        new_node->next = head->next;
        head->next = new_node;
    } else {
        new_node->next = NULL;
        head->next = new_node;
    }

    // end
}

void myinsertTail(struct node *head, int insData) {
    /*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
    // begin
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = insData;
    new_node->next = NULL;
    struct node *end = head;
    while (end->next) {
        end = end->next;
    }
    end->next = new_node;
    // end
}

void myprintList(struct node *L) {
    /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
    // begin
    struct node *end = L;
    while (end->next) {
        end = end->next;
        printf("%d\n", end->data);
    }
    // end
}

//第三关代码
void reverseList_link(struct node *L) {
    //请在此处填入代码，实现链表逆置功能
    // 所谓的逆置，就是在不新建结点的情况下，实现将每个结点的指针域指向由原来的指向后一个结点改为指向前一个结点。
    // begin
    struct node *temp_head = L->next, *insert_node = (L->next)->next;
    temp_head->next = NULL;
    while (insert_node->next) {
        L->next = insert_node->next;
        insert_node->next = temp_head;
        temp_head = insert_node;
        insert_node = L->next;
    }
    insert_node->next = temp_head;
    // end
}

//第四关代码
int locateAndChange(struct node *L, int data) {
    //请在此处填入代码，在头结点为L的链表中查找与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    //若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
    // begin
    struct node *pre = L, *now = L->next;
    if (now->data == data) {
        return 0;
    }
    while (now->next) {
        if ((now->next)->data == data) {
            break;
        }
        pre = now;
        now = now->next;
    }
    if (now->next) {
        pre->next = now->next;
        if ((now->next)->next) {
            now->next = pre->next;
            pre->next = now;
            return now->data;
        } else {
            pre->next = now;
            now->next = NULL;
        }
    } else {
        return -1;
    }

    // end
}

//第五关代码
int destroyList(struct node *L) {
    //请在此处填写代码，实现将链表L的结点空间回收
    //返回值为回收结点的个数，含头结点在内
    struct node *end, *next = L;
    int count = 1;
    while (next->next) {
        end = next;
        next = end->next;
        free(end);
        count++; 
    }
    free(next);
    return count++;
}

//第一关代码
// int main(void)
// {
//    struct node *L = mycreateList();
//    if(L==NULL)
//        printf("fail to create");
//    else
//        { printf("success to create");
//          printf(" %d ",L->data);
//        }
//     return 1;
// }

//  success to create 0

//第二关代码

// int main(void) {
//     struct node *L = mycreateList();
//     int a[] = {1, 2, 3, 4, 5, 6};
//     for (int i = 0; i < 6; i++)
//         if (i % 2)
//             myinsertTail(L, a[i]);
//         else
//             myinsertHead(L, a[i]);
//     myprintList(L);
// }
// 5
// 3
// 1
// 2
// 4
// 6

//第三关代码
// int main(void) {
//     struct node *pllist = mycreateList();
//     int num;
//     int data;
//     scanf("%d", &num);
//     for (int i = 0; i < num; i++) {
//         scanf("%d", &data);
//         myinsertTail(pllist, data);
//     }
//     reverseList_link(pllist);
//     myprintList(pllist);
// }
// 5 12 34 56 78 90
// 90
// 78
// 56
// 34
// 12

// 3 1 8 78
// 78
// 8
// 1

// 第四关代码
// int main(void) {
//     struct node *pllist = mycreateList();
//     int num;
//     int data;
//     int pos;
//     scanf("%d", &num);
//     for (int i = 0; i < num; i++) {
//         scanf("%d", &data);
//         myinsertTail(pllist, data);
//     }
//     scanf("%d", &data);
//     printf("%d", locateAndChange(pllist, data));
// }
// 5 -12 34 23 6 7 34
// -12

// 5 -12 34 23 6 7 -12
// 0

// 5 -12 34 23 6 7 45
// -1

//第五关代码
// int main(void) {
//     struct node *pllist = mycreateList();
//     int num;
//     int data;
//     int pos;
//     scanf("%d", &num);
//     for (int i = 0; i < num; i++) {
//         scanf("%d", &data);
//         myinsertHead(pllist, data);
//     }
//     printf("%d", destroyList(pllist));
// }
// 5 1 2 3 4 5
// 6

// 1 1
// 2
