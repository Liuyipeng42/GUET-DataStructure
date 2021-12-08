#include <stdio.h>

long long int two_n_mod(int n);

int main() {
    int number;
    scanf("%d", &number);
    int n[number];
    for (int i = 0; i < number; i++) scanf("%d", &n[i]);
    for (int l = 0; l < number; l++) {
        int mods[n[l] + 1];
        long long int sum = 0;
        for (int i = 0; i <= n[l]; i++) mods[i] = two_n_mod(i + 1) - 1;
        for (int i = 0; i <= n[l]; i++) sum += mods[i];
        printf("%lld\n", sum % 1000000007);
    }
    return 0;
}

long long int two_n_mod(int n) {
    int i, r = 1;
    for (i = 0; i < n; i++) r = r * 2 % 1000000007;
    return r;
}

//#include <stdio.h>
//
// int main() {
//    long long now, ans, p = 1e9 + 7;
//    int t, n;
//    scanf("%d", &t);
//    while (t--) {
//        scanf("%d", &n);
//        ans = 0;
//        now = 1;
//        for (int i = 0; i <= n; i++) {
//            ans += now * (n + 1 - i) % p;
//            ans %= p;
//            now = (now * 2) % p;
//        }
//        printf("%lld\n", ans);
//    }
//    return 0;
//}
