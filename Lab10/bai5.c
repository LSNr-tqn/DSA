#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    } printf("\n");
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != i) {
        Swap(&a[i], &a[largest]);
        heapifyMax(a, n, largest);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) {
        Swap(&a[i], &a[smallest]);
        printArray(a, n);
        heapifyMin(a, n, smallest);
    }
}

void HeapSortDesc(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Swap(&a[0], &a[i]);
        printArray(a, n);
        heapifyMin(a, i, 0);
    }
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Swap(&a[i], &a[0]);
        printArray(a, n);
        heapifyMax(a, i, 0);
    }
}

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void extractMax(int a[], int n, int k) {
    if(k <= 0) return;
    int *heap = (int*) malloc(n* sizeof(int));
    copyArray(a, heap, n);
    for (int i = n / 2 - 1; i >=0 ; i--) {
        heapifyMax(heap, n, i);
    }
    for (int i = 0; i < k && n > 0; i++) {
        printf("%d ", heap[0]);
        heap[0] = heap[n - 1];
        n--;
        heapifyMax(heap, n, 0);
    }
    free(heap);
}

int main() {
    int a[] = {7, 2, 9, 4, 9, 5, 10, 3};
    int n = sizeof(a) / sizeof(a[0]);
    HeapSortDesc(a, n);
    int k;
    printf("\nNhap k: ");
    if (scanf("%d", &k) == 1) {
        extractMax(a, n, k);
    }
    return 0;
}