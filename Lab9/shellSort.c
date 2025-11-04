#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[]) {
    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int shellSort(int a[],int h[],int n, int m) {
    for (int k = 0; k < m; k++) {
        int jump = h[k];
        for (int i = jump; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= jump && a[j - jump] > temp) {
                a[j] = a[j - jump];
                j -= jump;
            }
            a[j] = temp;
            printArray(a);
        }
    }
}

int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int h[] = {5, 3, 1};

    shellSort(a, h, sizeof(a)/sizeof(a[0]), sizeof(h)/sizeof(h[0]));
}