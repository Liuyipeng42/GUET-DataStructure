#include <stdio.h>
#include <string.h>
int main() {
    int i, j, n = 0, count = 0;
    char l[50], s[10];
    scanf("%s", l);
    scanf("%s", s);
    for (j = 0; j <= strlen(l) - strlen(s); j++) {
        if (l[j] == s[0]) {
            for (i = 1; i < strlen(s); i++) {
                if (l[j + i] == s[i]) n++;
            }
        }
        if (n == strlen(s) - 1) {
            count++;
            printf("p=%d\n", j + 1);
        }
        n = 0;
    }
    printf("%d", count);
    return 0;
}

/*
AAAAAAAAA
AAA

*/
