#include <stdio.h>

void get_pos(int row, int n, int pos[30], int zheng[30], int fu[30],
             int Col[30]);

void output(int n, int pos[30]);

int num, total;

int main() {
    int n, pos[30], zheng[30] = {}, fu[30] = {}, Col[30] = {};
    scanf("%d", &n);
    get_pos(0, n, pos, zheng, fu, Col);
    printf("%d", total);
    return 0;
}

void get_pos(int row, int n, int pos[30], int zheng[30], int fu[30],
             int Col[30]) {
    if (row == n) {
        output(n, pos);
        total++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (Col[col] == 0 && zheng[row - col + n - 1] == 0 &&
            fu[row + col] == 0) {
            Col[col] = 1;
            pos[row] = col;
            zheng[row - col + n - 1] = 1;
            fu[row + col] = 1;

            get_pos(row + 1, n, pos, zheng, fu, Col);

            Col[col] = 0;
            zheng[row - col + n - 1] = 0;
            fu[row + col] = 0;
        }
    }
}

void output(int n, int pos[30]) {
    if (num < 3) {
        for (int i = 0; i < n; ++i) printf("%d ", pos[i] + 1);
        printf("\n");
    }
    num++;
}
