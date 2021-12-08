#include <stdio.h>

int fast_power(int a, int b);
long long fast_power1(long long x, long long y);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld %d", fast_power1(a, b),fast_power(a, b));
}

int fast_power(int a, int b) {
    int r = 1;
    while (b != 0) {
        if (b % 2)
            r *= a;
        a *= a;
        b /= 2;
    }
    return r;
}

long long fast_power1(long long x, long long y) {
    if (y==0)
        return 1;
    long long z = fast_power1(x, y / 2);
    if (y % 2)
        return z * z * x ;
    else
        return z * z;
}


