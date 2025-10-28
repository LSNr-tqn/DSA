#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char op;
    int isNum;
    long long val;
    struct Node *left, *right;
} Node;

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// ================= INFIX → POSTFIX =================
int toPostfix(char *infix, char out[][20]) {
    char stack[100]; int top = -1, n = 0;
    for (int i = 0; infix[i]; ) {
        if (isspace(infix[i])) { i++; continue; }

        if (isdigit(infix[i])) {
            int j = 0; 
            while (isdigit(infix[i])) out[n][j++] = infix[i++];
            out[n][j] = '\0'; n++;
        } else {
            char c = infix[i++];
            if (c == '(') stack[++top] = c;
            else if (c == ')') {
                while (top >= 0 && stack[top] != '(') {
                    sprintf(out[n++], "%c", stack[top--]);
                }
                top--; // bỏ '('
            } else { // toán tử
                while (top >= 0 && prec(stack[top]) >= prec(c))
                    sprintf(out[n++], "%c", stack[top--]);
                stack[++top] = c;
            }
        }
    }
    while (top >= 0)
        sprintf(out[n++], "%c", stack[top--]);
    return n;
}

// ================= BUILD EXPRESSION TREE =================
Node* newNodeNum(long long v) {
    Node *t = malloc(sizeof(Node));
    t->isNum = 1; t->val = v; t->left = t->right = NULL;
    return t;
}
Node* newNodeOp(char op, Node *l, Node *r) {
    Node *t = malloc(sizeof(Node));
    t->isNum = 0; t->op = op; t->left = l; t->right = r;
    return t;
}

Node* buildTree(char post[][20], int n) {
    Node* st[100]; int top = -1;
    for (int i = 0; i < n; i++) {
        if (isdigit(post[i][0])) st[++top] = newNodeNum(atoll(post[i]));
        else {
            Node *r = st[top--], *l = st[top--];
            st[++top] = newNodeOp(post[i][0], l, r);
        }
    }
    return st[0];
}

// ================= EVALUATE & PRINT =================
long long eval(Node *t) {
    if (t->isNum) return t->val;
    long long a = eval(t->left), b = eval(t->right);
    switch (t->op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int p(Node *t) { return t->isNum ? 99 : prec(t->op); }

void printInfix(Node *t) {
    if (t->isNum) { printf("%lld", t->val); return; }

    int L = !t->left->isNum && p(t->left) < p(t);
    int R = !t->right->isNum &&
            (p(t->right) < p(t) || 
            (p(t->right) == p(t) && (t->op=='-'||t->op=='/')));

    if (L) printf("(");
    printInfix(t->left);
    if (L) printf(")");

    printf(" %c ", t->op);

    if (R) printf("(");
    printInfix(t->right);
    if (R) printf(")");
}

// ================= MAIN =================
int main() {
    char expr[200], post[100][20];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);

    int n = toPostfix(expr, post);
    printf("Hau to: ");
    for (int i=0;i<n;i++) printf("%s ", post[i]);
    printf("\n");

    Node *root = buildTree(post, n);
    printf("Gia tri: %lld\n", eval(root));

    printf("Trung to toi thieu: ");
    printInfix(root);
    printf("\n");
    return 0;
}
