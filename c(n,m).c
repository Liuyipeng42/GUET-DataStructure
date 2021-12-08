#include <stdio.h>

int c(int n, int m) {
    if (n == m || m == 0)
        return 1;
    else
        return c(n - 1, m - 1) + c(n - 1, m);
}


int main(){
    printf("%d\n", c(6,2));
    return 0;
}

