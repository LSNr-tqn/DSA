#include <stdio.h>
#include <stdlib.h>

typedef struct tagDNode
{
    int k;
    struct tagDNode *Next;
    struct tagDNode *Pre;
} DNode;

typedef struct tagDList
{
    DNode *Head;
    DNode *Tail;
} DList;

void CreateDList(DList *l)
{
    l->Head = NULL;
    l->Tail = NULL;
}

DNode *CreateDNode(int key)
{
    DNode *n = (DNode *)malloc(sizeof(DNode));
    n->k = key;
    n->Next = NULL;
    n->Pre = NULL;
    return n;
}

void dll_insert_sorted(DList *l, int key)
{
    DNode *n = CreateDNode(key);
    if (l->Head == NULL)
    {
        l->Head = n;
        l->Tail = l->Head;
        return;
    }

    DNode *temp = l->Head;
    // Xet key co lon hon phan tu dau khong
    if (key < temp->k)
    {
        n->Next = l->Head;
        l->Head->Pre = n;
        l->Head = n;
        return;
    }
    // di chuyen temp den vi tri ma so sau no lon hon key
    while (temp->Next != NULL && temp->Next->k < key)
    {
        temp = temp->Next;
    }
    // trung thi bo qua
    if (temp->Next != NULL && temp->Next->k == key) {
        free(n);
        return;
    }

    // bat dau chen vao
    n->Next = temp->Next;
    n->Pre = temp;
    temp->Next = n;

    // Xet xem sau n co Node nao nua khong
    // Neu co thi gan Pre cua no bang Node n
    if (n->Next != NULL)
        n->Next->Pre = n;
    else // Neu khong thi day l.Tall quan ly Node n
        l->Tail = n;
}

void printDList(DList l)
{
    DNode *n = l.Head;
    while (n != NULL)
    {
        printf("%d ", n->k);
        n = n->Next;
    }
    printf("\n");
}

int main()
{
    DList l;
    CreateDList(&l);
    int a[] = {5, 1, 3, 3, 2, 9, 7};

    for (int i = 0; i < 7; i++)
    {
        dll_insert_sorted(&l, a[i]);
    }

    printDList(l);
}