#include <stdio.h>
#include <stdlib.h>

typedef struct tagTNode {
    int key;
    struct tagTNode *Left, *Right;
} TNode;

typedef TNode *Tree;

void CreateTree(Tree *t) {*t = NULL;}

TNode* CreateNode(int x) {
    TNode *n = (TNode*) malloc(sizeof(TNode));
    if (!n) exit(1);
    n->key = x;
    n->Left = NULL;
    n->Right = NULL;
    return n;
}

int insertBST(Tree *t, int x) {
    if(!(*t)){
        *t = CreateNode(x);
        return 1;
    }
    if(x == (*t)->key) return 0;
    else if (x < (*t)->key) return insertBST(&(*t)->Left, x);
    else return insertBST(&(*t)->Right, x);
}

TNode* searchBST(Tree t, int x) {
    if(!t || t->key == x) return t;
    return x < t->key ? searchBST(t->Left, x) : searchBST(t->Right, x);
}

int findMin(Tree t) {
    while (t && t->Left) t = t->Left;
    return t->key;
}

int findMax(Tree t) {
    while (t && t->Right) t = t->Right;
    return t->key;
}

void printLNR(Tree t) {
    if (!t) return;
    if (t->Left) printLNR(t->Left);
    printf("%d ", t->key);
    if (t->Right) printLNR(t->Right);
}

int main() {
    Tree t;
    CreateTree(&t);
    int a[] = {1, 10, 4, 6, 3};

    for (int i = 0; i < 5; i++){
        insertBST(&t, a[i]);
    }

    if (searchBST(t, 5)) printf("FOUND");
    else printf("NOT FOUND");

    printf("\nMin: %d", findMin(t));
    printf("\nMax: %d", findMax(t));

    printf("\n");
    printLNR(t);
}