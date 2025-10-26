#include <stdio.h>
#include <stdlib.h>

typedef struct tagTNode {
    int key;
    struct tagTNode *Left, *Right;
} TNode;

typedef TNode* Tree;

void CreateTREE(Tree *t) {
    *t = NULL;
}

TNode* createNode(int x) {
    TNode *p = (TNode*) malloc(sizeof(TNode));
    if (!p) exit(1);
    p->key = x;
    p->Left = p->Right = NULL;
    return p;
}

void addNode(Tree *t, int x) {
    if (*t == NULL) {
        *t = createNode(x);
    } else if (x < (*t)->key) {
        addNode(&((*t)->Left), x);
    } else if (x > (*t)->key) {
        addNode(&((*t)->Right), x);
    }
}

void printNLR(Tree t) {
    if (t != NULL) {
        printf("%d ", t->key);
        printTree(t->Left);
        printTree(t->Right);
    }
}

int main() {
    Tree cay;
    CreateTREE(&cay);

    int a[] = {5, 3, 8, 1, 4};
    int n = 5;

    for (int i = 0; i < n; i++) {
        addNode(&cay, a[i]);
    }
	
    printf("Cay nhi phan: ");
    printNLR(cay);

    return 0;
}
