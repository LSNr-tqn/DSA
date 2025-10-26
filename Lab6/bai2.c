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

void preorder(Tree t) {
    if (!t) return;
    printf("%d ", t->key);
    preorder(t->Left); preorder(t->Right);
}

void inorder(Tree t) {
    if(!t) return;
    inorder(t->Left);
    printf("%d ", t->key);
    inorder(t->Right);
}

void postorder(Tree t) {
    if (!t) return;
    postorder(t->Left);
    postorder(t->Right); printf("%d ", t->key);
}

int main() {
    Tree cay;
    CreateTREE(&cay);

    int a[] = {5, 3, 8, 1, 4};
    int n = 5;

    for (int i = 0; i < n; i++) {
        addNode(&cay, a[i]);
    }
	
    printf("Preorder: "); preorder(cay);
    printf("\nInorder: "); inorder(cay);
    printf("\nPostorder: "); postorder(cay);

    return 0;
}
