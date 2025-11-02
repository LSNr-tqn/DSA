#include <stdio.h>
void printArray(int a[], int n) {
    for (int i =0 ; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int x, index, l, r;
    int countSwap = 0;
    int countGan = 0;
    
    for (int i = 1; i < 9; i++) {
        x = a[i]; countGan++;
        l = 0, r = i - 1;
        while(l<=r) {
            countSwap++;
            if (x < a[(l+r)/2]) r = (l+r)/2 - 1;
            else l = (l+r)/2 + 1;
        }
        for (int j = i - 1; j >= l; j--) {
            a[j+1] = a[j]; countGan++;
            printArray(a, 9);
        }
        a[l] = x; countGan++; printArray(a, 9);
    }
    printf("\nSo lan so sanh: %d", countSwap);
    printf("\nSo phep gan: %d", countGan);
}