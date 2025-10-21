#include <stdio.h>

long long power(long long a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    long long split = power(a, n / 2);
    if (n % 2 == 0) return split * split;
    else return a*split*split;
}

int main() {
    long long a;
    int n;
    scanf("%lld%d", &a, &n);
    printf("%lld", power(a,n));
}