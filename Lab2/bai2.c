#include <stdio.h>

int sum_rec(int a[], int n) {
    if (n < 1) return 0;
    else return a[n-1] + sum_rec(a,n-1);
}

int main() {
    int a[] = {3, -1, 4};
    int n; scanf("%d", &n);
    printf("%d", sum_rec(a, n));
}