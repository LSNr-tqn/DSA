#include <stdio.h>

void printArray(int a[], int n) {
    for(int i =0 ; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Merge(int a[], int l, int r, int m) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int b[n1], c[n2];
    for(int i = 0; i < n1; i++) b[i] = a[l + i];
    for(int j = 0; j < n2; j++) c[j] = a[m + 1 + j];
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }
    while (i < n1) a[k++] = b[i++];
    while (j < n2) a[k++] = c[j++];
}

void mergeSort(int a[], int n, int l, int r) {
    if(l >= r) return;
    int m = (l + r)/2;
    mergeSort(a,n, l, m);
    mergeSort(a,n, m + 1, r);
    Merge(a, l, r, m);
    printArray(a, n);
}

int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4, 8, 29, 2};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a, n, 0, n - 1);
}