#include <iostream>
using namespace std;


void BubbleSort_1(int* A, int N) {
    //请在此处填写另一种冒泡排序的算法，使得结果能如说明所示
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] > A[j - 1]) {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
        for (int k = 0; k < N; k++) {
            printf("%d ", A[k]);
        }
        printf("\n");
    }

}

int main(void) {
    int a[8];
    int i;
    for (i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
    }

    BubbleSort_1(a, 8);
}

// 5 11 6 38 19 12 66 4

// 4 5 11 6 38 19 12 66
// 4 5 6 11 12 38 19 66
// 4 5 6 11 12 19 38 66
// 4 5 6 11 12 19 38 66
// 4 5 6 11 12 19 38 66
// 4 5 6 11 12 19 38 66
// 4 5 6 11 12 19 38 66

