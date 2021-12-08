#include <stdio.h>
int main() {
    int num, n;
    int i, j, k, nk;
    double kb[2][50][4], pos[10][50][2], intersection[50][2];
    //kb k num 坐标1 坐标2
    scanf("%d", &num);
    for (i = 0, nk = 0; i < num; i++) {
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            for(k=0;k<2;k++)
                scanf("%lf", &pos[i][j][k]);
            if (j > 0) {
                kb[0][nk][0] = (pos[i][j-1][1] - pos[i][j][1]) / (pos[i][j - 1][0] - pos[i][j][0]);
                kb[1][nk][0] = pos[i][j][1] - kb[0][nk][0] * pos[i][j][0];
                kb[0][nk][1] = i;
                kb[0][nk][2] = j-1;
                kb[0][nk][3] = j;
                nk++;
            }
            if(j==n-1){
                kb[0][nk][0] = (pos[i][j][1] - pos[i][0][1]) / (pos[i][j][0] - pos[i][0][0]);
                kb[1][nk][0] = pos[i][0][1] - kb[0][nk][0] * pos[i][0][0];
                kb[0][nk][1] = i;
                kb[0][nk][2] = j;
                kb[0][nk][3] = 0;
                nk++;
            }
        }
    }
    k=0;
    double x,y,x1,y1,x2,y2,temp;
    for (i = 0; i < nk - 1; i++) {
        for (j = i + 1; j < nk; j++) {
            if (kb[1][j][0] - kb[1][i][0]==0){
                x = 0;
                y = kb[1][i][0];
            }else {
                x = (kb[0][i][0] - kb[0][j][0]) / (kb[1][j][0] - kb[1][i][0]);
                y = kb[0][i][0] * x + kb[1][i][0];
            }
            x1 = pos[(int)kb[0][i][1]] [(int)kb[0][i][2]] [0];
            y1 = pos[(int)kb[0][i][1]] [(int)kb[0][i][2]] [1];
            x2 = pos[(int)kb[0][i][1]] [(int)kb[0][i][3]] [0];
            y2 = pos[(int)kb[0][i][1]] [(int)kb[0][i][3]] [1];

            if(x1>x2){
                temp=x1;
                x1=x2;
                x2=temp;
            }
            if(y1>y2){
                temp=y1;
                y1=y2;
                y2=temp;
            }
            printf("%.2lf %.2lf  %.2lf %.2lf\n",x1,x2,y1,y2);
            if(x1<x&&x<x2&&y1<y&&y<y2){
                intersection[k][0]=x;
                intersection[k][1]=y;
                k++;
            }
        }
    }

    printf("%d\n",k);
    for(j=0;j<10;j++) {
        for (k = 0; k < 2; k++)
            printf(" %.3lf", intersection[j][k]);
        printf("\n");
    }
/*
    for (i = 0; i < 10; i++) {
        printf("%5.2lf  ", kb[0][i][0]);
        printf("%5.2lf  \n", kb[1][i][0]);
    }
*/

/*
    for(j=0;j<6;j++)
        for(k=0;k<2;k++)
            printf(" %.0lf",pos[0][j][k]);
    printf("\n");
    for(j=0;j<4;j++)
        for(k=0;k<2;k++)
            printf(" %.0lf",pos[1][j][k]);
    printf("\n");
*/
    return 0;
}

/*

2
6
-2 0
-1 -2
1 -2
2 0
1 2
-1 2
4
0 -3
1 -1
2 2
-1 0

-2.00  -4.00   2.24
-0.00  -2.00   2.00
 2.00  -4.00   2.24
-2.00   4.00   2.24
 0.00   2.00   2.00
 2.00   4.00   2.24
 2.00  -3.00   2.24
 3.00  -4.00   3.16
 0.67   0.67   3.61
-3.00  -3.00   3.16

 */