#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BubbleSortDR(int a[], int l, int r, int check) {
    if (check == 1) { //Tăng dần
        for (int i = l; i < r; i++) {
            for (int j = r; j > i; j--) {
                if(a[j - 1] > a[j]) {
                    Swap(&a[j], &a[j - 1]);
                }
            }
        }
        printArray(a, 9);
    } else { //Giảm dần
        for (int i = l; i < r; i++) {
            int max = i;
            for (int j = i + 1; j < r; j++) {
                if (a[j] > a[max]) max = j;
            }
            if (max != i) Swap(&a[max], &a[i]);
        }
        printArray(a, 9);
    }
}

int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            BubbleSortDR(a, 0, i - 1, 1);
            BubbleSortDR(a, i + 1, n, 0);
        }
    }
    printArray(a, n);
}