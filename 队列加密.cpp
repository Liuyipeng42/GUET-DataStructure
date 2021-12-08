#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;

//队列数据元素结构
typedef struct node {
    DataType info;
    struct node *next;
} QueueData;

typedef struct queueRecord {
    QueueData *front, *rear;
} LINKQUEUE;

typedef struct queueRecord *PLinkQueue;

PLinkQueue createEmptyQueue_link() {
    //创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front 和 rear
    LINKQUEUE *queue = (LINKQUEUE *)malloc(sizeof(LINKQUEUE));
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmptyQueue_link(PLinkQueue queue) {
    //判定队列是否为空，实质：看队列的front指针是否为空，若为空，则队列为空
    return queue->front == NULL;
}

void enQueue_link(DataType x, PLinkQueue queue) {
    //将数据元素x插入队尾。实质：生成一个struct
    // node类型的结点，并给相应成员赋值后插入队尾
    QueueData *new_node = (QueueData *)malloc(sizeof(QueueData));
    new_node->info = x;
    new_node->next = NULL;
    if (isEmptyQueue_link(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

DataType deQueue_link(PLinkQueue Q) {
    //出队，实质：
    //取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData
    //*p,PLinkQueue Q)插入队尾 本函数为针对本实验特殊设计，可实现秘钥的循环使用
    QueueData *p = Q->front;
    Q->front = p->next;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return p->info;
}

void decrypt(char src[], char key[], char dest[]) {
    /*  参数： src 放的是源文 ； key 放的是秘钥 ； dest 放加密后的密文
   加密函数： 步骤提示
   1. 初始化一个空队列Q
   2. 将key数组的元素逐个插入队列Q
   3. 逐个访问src数组的源文，并加密，
   使用deQueue_link(Q)函数可得到队首秘钥，并使秘钥循环使用
    */
    PLinkQueue key_queue = createEmptyQueue_link();
    for (int i = 0; i < strlen(key); i++) {
        enQueue_link(key[i], key_queue);
    }
    for (int i = 0; i < strlen(src); i++) {
        dest[i] = src[i] + (int)deQueue_link(key_queue) - 48;
    }

}

int main(void) {
    char src[80], key[20], dest[80];

    cin >> src;
    cin >> key;
    decrypt(src, key, dest);
    cout << dest;
}

// student 123
// tvxegqu

// hello 1357
// ihqsp