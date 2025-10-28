#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

typedef Node *Tree;

void createTree(Tree *t) {*t = NULL;}

Node* createNode(int x) {
    Node *n= (Node*) malloc(sizeof(Node));
    if(!n) exit(1);
    n->key = x;
    n->left = n->right = NULL;
    return n;
}

void insertBST(Tree *t, int x) {
    if (!(*t)) {
        *t = createNode(x);
        return;
    } else if (x < (*t)->key) insertBST(&(*t)->left, x);
    else if (x > (*t)->key) insertBST(&(*t)->right, x);
}

Node* searchBST(Tree t, int x) {
    if (!t || t->key == x) return t;
    return x < t->key ? searchBST(t->left, x) : searchBST(t->right, x);
}

Node* minNode(Tree t) {
    while(t && t->left) t = t->left;
    return t;
}

int isBST(Tree t) {
    if (t->left->key > t->key || t->right->key < t->key) return 0;
    else return 1;
    return isBST(t->left) && isBST(t->right);
}

Node* deleteBST(Tree *t, int x) {
    if (!(*t)) return NULL;
    if (x < (*t)->key) (*t)->left = deleteBST(&(*t)->left, x);
    else if (x > (*t)->key) (*t)->right = deleteBST(&(*t)->right, x);
    else {
        if(!(*t)->left) {
            Node *temp = (*t)->right;
            free(*t);
            return temp;
        }
        if(!(*t)->right) {
            Node *temp = (*t)->left;
            free(*t);
            return temp;
        }
        Node *temp = minNode((*t)->right);
        (*t)->key = temp->key;
        (*t)->right = deleteBST(&(*t)->right, temp->key);

    }
    return *t;
}

void inorder(Tree t) {
    if(!t) return;
    inorder(t->left);
    printf("%d ", t->key);
    inorder(t->right);
}

int main() {
    Tree t;
    createTree(&t);
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i =0; i<7; i++) insertBST(&t, a[i]);

    if (isBST(t)) printf("\nDay la 1 BST");
    t = deleteBST(&t, 50);
    printf("\nInorder sau khi xoa 50: "); inorder(t);
}