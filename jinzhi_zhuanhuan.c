#include <stdio.h>
#include <string.h>

int main() {
    int k, b, now = 0, len;
    char num[100005];
    int ans[100005];
    scanf("%d %d", &k, &b);
    scanf("%s", num);
    len = strlen(num);
    for (int i = 0; i < len; i++) {
        now = now * k;
        if (num[i] >= '0' && num[i] <= '9')
            now += num[i] - '0';
        else if (num[i] >= 'A' && num[i] <= 'Z')
            now += num[i] - 'A' + 10;
    }

    len = 0;
    while (now) {
        ans[++len] = now % b;
        now /= b;
    }
    for (int i = len; i >= 1; i--) {
        if (ans[i] <= 9)
            printf("%d", ans[i]);
        else
            printf("%c", ans[i] - 10 + 'A');
    }
    return 0;
}
