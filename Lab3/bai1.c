#include <stdio.h>

typedef struct tagStack {
    int a[1001];
    int t;
} Stack;

void CreateStack (Stack *s) {
    s->t = -1;
}

int isEmpty(Stack s) {
    if (s.t == -1) return 1;
	else return 0;
}

void Push(Stack *s, int x) {
    s->t++;
    s->a[s->t] = x;
}

int Pop(Stack *s, int *x) {
    if (isEmpty(*s) == 0) {
        *x = s->a[s->t];
        s->t--;
        return 1;
    } 
	else return 0;
}


int main () { 
    Stack s;
    CreateStack(&s);
    int n;
    printf("Nhap n de quy doi: "); scanf("%d", &n);
    int m = n;
    
    while (n != 0) {
        Push(&s, n % 2);
        n /= 2;
    }
    
    printf("%d sau khi quy doi sang nhi phan: ", m);
    while (Pop(&s, &n) == 1) {
        printf("%d", n);
    }
}