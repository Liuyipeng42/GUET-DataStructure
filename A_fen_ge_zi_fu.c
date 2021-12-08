#include <stdio.h>  //1900300922������
int judge(char str[], int i, double num[]);
double strtoint(char str[], int i, double n, int r);
void sort(double num[], int i);
void output(double num[], int);

int main() {
    double num[10] = {};
    int len = 0, i = 0;
    char str[80];
    gets(str);
    while (str[i]) {
        len = judge(str, i, num);
        i++;
    }
    sort(num, len);
    output(num, len);
    return 0;
}

int judge(char str[], int i, double num[]) {
    static double n = 0;
    static int len = 0, isnum = 0, negative = 0;
    if (str[i] != 'A') {
        if (str[i] == '-' && n == 0) negative = 1;
        if (str[i] != '-') {
            n = strtoint(str, i, n, 0);
            isnum = 1;
        }
        if (str[i + 1] == 'A') strtoint(str, i, n, 1);
    }
    if ((str[i + 1] == '\0' || str[i] == 'A') && isnum == 1) {
        if (negative == 1)
            num[len] = -n;
        else
            num[len] = n;
        len++;
        n = 0;
        isnum = 0;
        negative = 0;
    }
    return len;
}

double strtoint(char str[], int i, double n, int r) {
    static int point = 0;
    static double a = 1;
    if (r == 0) {
        if (str[i] == '.') {
            point = 1;
            return n;
        }
        if (point == 0) {
            n = n * 10 + ((int)str[i] - 48);
        } else {
            a *= 0.1;
            n += a * ((double)str[i] - 48);
        }
    } else {
        a = 1;
        point = 0;
    }
    return n;
}

void sort(double num[], int len) {
    int i, j;
    double t;
    for (i = 0; i < len; i++)
        for (j = i; j < len; j++)
            if (num[i] > num[j]) {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
}

void output(double num[], int len) {
    int i;
    for (i = 0; i < len; i++) printf("%lf ", num[i]);
}

// A-123.456AAA2.23AA32.36