#include <stdio.h>

/*此处是顺序队列数据结构定义*/
typedef int DataType;
struct seqQueue {
    DataType MAXNUM;
    DataType front, rear;
    DataType *element;
};

typedef struct seqQueue *PseqQueue;
//第一关
PseqQueue createNullQueue_seq(int m) {
    //此处填写代码，创建一个空的顺序队列，能存放的最大元素个数为 m
    //若m=0，则返回NULL
    if (m) {
        PseqQueue Queue = (PseqQueue)malloc(sizeof(struct seqQueue));
        Queue->MAXNUM = m;
        Queue->element = (DataType *)malloc(sizeof(DataType) * m);
        Queue->rear = 0;
        Queue->front = 0;
        return Queue;
    } else {
        return NULL;
    }
}

//第二关
int isNullQueue_seq(PseqQueue Q) {
    //判断顺序（环形）队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
    if (Q == NULL) {
        return -1;
    } else {
        return Q->front == Q->rear;
    }
}

//第三关
int isFullQueue_seq(PseqQueue Q) {
    //判断环形队列是否已满，若已满，返回值为1，否则返回值为0
    return ((Q->rear + 1) % Q->MAXNUM == Q->front);
}

//第四关
int enQueue_seq(PseqQueue Q, DataType x) {
    //在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (isFullQueue_seq(Q) == 0) {
        Q->element[Q->rear] = x;
        Q->rear = (Q->rear + 1) % Q->MAXNUM;
        return 1;
    } else {
        return 0;
    }
}

//第五关
DataType delQueue_seq(PseqQueue Q) {
    //出队并返回删除元素，若队列为空，则返回-1
    if (isNullQueue_seq(Q) == 0) {
        int e = Q->front;
        Q->front = (Q->front + 1) % (Q->MAXNUM);
        return Q->element[e];
    } else {
        return -1;
    }
}

//第六关
DataType front_seq(PseqQueue Q) {
    // 取队首元素返回，若队列为空，则返回-1
    if (isNullQueue_seq(Q) == 1) {
        return -1;
    } else {
        return Q->element[Q->front];
    }
}

//销毁顺序队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q) {
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    free(Q->element);
    if (Q->front > Q->rear)
        return Q->MAXNUM - Q->front + Q->rear;
    else
        return Q->rear - Q->front;
}

void sort(int a[], int m) {
    int min = 0, min_p, temp;
    for (int i = 0; i < m; i++) {
        min = a[i];
        min_p = i;
        for (int j = i; j < m; j++) {
            if (a[j] < min) {
                min = a[j];
                min_p = j;
            }
        }
        temp = a[i];
        a[i] = a[min_p];
        a[min_p] = temp;
    }
}

//第七关
void queueApp(int a[], int n) {
    //参数用于传递顾客编号和顾客人数，输出顾客接受服务后离开顺序
    sort(a, n);

    PseqQueue A = createNullQueue_seq(n + 1), B = createNullQueue_seq(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            enQueue_seq(A, a[i]);
        } else {
            enQueue_seq(B, a[i]);
        }
    }

    while (isNullQueue_seq(A) == 0 || isNullQueue_seq(B) == 0) {
        if (isNullQueue_seq(A) == 0) {
            printf("%d ", delQueue_seq(A));
            printf("%d ", delQueue_seq(A));
        }
        if (isNullQueue_seq(B) == 0) {
            printf("%d ", delQueue_seq(B));
        }
    }
}

int main(void) {
    int m, a[8];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    queueApp(a, m);
}

// 8 2 1 3 9 4 11 13 15
// 1 3 2 9 11 4 13 15

// 6 2 4 6 8 10 12
// 2 4 6 8 10 12

// 5 1 3 7 4 5
// 1 3 4 7 5