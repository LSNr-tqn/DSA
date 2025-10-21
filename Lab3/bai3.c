#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagStack {
    int a[100];
    int t;
} Stack;

void CreateStack (Stack *s) {
    s->t = -1;
}

int isEmpty(Stack s) {
    if (s.t == -1) return 1;
	else return 0;
}

int isFull(Stack s) {
    if(s.t + 1 == 100) {
        return 1;
    }
    else return 0;
}

void Push(Stack *s, int x) {
    if (isFull(*s) == 0) {
        s->t++;
        s->a[s->t] = x;
    } else printf("Stack da day!!");
}

int Pop(Stack *s, int *x) {
    if (isEmpty(*s) == 0) {
        *x = s->a[s->t];
        s->t--;
        return 1;
    } 
	else return 0;
}

int Top(Stack s) {
    return s.a[s.t];
}

int Size(Stack s) {
    return s.t + 1;
}

int main() {
    Stack s;
    CreateStack(&s);
    int x;
    char string[10];
    while (1) {
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        char *cmd = strtok(string, " "); // Lay dau cach lam dau phan cach
        char *value = strtok(NULL, " "); // Lay tham so neu co

        if (strcmp(string, "PUSH") == 0 && value != NULL) {
            int num = atoi(value);
            Push(&s, num);
            printf("Thanh cong!\n");
        }
        else if (strcmp(string, "POP") == 0) {
            Pop(&s, &x);
            printf("x = %d\n", x);
        }
        else if (strcmp(string, "TOP") == 0) {
            printf("Top: %d\n", Top(s));
        }
        else if (strcmp(string, "SIZE") == 0) {
            printf("Size: %d\n", Size(s));
        }
        else if (strcmp(string, "END") == 0) break;
        else printf("Sai cu phap!!\n");
    } 
}