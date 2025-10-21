#include <stdio.h>

long long fib_naive(int n, long long *cnt) {
	(*cnt)++;
    if (n == 0) return 0;
    if (n == 1) return 1;  
   	return fib_naive(n - 1, cnt) + fib_naive(n - 2, cnt);
}
int main() {
    long long cnt = 0;
    int n; scanf("%d", &n);
    printf("F(%d) = %lld\n", n,fib_naive(n, &cnt));
    printf("So lan chay de quy = %lld", cnt);
}