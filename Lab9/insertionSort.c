#include <stdio.h>
void printArray(int a[], int n) {
    for (int i =0 ; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int x, index;
    int countSwap = 0;
    int countGan = 0;
    for (int i = 1; i < 9; i++) {
        x = a[i];countGan++;
        index = i - 1;
        while (index >= 0 && a[index] > x) {
            countSwap++;
            a[index + 1] = a[index];countGan++;
            index--;
            printArray(a, 9);
        }
        a[index + 1] = x;countGan++;
        printArray(a, 9);
    } 

    printf("\nSo lan so sanh: %d", countSwap);
    printf("\nSo phep gan: %d", countGan);
}