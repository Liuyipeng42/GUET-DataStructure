#include <stdio.h>

/*此处是顺序栈数据结构定义*/
typedef int DataType;
struct seqStack {  //有3个数据成员
    int MAXNUM;  //用于记录顺序栈中能存放的最大元素个数的 整型 MAXNUM
    int top;  //用于存放顺序栈的栈顶位置，初始化为0或-1 均可  整型  curNum
    DataType *element;  //用于存放顺序栈数据元素的连续空间的起始地址
};

typedef struct seqStack *PseqStack;
//第一关
PseqStack createNullStack_seq(int m) {
    //此处填写代码，创建一个空的顺序栈，能存放的最大元素个数为m,栈顶top设置为0
    //若m=0，则返回NULL
    if (m > 0) {
        struct seqStack *stack =
            (struct seqStack *)malloc(sizeof(struct seqStack));
        stack->MAXNUM = m;
        stack->top = 0;
        stack->element = (DataType *)malloc(sizeof(DataType) * m);
        return stack;
    } else {
        return NULL;
    }
}

//第二关
int isNullStack_seq(PseqStack L) {
    //判断顺序栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L) {
        if (L->top) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return -1;
    }
}

//第三关
int isFullStack_seq(PseqStack L) {
    //判断顺序栈是否已满，若已满，返回值为1，否则返回值为0
    if (L->top == L->MAXNUM) {
        return 1;
    } else {
        return 0;
    }
}

//第四关
int push_seq(PseqStack L,DataType x) {  //在顺序栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (isFullStack_seq(L) == 0) {
        L->element[L->top] = x;
        L->top += 1;
        return 1;
    } else {
        return 0;
    }
}

//第五关
DataType pop_seq(PseqStack L) {  //弹栈并返回删除元素，若栈为空，则返回-1
    if (L->top) {
        L->top--;
        return L->element[L->top];
    } else {
        return -1;
    }
}

//第六关
DataType top_seq(PseqStack L) {  // 取栈顶元素返回，若栈为空，则返回-1
    if (L->top) {
        return L->element[L->top - 1];
    } else {
        return -1;
    }
}

//销毁顺序栈，释放栈所占存储空间
int destroystack_seq(PseqStack L) {
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (L) {
        free(L->element);
        free(L);
    } else {
        return 0;
    }
}

//第七关
//使用已实现的栈操作，实现数制转换

void print(PseqStack L) {
    //逐个弹出栈L中的数据元素并输出，输出数据间不需要任何间隔符号
    int r;
    while (1) {
        r = pop_seq(L);
        if (r == -1) {
            break;
        }else{
            if (r<10){
                printf("%d", r);
            }else{
                printf("%c", r-10+'A');
            }
        }
    }
}

void convert(int data, int k) {
    //利用栈实现将data转换为k进制，k可能是2，8，16.
    //在本函数内实现转换并调用print函数输出转换后的结果 十六进制时输出
    //A,B,C,D,E,F 使用大写字母
    PseqStack stack = createNullStack_seq(100);
    while (data > 0) {
        push_seq(stack, data % k);
        data /= k;
        // printf("%d\n", data);
    }
    print(stack);
}

//第一关
// int main(void) {
//     int m;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);
//     if (head == NULL)
//         printf("fail to create");
//     else
//         printf("success to create a stack of %d elements,current top %d", m,
//         head->top);
//     destroystack_seq(head);
// }
// 4
// success to create a stack of 4 elements,current top 0
// 0
// fail to create
// 6
// success to create a stack of 6 elements,current top 0

//第二关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);

//     printf("%d", isNullStack_seq(head));
//     destroystack_seq(head);
// }
// 5
// 1
// 0
// -1

//第三关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);

//     printf("%d", isFullStack_seq(head));
//     destroystack_seq(head);
// }
// 5
// 0

//第四关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         printf("%d ", push_seq(head, x));
//     }
//     destroystack_seq(head);
// }
// 4 3 1 2 3
// 1 1 1
// 3 4 1 2 3 4
// 1 1 1 0

//第五关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         push_seq(head, x);
//     }
//     while (isNullStack_seq(head) == 0) printf("%d ", pop_seq(head));
//     destroystack_seq(head);
// }
// 4 3 2 3 4
// 4 3 2
// 3 3 1 2 3
// 3 2 1

//第六关
// int main(void) {
//     int m, x;
//     scanf("%d", &m);
//     PseqStack head = createNullStack_seq(m);
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &x);
//         push_seq(head, x);
//     }

//     printf("%d", top_seq(head));
//     destroystack_seq(head);
// }
// 4 3 35 23 34
// 34
// 3 0
// -1

// //第七关
int main(void) {
    int m, x;
    scanf("%d%d", &m, &x);
    convert(m, x);
}
// 173 2
// 10101101
// 12 8
// 14
// 27 16
// 1B