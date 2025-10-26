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

void insertBST(Tree *t, int x) {
    if(!(*t)) {
        *t = CreateNode(x);
        return;
    }
    if (x < (*t)->key) return insertBST(&(*t)->Left, x);
    else if (x > (*t)->key) return insertBST(&(*t)->Right, x);

}

TNode* searchBST(Tree t, int x) {
    if(!t || t->key == x) return t;
    return x < t->key ? searchBST(t->Left, x) : searchBST(t->Right, x);
}

TNode* findMin(Tree t) {
    while (t && t->Left) t = t->Left;
    return t;
}

TNode* findMax(Tree t) {
    while (t && t->Right) t = t->Right;
    return t;
}

TNode* deleteBST(Tree *t, int x) {
    if (!t) return NULL;
    if (x < (*t)->key) (*t)->Left = deleteBST(&(*t)->Left, x);
    else if (x > (*t)->key) (*t)->Right = deleteBST(&(*t)->Right, x);
    else {
        if (!(*t)->Left) {
            TNode *p = (*t)->Right;
            free(*t);
            return p;
        }
        else if (!(*t)->Right) {
            TNode *p = (*t)->Left;
            free(*t);
            return p;
        }
        TNode *temp = findMin((*t)->Right); // TNode *temp = findMin((*t)->Left)
        (*t)->key = temp->key;
        (*t)->Right = deleteBST(&(*t)->Right, temp->key);
    }
    return *t;
}

void printLNR(Tree t) {
    if (!t) return;
    printLNR(t->Left);
    printf("%d ", t->key);
    printLNR(t->Right);
}

int main() {
    Tree t;
    CreateTree(&t);
    int a[] = {9, 5, 4, 8, 6, 3, 14, 12, 13};

    for (int i = 0; i < 9; i++){
        insertBST(&t, a[i]);
    }

    printf("Cay ban dau: "); printLNR(t);
    printf("\n");

    int del[] = {4, 5, 9};
    for(int i = 0; i< 3; i++) {
        printf("Xoa %d\n", del[i]);
        t = deleteBST(&t, del[i]);
        printf("Sau khi xoa: "); printLNR(t); printf("\n");
    }
}