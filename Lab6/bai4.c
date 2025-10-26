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
    if(!n) exit(1);
    n->key = x;
    n->Left = NULL;
    n->Right = NULL;
    return n;
}

void addNode(Tree *t, int x) {
    if(!*t) *t = CreateNode(x);
    else if(x < (*t)->key) addNode(&((*t)->Left), x);
    else if(x > (*t)->key) addNode(&((*t)->Right), x);
}

int findDFS(Tree t, int x) {
    if(!t) return 0;
    if (t->key == x) return 1;
    return findDFS(t->Left, x) || findDFS(t->Right, x);
}

int main() {
    Tree t;
    CreateTree(&t);
    int a[] = {1, 10, 4, 6, 3};

    for (int i = 0; i < 5; i++){
        addNode(&t, a[i]);
    }

    int k = 10;
    if (findDFS(t, k)) {
        printf("FOUND");
    } else {
        printf("NOT FOUND");
    }
}