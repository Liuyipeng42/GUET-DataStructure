#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*此处是链栈数据结构定义*/
struct node {
    char info;
    struct node *link;
};

struct LinkStack {
    struct node *top;
};

//第一关
struct LinkStack *createNullStack_link() {  //此处填写代码，创建一个空的链栈
    struct LinkStack *stack =
        (struct LinkStack *)malloc(sizeof(struct LinkStack));
    stack->top = NULL;
    return stack;
}

//第二关
int isNullStack_link(struct LinkStack *L) {
    //判断栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L == NULL) return -1;
    return (L->top == NULL);
}

//第三关
int push_link(struct LinkStack *L, int x) {
    //在栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = x;
    if (L->top)
        new_node->link = L->top;
    else
        new_node->link = NULL;
    L->top = new_node;
    return 1;
}

//第四关
int pop_link(struct LinkStack *L) {  //弹栈并返回删除元素，若栈为空，则返回-1
    if (L->top == NULL) return -1;
    int pop = L->top->info;
    L->top = L->top->link;
    return pop;
}

//第五关
int top_link(struct LinkStack *L) {  // 取栈顶元素返回，若栈为空，则返回-1
    if (L->top == NULL) return -1;
    int pop = L->top->info;
    return pop;
}

//销毁栈，释放栈所占存储空间
int destroystack_link(struct LinkStack *L) {
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    int cnt = 0;
    if (L == NULL) return 0;
    struct node *p = L->top, *q;
    free(L);
    while (p->link != NULL) {
        q = p->link;
        cnt++;
        free(p);
        p = q;
    }
    return cnt;
}

//第六关
// 问题描述：平衡符号问题：在C语言源程序中，经常用到（）、[]、{}，这些符号应配对，否则会提示出错。

// 本关任务：使用链栈的基本操作，判断输入的一段程序或代码中这些符号是否配对。
int balance_symbol(char *s) {  //在此处填写代码完成符号配对判断，若配对，返回值为1，否则返回值为0
    struct LinkStack *head = createNullStack_link();
    char top;
    head->top = NULL;
    for (int i = 0; i < strlen(s); i++) {
        top = top_link(head);
        // printf("   %c %c\n", top, s[i]);
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' ||s[i] == ']' || s[i] == '}') {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                push_link(head, s[i]);
            else {
                if ((top == '[' && s[i] == ']') || (top == '(' && s[i] == ')') || (top == '{' && s[i] == '}')) {
                    pop_link(head);
                } else {
                    return 0;
                }
            }
        }
    }
    if (head->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// // 第一关
// int main(void) {
//     int m;

//     struct LinkStack *head = createNullStack_link();
//     if (head == NULL)
//         printf("fail to create");
//     else
//         printf("success to create a stack");
//     destroystack_link(head);
// }
// // success to create a stack

// //第二关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     struct LinkStack *head = createNullStack_link(m);

//     printf("%d", isNullStack_link(head));
// }
// // 1

// //第三关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     struct LinkStack *head = createNullStack_link();
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         printf("%d ", push_link(head, x));
//     }
// }
// // 3 1 2 3
// // 1 1 1

// // 1
// // 1

// //第四关
// int main(void) {
//     int m, x;

//     struct LinkStack *head = createNullStack_link();
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         push_link(head, x);
//     }
//     printf("%d ", pop_link(head));
// }

// // 4 2 3 4
// // 4
// // 0
// // -1

// //第五关
// int main(void) {
//     int m, x;
//     struct LinkStack *head = createNullStack_link();
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         push_link(head, x);
//     }

//     printf("%d ", top_link(head));
// }
// // 4 3 35 23 34
// // 34
// // 0
// // -1

//第六关
int main(void) {
    int m, x;
    char s[200];
    gets(s);
    printf("%d", balance_symbol(s));
}
// this { is [ a test ] }
// 1
// i am { test } ( [ ) hello }
// 0
// { [ ] ( ) }
// 1