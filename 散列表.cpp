#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef int DataType;
struct hashdata  // hash表结构
{
    int num;  // hash表长度
    DataType *element;
};

typedef struct hashdata *phash;
phash InitHashTable(int n) {
    //请在此处填入代码， 初始化哈希表 注意初始化时，未装填数据哈希表填入-1
    phash hashlist = (phash)malloc(sizeof(hashdata));
    hashlist->num = n;
    hashlist->element = (DataType *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        hashlist->element[i] = -1;
    }
    return hashlist;
}

void Print(phash H) {
    for (int i = 0; i < H->num; i++) {
        cout << H->element[i] << " ";
    }
}

// hash函数
int hashFun(int data) { return data % 11; }

void InsertHash(phash H, int data) {
    //请在此处填入代码，调用hashFun计算哈希地址，将数据data装填到哈希表中对应地址处，处理冲突的方法是线性探查法
    int pos = hashFun(data);
    for (int i = 0; i < 11; i++) {
        if (H->element[pos] == -1) {
            H->element[pos] = data;
			break;
        } else {
            pos ++;
        }
    }
}

//输出哈希表


int main() {
    phash H = InitHashTable(11);  //初始化哈希表
    int d;
    for (int i = 0; i < 7; i++)  //输入7个元素，装填到哈希表中
    {
        scanf("%d", &d);
        InsertHash(H, d);
    }
    Print(H);  //输出哈希表
}

// 12 3 78 9 12 11 22
// 11 12 78 3 12 22 -1 -1 -1 9 -1

// 7 6 3 15 17 18 9
// -1 -1 -1 3 15 -1 6 7 17 18 9