#include <stdio.h>
void printArray(int a[], int n) {
    for (int i =0 ; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int l, r, k;
    l = 0;
    r = 8;
    k = 8;
    int countChange = 0;
    int countBrowse = 0;
    while (l < r) {
        for (int i = r; i > l; i--) {
            countBrowse++;
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i-1] = temp;
                k = i;
                printArray(a, 9);
                countChange++;
            }
        }
        l = k;
        for (int i = l; i < r; i++) {
            countBrowse++;
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                k = i;
                printArray(a, 9);
                countChange++;
            }
        }
        r = k;
    }
    printf("\nSo lan so sanh: %d", countBrowse);
    printf("\nSo lan Swap: %d", countChange);
}