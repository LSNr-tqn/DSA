#include <stdio.h>

void printArray(int a[]) {
    for (int i = 0; i < 8 ; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {7, 9, 10, -4, 5, 8, 2, 1};
    int i = 0;
    for (i; i < 7; i++) {
        int j = i + 1;
        for (j; j < 8; j++) {
            if (a[j] < a[i]) {
                a[i] = a[i] + a[j];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
                printArray(a);
            }
        }
    }
}
