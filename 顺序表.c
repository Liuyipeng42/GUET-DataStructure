#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct seqList {
    int MAXNUM;
    int curNum;
    DataType* element;
};

typedef struct seqList* PseqList;

PseqList createNullList_seq(int m) {
    struct seqList* palist = (struct seqList*)malloc(sizeof(struct seqList));
    if (palist) {
        palist->element = (DataType*)malloc(sizeof(DataType) * m);
        if (palist->element && m > 0) {
            palist->MAXNUM = m;
            palist->curNum = 0;
            return palist;
        } else
            free(palist);
    }
    return NULL;
}

int isFullList_seq(PseqList L) {
    //判断顺序线性表是否已满，若已满，返回值为1，否则返回值为0
    if (L->curNum == L->MAXNUM)
        return 1;
    else
        return 0;
}

int insertP_seq(PseqList L, int p, int x) {
    //在线性表L中下标为p的位置插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
    //如果线性表满了， 还需输"list is full"的提示
    //如果插入位置非法，需输出提示"position is illegel"
    if (L->curNum == L->MAXNUM) {
        return 0;
    }
    if (p < 0 || L->MAXNUM <= p) {
        return 0;
    }

    for (int q = L->curNum - 1; q >= p; q--) {
        L->element[q + 1] = L->element[q];
    }
    L->element[p] = x;
    L->curNum = L->curNum + 1;
    return 1;
}

int insertPre_seq(PseqList L, int p, int x) {
    // 在线性表L中下标为p的位置的前面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
    //提示：直接调用insertP函数实现即可
    if (L->curNum == L->MAXNUM) {
        return 0;
    }
    if (p <= 0 || L->MAXNUM - 1 < p) {
        return 0;
    }

    for (int q = L->curNum - 1; q >= p - 1; q--) {
        L->element[q + 1] = L->element[q];
    }
    L->element[p - 1] = x;
    L->curNum = L->curNum + 1;
    return 1;
}

int insertPost_seq(PseqList L, int p, int x) {
    // 在线性表L中下标为p的位置的后面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
    //提示：直接调用insertP函数实现即可
    if (L->curNum == L->MAXNUM) {
        return 0;
    }
    if (p < 0 || L->MAXNUM - 1 <= p) {
        return 0;
    }

    for (int q = L->curNum - 1; q > p; q--) {
        L->element[q + 1] = L->element[q];
    }
    L->element[p + 1] = x;
    L->curNum = L->curNum + 1;
    return 1;
}

void printList_seq(PseqList L) {
    //逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    for (int i = 0; i < L->curNum; i++) {
        printf("%d ", L->element[i]);
    }
}

int destroyList_seq(PseqList L) {
    //返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (L == NULL)
        return 0;
    else {
        free(L->element);
        return L->curNum + 1;
    }
}

int locate_seq(PseqList L, int x) {
    //在顺序表L中查找给定值x首次出现的位置，若不存在给定值，则返回-1
    for (int i = 0; i < L->curNum; i++) {
        if (L->element[i] == x) return i;
    }
    return -1;
}

DataType locatePos_seq(PseqList L, int pos) {
    // 在顺序表L中查找指定位置pos处的数据元素，若位置非法，则返回第0个数据元素
    if (pos < 0 || L->curNum <= pos) return L->element[0];
    return L->element[pos];
}

int deletePos_seq(PseqList L, int pos) {
    //在顺序表L中删除下标pos处的数据元素，若pos非法，则返回-1；否则返回1
    if (pos < 0 || L->curNum <= pos) return -1;
    for (int i = pos; i < L->curNum - 1; i++) {
        L->element[i] = L->element[i + 1];
    }
    L->curNum = L->curNum - 1;
    return 1;
}

int delete_seq(PseqList L, int x) {
    //在顺序表L中删除与参数x值相同的数据元素，返回删除数据元素的个数
    //可以使用之前已完成的操作
    int dnum = 0;
    for (int pos = 0; pos < L->curNum; pos++) {
        if (L->element[pos] == x) {
            deletePos_seq(L, pos);
            dnum++;
            pos--;
        }
    }
    return dnum;
}

void replace_seq(PseqList L, int x, int y) {
    //将顺序表L中值为x的数据元素替换为y
    for (int pos = 0; pos < L->curNum; pos++) {
        if (L->element[pos] == x) {
            L->element[pos] = y;
        }
    }
}

void delDuplicate_seq(PseqList L) {
    //移除线性表中的所有重复元素；不要使用额外的数组空间，必须在原地修改输入数组
    //并在使用 O(1) 额外空间的条件下完成 使用常规删除即可，已修改测试用例
    int count = 0;
    for (int pos = 0; pos < L->curNum; pos++) {
        count = 0;
        for (int p = pos + 1; p < L->curNum; p++) {
            if (L->element[p] == L->element[pos]) {
                count++;
            }
        }
        if (count) {
            delete_seq(L, L->element[pos]);
            pos--;
        }
    }
}