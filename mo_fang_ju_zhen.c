#include <stdio.h>
int main() {
    int a[5][5] = {0};
    int sum[12] = {0};
    int row, col, i, equal = 1;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) scanf("%d", &a[row][col]);
    }
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            sum[row] += a[row][col];
            sum[col + 5] += a[row][col];
            if (row == col) sum[10] += a[row][col];
            if (row + col == 4) sum[11] += a[row][col];
        }
    }
    for (i = 1; i < 12; i++) {
        if (sum[0] != sum[i]) equal = 0;
    }
    if (equal == 1)
        printf("��ħ������");
    else
        printf("����ħ������");
    return 0;
}