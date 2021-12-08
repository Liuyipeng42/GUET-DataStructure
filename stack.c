#include <stdio.h>
#include <string.h>

int str_to_num(char num[]);

int main() {
    int stack[300];
    int t, top = 0;
    char operation[2], num[15];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", operation);
        if (operation[0] == 'p') {
            scanf("%s", num);
            stack[top] = str_to_num(num);
            top++;
        } else if (operation[0] == 't') {
            if (top)
                printf("%d\n", stack[top - 1]);
            else
                printf("no\n");
        } else if (operation[0] == 'd') {
            if (top)
                top--;
        }
    }
    return 0;
}


int str_to_num(char num[]) {
    int n = 0;
    for (int i = 0; i < strlen(num); ++i)
        n = n * 10 + (int) num[i] - 48;
    return n;
}

//  p x 代表x入队
//  t 输出队首元素（无元素输出no）
//  d 删除队首元素 （无元素不进行操作）

