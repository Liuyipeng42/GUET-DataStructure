#include <stdio.h>
#include <string.h>

void reverse(char str[]);
int main() {
    char num1[100], num2[100], answer[100];
    scanf("%s", num1);
    scanf("%s", num2);
    int lmax, i, n;
    reverse(num1);
    reverse(num2);
    for (i = 0; i < 100; i++) answer[i] = '0';
    if (strlen(num1) > strlen(num2)) {
        lmax = strlen(num1);
        for (i = strlen(num2); i < lmax; i++) num2[i] = '0';
        num2[i] = '\0';
    } else {
        lmax = strlen(num2);
        for (i = strlen(num1); i < lmax; i++) num1[i] = '0';
        num1[i] = '\0';
    }
    for (i = 0; i < lmax; i++) {
        n = (int)(num1[i] + num2[i] + answer[i]) - 144;
        if (n < 10) {
            answer[i] = (char)(n + 48);
        } else {
            answer[i] = (char)(n % 10 + 48);
            answer[i + 1] = '1';
        }
    }
    answer[i] = '\0';
    reverse(answer);
    printf("%s", answer);
}

void reverse(char str[]) {
    int len = strlen(str);
    char t;
    for (int i = 0; i < len / 2; i++) {
        t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
}