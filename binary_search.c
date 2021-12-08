#include <stdio.h>

int search(int num[], int querynum, int len);
int first_num(int num[], int p, int querynum);

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    int num[n], querynum[m], p = 0;
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    for (int i = 0; i < m; i++) scanf("%d", &querynum[i]);
    for (int i = 0; i < m; i++) {
        if (querynum[i] == num[0])
            printf("1 ");
        else if (querynum[i] == num[n - 1]) {
            p = first_num(num, n - 1, querynum[i]);
            printf("%d ", p + 2);
        } else {
            p = search(num, querynum[i], n);
            p = first_num(num, p, querynum[i]);
            printf("%d ", p + 2);
        }
    }
}

int search(int num[], int querynum, int len) {
    int low = 0, mid = 0, high = len - 1;
    while (low < high - 1) {
        mid = (low + high) / 2;
        if (querynum == num[mid])
            return mid;
        else if (querynum > num[mid])
            low = mid;
        else
            high = mid;
    }
    return -3;
}

int first_num(int num[], int p, int querynum) {
    for (int j = p; j >= 0; --j) {
        if (num[j] != querynum) {
            p = j;
            break;
        }
    }
    return p;
}

/*
11 11
1 2 3 3 3 7 9 11 13 15 15
1 2 3 4 6 7 9 11 13 15 15

 */