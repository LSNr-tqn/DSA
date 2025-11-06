#include <stdio.h>

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a[] = {3,6,1, -1, 0, 5, 8, 2, 4, -4, 29, -2};
    int n = sizeof(a)/sizeof(a[0]);

    int l = 0;
    int r = n - 1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            // Xử lý phần bên phải
            while (r > i) {
                if (a[r] < a[r - 1]) {
                    Swap(&a[r], &a[r - 1]);
                    printArray(a, n);
                }
                if (a[r] >= 0) {
                    int temp = a[r], j = i;
                    while (j > 0 && temp > a[j - 1]) j--;
                    int k = r;
                    while (k > j) {
                        a[k] = a[k - 1];
                        k--;
                    }
                    a[k] = temp;
                    count++;
                    i++;
                    printArray(a, n);
                } else r--;
            }
            while (l < i) {
                if (a[l] < a[l + 1]) {
                    Swap(&a[l], &a[l + 1]);
                    printArray(a, n);
                }
                if (a[l] < 0) {
                    int temp = a[l], j = i;
                    while (j < n - 1  && temp > a[j + 1]) j++;
                    int k = l;
                    while (k < j) {
                        a[k] = a[k + 1];
                        k++;
                    }
                    a[k] = temp;
                    i--;
                    printArray(a, n);
                }
                else l++;
            }
            break;
        }
    }
    printArray(a, n);
    return 0;
}