#include <stdio.h>

void printArray(int a[]) {
    for (int i = 0; i < 8 ; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {7, 9, 10, -4, 5, 8, 2, 1};
    int i = 0;
    for (i; i < 7; i++) {
        int j = 7;
        for (j; j > i; j--) {
            if(a[j - 1] > a[j]) {
                a[j] = a[j] + a[j - 1];
                a[j - 1] = a[j] - a[j - 1];
                a[j] = a[j] - a[j - 1];
                printArray(a);
            }
        }
    }
}