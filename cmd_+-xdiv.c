#include <stdio.h>  //1900300922刘艺鹏
#include <stdlib.h>

void processUserInputStr(char* s);

int main(int argc, char* argv[]) { processUserInputStr(argv[1]); }

void processUserInputStr(char* s) {
    double num1, num2;
    char snum1[20] = {}, snum2[20] = {};
    int lennum = 0, j = 0, c = 0;
    while (s[lennum] != '+' && s[lennum] != '-' && s[lennum] != '*' &&
           s[lennum] != '/') {
        snum1[lennum] = s[lennum];
        lennum++;
    }
    c = lennum++;
    while (s[lennum++]) snum2[j++] = s[lennum - 1];
    num1 = (double)atof(snum1);
    num2 = (double)atof(snum2);
    if (s[c] == '+') printf("%.2lf", num1 + num2);
    if (s[c] == '-') printf("%.2lf", num1 - num2);
    if (s[c] == '*') printf("%.2lf", num1 * num2);
    if (s[c] == '/') printf("%.2lf", num1 / num2);
}