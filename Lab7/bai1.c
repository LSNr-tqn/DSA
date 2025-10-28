#include <stdio.h>
#include <stdlib.h>

typedef struct tagTNode {
    int k;
    struct tagTNode *left, *right;
} TNode;

typedef TNode *Tree;

void CreateTree(Tree *t) {
    (*t) = NULL;
}

TNode* CreateNode(int x) {
    TNode *n = (TNode*) malloc(sizeof(TNode));
    if(!n) exit(1);
    n->k = x;
    n->left = NULL;
    n->right = NULL;
    return n; 
}

void addNode(Tree *t, int x) {
    if (!(*t)) {
        *t = CreateNode(x);
    }
    if (x < (*t)->k) addNode(&(*t)->left, x);
    else if (x > (*t)->k) addNode(&(*t)->right, x);
}

TNode* searchNode(Tree t, int x) {
    if (!t || t->k == x) return t;
    return x < t->k ? searchNode(t->left, x) : searchNode(t->right, x);
}

TNode* findMin(Tree t) {
    while(t && t->left) t = t->left;
    return t;
}

TNode* deleteNode(Tree *t, int x) {
    if(!t) return NULL;
    if (x < (*t)->k) (*t)->left = deleteNode(&(*t)->left, x);
    else if (x > (*t)->k) (*t)->right = deleteNode(&(*t)->right, x);
    else {
        if (!(*t)->left) {
            TNode *temp = (*t)->right;
            free(*t);
            return temp;
        } else if (!(*t)->right) {
            TNode *temp = (*t)->left;
            free(*t);
            return temp;
        }

        TNode* temp = findMin((*t)->right);

        (*t)->k = temp->k;
        (*t)->right = deleteNode(&(*t)->right, temp->k);
    }
    return  *t;
}

void NLR(Tree t) {
    if(!t) return;
    printf("%d ", t->k);
    NLR(t->left);
    NLR(t->right);
}

void LNR(Tree t) {
    if(!t) return;
    LNR(t->left);
    printf("%d ", t->k);
    LNR(t->right);
}

void LRN(Tree t) {
    if(!t) return;
    LRN(t->left);
    LRN(t->right);
    printf("%d ", t->k);
}

int main() {
    Tree t;
    CreateTree(&t);

    int a[] = {10, 4, 6, 8, 12, 1, 2};
    for (int i = 0; i<7; i++) {
        addNode(&t, a[i]);
    }

    if (searchNode(t, 5)) printf("FOUND");
    else printf("NOT FOUND");

    t = deleteNode(&t, 4);
    printf("\nCay sau khi xoa 4 theo NLR: ");
    NLR(t);
    t = deleteNode(&t, 10);
    printf("\nCay sau khi xoa 10 LNR: "); LNR(t);
    t = deleteNode(&t, 1);
    printf("\nCay sau khi xoa 1 LRN: "); LRN(t);
}