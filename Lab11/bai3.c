#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void BubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) Swap(&a[j], &a[j - 1]);
        }
    }
    printArray(a,n);
}

int BinarySearch(int a[], int l, int r, int k, int *count) {
    int m = (l + r) / 2;
    (*count)++;
    printf("Lan xet %d\n", *count);
    printf("Dang xet vi tri %d co gia tri %d\n",m + 1, a[m]);
    if (a[m] == k) return m;
    printf("Khong bang\n");
    if (a[m] < k) return BinarySearch(a, m + 1, r, k, count);
    if (a[m] > k) return BinarySearch(a, l, m - 1, k, count);
    return -1;
}

int main() {
    int a[] = {7, 9, 10, -4, 5, 8, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int k;
    printf("Nhap k: ");scanf("%d", &k);
    int count = 0;
    BubbleSort(a, n);

    int x = BinarySearch(a, 0, n - 1, k, &count);
    if (x != -1) {
        printf("Tim thay o vi tri %d", x + 1);
    } else {
        printf("Khong tim thay");
    }
}