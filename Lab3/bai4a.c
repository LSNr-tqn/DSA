#include <stdio.h>
#include <string.h>

typedef struct tagStack {
    char a[1001];
    int t;
} Stack;

void CreateStack(Stack *s) {
    s->t = -1;
}

int isEmpty(Stack s) {
    if (s.t == -1) return 1;
    else return 0;
}

void Push(Stack *s, char str) {
    s->t++;
    s->a[s->t] = str;
}

int Pop(Stack *s, char *str) {
    if (isEmpty(*s) == 0) {
        *str = s->a[s->t];
        s->t--;
        return 1;
    } else return 0;

}

int main () {
    Stack s;
    CreateStack(&s);
    char str;
    char string[100];
    int identy = 1;
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] == '\0';

// a.
    for (int i = 0; i < sizeof(string)/sizeof(string[0]); i++) {
        if (string[i] == '{' || string[i] == '(' || string[i] == '[') {
            Push(&s, string[i]);
        } 
        else if (string[i] == ')') {
            if (Pop(&s, &str) == 1) {
                if (str != '(') {
                    printf("Khong hop le!!\n");
                    identy = 0;
                    break;
                } 
            }
        } else if (string[i] == ']') {
            if (Pop(&s, &str) == 1) {
                if (str != '[') {
                    printf("Khong hop le!!\n");
                    identy = 0;
                    break;
                } 
            }
        } else if (string[i] == '}') {
            if (Pop(&s, &str) == 1) {
                if (str != '{') {
                    printf("Khong hop le!!\n");
                    identy = 0;
                    break;
                } 
            }
        }
    }

    if (identy) {
        printf("Hop le");
    }
}
