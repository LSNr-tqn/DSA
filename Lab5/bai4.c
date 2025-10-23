#include <stdio.h>
#include <stdlib.h>

typedef struct tagDNode {
    int k;
    struct tagDNode *Next;
    struct tagDNode *Pre;
} DNode;

typedef struct tagDList {
    DNode *Head;
    DNode *Tail;
    int size;
} DList;

void CreateDList(DList *l) {
    l->Head = NULL;
    l->Tail = NULL;
    l->size = 0;
}

DNode* CreateDNode(int x) {
    DNode *n = (DNode*) malloc(sizeof(DNode));
    n->k = x;
    n->Next = NULL;
    n->Pre = NULL;
    return n;
}

void addTail(DList *l, DNode *n) {
    if (l->Head == NULL) {
        l->Head = n;
        l->Tail = l->Head;
    } else {
        n->Pre = l->Tail;
        l->Tail->Next = n;
        l->Tail = n;
    }
    l->size++;
}

DList dll_from_array(int a[], int n) {
    DList l;
    CreateDList(&l);
    for (int i = 0; i < n; i++) {
        addTail(&l, CreateDNode(a[i]));
    }
    return l;
}

int array_from_dll(DList *l, int out[]) {
    DNode *n = l->Head;
    int i = 0;
    while (n != NULL) {
        out[i] = n->k;
        i++;
        n = n->Next;
    }
    return i;
}

void printDList(DList l) {
    DNode *p = l.Head;
    while (p != NULL) {
        printf("%d ", p->k);
        p = p->Next;
    }
    printf("\n");
}

int main() {
    int n = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    DList l = dll_from_array(a, n);
    printf("Array sau khi chuyen sang List: ");
    printDList(l);

    int out[l.size];
    array_from_dll(&l, out);
    printf("List sau khi chuyen sang Array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", out[i]);
    }
}