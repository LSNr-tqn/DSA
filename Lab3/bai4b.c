#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct tagStack {
    char a[1001][100]; // mỗi phần tử là 1 thẻ <tag>
    int t;
} Stack;

void CreateStack(Stack *s) {
    s->t = -1;
}

int isEmpty(Stack s) {
    return (s.t == -1);
}

void Push(Stack *s, char str[]) {
    s->t++;
    strcpy(s->a[s->t], str);
}

int Pop(Stack *s, char str[]) {
    if (!isEmpty(*s)) {
        strcpy(str, s->a[s->t]);
        s->t--;
        return 1;
    }
    return 0;
}

int main() {
    Stack s;
    CreateStack(&s);

    char string[1001];
    printf("Nhap chuoi the HTML: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0'; // xóa ký tự newline

    int i = 0;
    int identy = 1;
    char temp[100], tag[100];

    while (i < strlen(string)) {
        if (string[i] == '<') {
            i++;
            // Nếu là thẻ đóng
            if (string[i] == '/') {
                i++;
                int j = 0;
                while (string[i] != '>' && string[i] != '\0') {
                    if (!islower(string[i])) { identy = 0; break; } // chỉ cho chữ thường
                    tag[j++] = string[i++];
                }
                tag[j] = '\0';
                if (identy == 0) break;

                char openTag[100];
                if (!Pop(&s, openTag)) {
                    identy = 0; // có thẻ đóng mà không có mở
                    break;
                }
                if (strcmp(openTag, tag) != 0) {
                    identy = 0; // tên thẻ không khớp
                    break;
                }
            } 
            // Nếu là thẻ mở
            else {
                int j = 0;
                while (string[i] != '>' && string[i] != '\0') {
                    if (!islower(string[i])) { identy = 0; break; } // chỉ chữ thường
                    tag[j++] = string[i++];
                }
                tag[j] = '\0';
                if (identy == 0) break;
                Push(&s, tag);
            }
        }
        i++;
    }

    // Sau khi duyệt xong
    if (!isEmpty(s)) identy = 0;

    if (identy)
        printf("Hop le\n");
    else
        printf("Khong hop le\n");

    return 0;
}