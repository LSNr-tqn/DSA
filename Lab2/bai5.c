#include <stdio.h>
long long dp[46];
long long fib_memo (int n) {
	if (n <= 1) return n;
	if (dp[n] != -1) return dp[n];
	dp[n] = fib_memo(n - 1) + fib_memo(n - 2);
	return dp[n];
}
int main() {
    int n;
    scanf("%d", &n);	
	for(int i = 0; i <= n ; i++) dp[i] = -1;
	printf("F(%d) = %lld\n", n, fib_memo(n));
	return 0;
}