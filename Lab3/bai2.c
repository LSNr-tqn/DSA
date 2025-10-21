#include <stdio.h>

typedef struct tagQueue {
    int a[1001];
    int Front;
    int Rear;
} Queue;

void CreateQueue(Queue *q) {
    q->Front = -1;
    q->Rear = -1;
}

int isEmpty(Queue q) {
    if (q.Front == -1) return 1; 
    else return 0;
}

int DeQueue(Queue *q, int *x) {
    if(isEmpty(*q)) {
        printf("Queue rong\n");
        return 0;
    } 
    *x = q->a[q->Front];
    if (q->Front == q->Rear) {
        q->Front = -1;
        q->Rear = -1;
    } else q->Front++;
    return 1;
}

int EnQueue(Queue *q, int x) {
    if (q->Rear - q->Front + 1 == 1001) {
        printf("Queue day!!");
        return 0;
    } else {
        if (isEmpty(*q)) {
            q->Front = 0;
        }
        if (q->Rear == 1000) {
            for (int i = q->Front ; i <= q->Rear; i++) q->a[i-q->Front] = q->a[i];
            q->Rear -= q->Front;
            q->Front = 0;
        }
        q->Rear++;
    }
    q->a[q->Rear] = x;
    printf("Thanh Cong!");
    return 1;
}

int main() {
    Queue q;
    CreateQueue(&q);
    int n;
    int x;
    do {
        printf("\n1. EnQueue\n2. DeQueue\n3. IsEmpty\n4. Out\nChoose: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Nhap x: "); scanf("%d", &x);
            EnQueue(&q, x);
            break;
        case 2:
            if (DeQueue(&q, &x)) 
            {
                printf("Thanh cong phan tu duoc xoa = %d", x);
            }
            break;
        case 3:
            if (isEmpty(q)) {
                printf("Queue rong!");
            } else printf("Queue khong rong");
            break;
        }
    } while (n != 4);
    
}