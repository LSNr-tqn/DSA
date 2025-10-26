#include <stdio.h>
#include <stdlib.h>

typedef struct tagTNode
{
    int key;
    struct tagTNode *Left, *Right;
} TNode;

typedef TNode *Tree;

void CreateTree(Tree *t) { *t = NULL; }

TNode *CreateNode(int x)
{
    TNode *n = (TNode *)malloc(sizeof(TNode));
    if (n == NULL)
    {
        exit(1);
    }
    n->key = x;
    n->Left = NULL;
    n->Right = NULL;
    return n;
}

void addNode(Tree *t, int x)
{
    if (*t == NULL)
        *t = CreateNode(x);
    else if (x < (*t)->key)
        addNode(&((*t)->Left), x);
    else if (x > (*t)->key)
        addNode(&((*t)->Right), x);
}

int countNode(Tree t) {
    return t ? 1 + countNode(t->Left) + countNode(t->Right) : 0;
}

int countLeaves(Tree t) {
    if (!t) return 0;
    if (!t->Left && !t->Right) return 1;
    return countLeaves(t->Left) + countLeaves(t->Right);
}

int countInternal(Tree t) {
    if (!t || (!t->Left && !t->Right)) return 0;
    return 1 + countInternal(t->Left) + countInternal(t->Right);
}

int max(int a, int b) {
    return a > b ? a:b;
}

int height(Tree t) {
    // if (!t) return 0;
    // else {
    //     return 1 + max(height(t->Left), height(t->Right));
    // }
    return t ? 1 + max(height(t->Left), height(t->Right)) : 0; 
}

void inorder(Tree t)
{
    if (!t)
        return;
    inorder(t->Left);
    printf("%d ", t->key);
    inorder(t->Right);
}
int main()
{
    Tree t;
    CreateTree(&t);
    int a[] = {1, 10, 4, 6, 3};

    for (int i = 0; i < 5; i++){
        addNode(&t, a[i]);
    }

    inorder(t);

    printf("\nSo Node cua cay la: %d", countNode(t));
    printf("\nSo la cua cay la: %d", countLeaves(t));
    printf("\nSo Node trong cua cay la: %d", countInternal(t));
    printf("\nChieu cao cua cay la: %d", height(t));
}