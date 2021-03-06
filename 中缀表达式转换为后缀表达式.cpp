#ifndef _STACK_H_
#define _STACK_H_
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

typedef char DataType;

//采用链式栈
struct node {
    DataType element;   //数据元素
    struct node *next;  //指向下一个数据元素的指针
};

typedef struct node *PtrToNode;
typedef PtrToNode Stack;

/*
   函数名：isEmpty
   函数功能：判定栈是否为空
   函数参数：栈头结点指针
   返回值：若栈为空，则返回1，否则返回0
*/
int isEmpty(Stack s) { return s->next == NULL; }

/*
   函数名：createStack
   函数功能：创建一个空栈，实际上只需要初始化栈头结点
   函数参数：无
   返回值：栈头结点指针
*/
Stack createStack(void) {
    Stack s;
    s = new struct node;
    s->next = NULL;
    s->element = 0;
    return s;
}

/*
   函数名：push
   函数功能：向栈中压人一个数据元素值为x
   函数参数：待压栈的数据元素，栈头结点指针
   返回值：无
*/
void push(DataType x, Stack s) {
    //表头作为栈顶
    PtrToNode temp;
    temp = new struct node;
    temp->element = x;
    temp->next = s->next;
    s->next = temp;
}

/*
   函数名：pop
   函数功能：弹出栈顶元素并返回元素值
   函数参数：栈头结点指针
   返回值：栈顶元素的值
*/
DataType pop(Stack s) {
    PtrToNode temp;
    int t;
    if (isEmpty(s) == 0) {
        temp = s->next;
        t = temp->element;
        s->next = temp->next;
        free(temp);
        return t;
    }
}

DataType top(Stack s) {
    if (isEmpty(s) == 0) {
        return s->next->element;
    }
}

/*
   函数名：inToPost
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：无
*/
void inToPost(char *expression) {
    int priority[13] = {};
    priority[(int)'#' - 35] = 0;
    priority[(int)'*' - 35] = 2;
    priority[(int)'+' - 35] = 1;
    priority[(int)'-' - 35] = 1;
    priority[(int)'/' - 35] = 2;

    Stack stack = createStack();
    push('#', stack);
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            printf("%c", expression[i]);
        } else {
            if (expression[i] == '(') {
                push('(', stack);
            } else if (expression[i] == ')') {
                while (1) {
                    char c = pop(stack);
                    if (c == '(') {
                        break;
                    } else {
                        printf(" %c", c);
                    }
                }
            } else {
                printf(" ");
                int n = 0;
                while (1) {
                    char c = top(stack);
                    if (priority[(int)c - 35] < priority[(int)expression[i] - 35])
                        break;
                    printf("%c ", pop(stack));
                }
                push(expression[i], stack);
            }
        }
    }

    while (1) {
        char c = top(stack);
        if (c == '#') break;
        printf(" %c", pop(stack));
    }

}

int main(void) {
    char express[80];
    cin >> express;
    inToPost(express);
}

#endif

// 31*(5-22)+70
// 31 5 22 - * 70 +

// 52+3*21-32/2
// 52 3 21 * + 32 2 / -

// #35 *42  +43 -45  /47
//  0   7    8   10   12
//  0   2    1   1    2