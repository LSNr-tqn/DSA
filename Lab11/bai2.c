#include <stdio.h>

int main() {
    int a[] = {7, 9, 10, -4, 5, 8, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int k;
    printf("Nhap k: ");scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        printf("Tim kiem thu %d\n", i + 1);
        printf("Phan tu dang xet: %d\n", a[i]);
        if (a[i] == k) {
            printf("Bang\n");
            printf("Tim thay o vi tri %d", i+1);
            break;
        }
        printf("Khong bang\n\n");
    }
}