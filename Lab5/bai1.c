#include <stdio.h>
#include <stdlib.h>

typedef struct tagDNode {
    int k;
    struct tagDNode *Pre; 
    struct tagDNode *Next;
} DNode;

typedef struct tagDList {
    DNode *Head;
    DNode *Tail;
} DList;

void CreateList(DList *l) {
    l->Head = NULL;
    l->Tail = NULL;
}

DNode* CreateDNode(int x) {
    DNode *p = (DNode*) malloc(sizeof(DNode));
    p->k = x;
    p->Next = NULL;
    p->Pre = NULL;

    return p;
}

void addTail(DList *l, DNode* n) {
    if (l->Head == NULL) {
        l->Head = n;
        l->Tail = l->Head;
    } else {
        n->Pre = l->Tail;
        l->Tail->Next = n;
        l->Tail = n;
    }
}

void deleteHead(DList *l) {
    if (l->Head == NULL) return;
    if (l->Head == l->Tail) {
        l->Head = l->Tail = NULL;
    } else {
        l->Head = l->Head->Next;
        l->Head->Pre = NULL;
    }
}

void deleteTail(DList *l) {
    if (l->Tail == NULL) return;
    if (l->Head == l->Tail) {
        l->Head = l->Tail = NULL;
    } else {
        l->Tail = l->Tail->Pre;
        l->Tail->Next = NULL;
    }
}

void deleteX(DList *l, int x) {
    DNode *p = l->Head;
    while (p != NULL) {
        if (p->k == x) {
            if (p->Next == NULL && p->Pre == NULL) {
                l->Head = l->Tail = NULL;
            } 
            else if (p->Pre == NULL) {
                l->Head = p->Next;
                l->Head->Pre = NULL;
            }
            else if (p->Next == NULL) {
                l->Tail = p->Pre;
                l->Tail->Next = NULL;
            }
            else {
                p->Pre->Next = p->Next;
                p->Next->Pre = p->Pre;
            }
        }
        p = p->Next;
    }
}

void printList(DList l) {
    DNode *p = l.Head;

    while (p != NULL) {
        printf("%d ", p->k);
        p = p->Next;
    }
    printf("\n");
}

int main() {
    DList l;
    CreateList(&l);
    int a[] = {1, 5, 21, 5, 7, 8};

    for (int i = 0; i < 6; i++) {
        addTail(&l, CreateDNode(a[i]));
        printList(l);
    }

    deleteHead(&l);
    deleteTail(&l);
    printf("List sau khi xoa phan tu dau va cuoi: ");
    printList(l);

    int k; printf("Nhap k: "); scanf("%d", &k);
    deleteX(&l, k);

    printf("List sau khi xoa bo phan tu co gia tri bang %d: ", k);
    printList(l);
}