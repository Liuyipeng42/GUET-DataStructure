#include <stdio.h>
#include <string.h>

int str_to_num(char num[]);

int main() {
    int queue[300], head = 0, tail = 0, t;
    scanf("%d", &t);
    char operation[2], num[15];
    while (t--) {
        scanf("%s", operation);
        if (operation[0] == 'p') {
            scanf("%s", num);
            queue[tail] = str_to_num(num);
            tail++;
        } else if (operation[0] == 't') {
            if (head != tail)
                printf("%d\n", queue[head]);
            else
                printf("no\n");
        } else if (operation[0] == 'd') {
            if (head != tail) head++;
        }
    }
}

int str_to_num(char num[]) {
    int n = 0;
    for (int i = 0; i < strlen(num); ++i) n = n * 10 + (int)num[i] - 48;
    return n;
}

//  p x 代表x入队
//  t 输出队首元素（无元素输出no）
//  d 删除队首元素 （无元素不进行操作）
