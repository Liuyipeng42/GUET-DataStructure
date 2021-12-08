#include <stdio.h>

int target_num, a, field[5001][5001];

int main() {
    scanf("%d %d", &target_num, &a);
    int x, y, v, i = 0;
    for (i = 0; i < target_num; i++) {
        scanf("%d %d %d", &x, &y, &v);
        field[x][y] = v;
    }

    for (x = 0; x < 5001; x++) {
        for (y = 0; y < 5001; y++) {
            if (x == 0)
                field[x][y] = field[x][y - 1] + field[x][y];
            else if (y == 0)
                field[x][y] = field[x - 1][y] + field[x][y];
            else
                field[x][y] = field[x - 1][y] + field[x][y - 1] -
                              field[x - 1][y - 1] + field[x][y];
        }
    }

    int max = 0, value = 0, lt = 0, lb = 0, rt = 0, rb = 0;
    for (x = 0; x < 5001; x++) {
        for (y = 0; y < 5001; y++) {
            if (x - a < 0 && y - a < 0) {
                rt = 0;
                lt = 0;
                lb = 0;
            }
            if (x - a < 0 && y - a >= 0) {
                rt = 0;
                lt = 0;
                lb = field[x][y - a];
            }
            if (y - a < 0 && x - a >= 0) {
                lt = 0;
                lb = 0;
                rt = field[x - a][y];
            }
            if (y - a >= 0 && x - a >= 0) {
                rt = field[x - a][y];
                lb = field[x][y - a];
                lt = field[x - a][y - a];
            }
            rb = field[x][y];

            value = rb - rt - lb + lt;

            if (value > max) max = value;
        }
    }

    printf("%d", max);

    return 0;
}

/*
5 2
0 2 2
3 2 3
1 1 1
1 0 2
0 1 3

*/
