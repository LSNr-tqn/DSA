#include <stdio.h>
#include <stdlib.h>

typedef struct tagQueue {
    int data[100];
    int front, rear;
} Queue;

void CreateQueue(Queue *q)  {
    q->front = q->rear = -1;
}

int isEmpty(Queue q) {
    return q.front == -1;
}

void enQueue(Queue *q, int x) {
    if (q->rear == 100 - 1) {
        printf("Queue day!");
        return;
    }
    if (isEmpty(*q)) q->front = 0;
    q->data[++q->rear] = x;
}

int deQueue(Queue *q) {
    if (isEmpty(*q)) return -1;
    int x = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return x;
}

int getMax(int a[], int n) {
    int max = a[0];
    for(int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void RadixPositive(int a[], int n) {
    Queue bucket[10];
    for (int i = 0; i < 10; i++) CreateQueue(&bucket[i]);

    int max = getMax(a, n);
    int exp = 1;
    while(max/exp > 0) {
        for (int i = 0; i < n; i++) {
            int digit = (a[i]/exp) % 10;
            enQueue(&bucket[digit], a[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while(!isEmpty(bucket[i])) {
                a[idx++] = deQueue(&bucket[i]);
            }
        }
        exp *= 10;
        printArray(a, n);
    }
}

void Reverse(int a[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++; j--;
        printArray(a, n);
    }
}

void RadixSort(int a[], int n) {
    int neg[n], pos[n];
    int nNeg = 0, nPos = 0;
    // Phan am duong
    for(int i = 0; i < n; i++) {
        if (a[i] < 0) neg[nNeg++] = -a[i];
        else pos[nPos++] = a[i];
    }
    // Sort duong
    if (nPos > 0) RadixPositive(pos, nPos);
    // Sort am
    if (nNeg > 0) {
        RadixPositive(neg, nNeg);
        Reverse(neg, nNeg);
        for(int i = 0; i < nNeg; i++) neg[i] = -neg[i];
    }

    int idx = 0;
    for (int i = 0; i < nNeg; i++) a[idx++] = neg[i];
    for (int i = 0; i < nPos; i++) a[idx++] = pos[i];
}

int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4, 8, 29, 2};
    int n = sizeof(a)/sizeof(a[0]);
    RadixSort(a, n);
    printArray(a, n);
}