#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int data;
    struct Node *Next;
} Node;

typedef struct tagList{
    Node *Head;
    Node *Tail;
    int size;
} List;

void CreateList(List *l) {
    l->Head = NULL;
    l->Tail = NULL;
	l->size = 0;  
}

Node* CreateNode(int x) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = x;
    n->Next = NULL;
    return n;
}

void addHead(List *l, Node* n) {
    if(l->Head == NULL) {
        l->Head = n;
        l->Tail = l->Head;
        l->size++;
    } else {
        n->Next = l->Head;
        l->Head = n;
        l->size++;
    }
}

void addTail(List *l, Node* n) {
    if (l->Head == NULL) {
        l->Head = n;
        l->Tail = l->Head;
        l->size++;
    } else {
        l->Tail->Next = n;
        l->Tail = n;
        l->size++;
    }
}

void printList(List l) {
    Node* n = l.Head;
    while(n != NULL)  {
        printf("%d ", n->data);
        n = n->Next;
    }
}

int findFirst(List  *l, int k) {
    Node* n = l->Head;
    int i = 0;
    while (n != NULL) {
    	i++;
        if (n->data == k) {
            return i;
        }
        n = n->Next; 
    }
    return 0; 
}

int main () {
    List l;
    CreateList(&l);

    int a[] = {1, 10, 3, 5 , 6, 3};
    for (int i = 0; i < 6; i++) {
        addTail(&l, CreateNode(a[i]));
    }

    printList(l);
    printf("\nCo %d phan tu trong danh sach\n", l.size);

    int k;
    printf("Nhap so k: ");
    scanf("%d", &k);
    if (findFirst(&l, k)) {
        printf("Tim thay %d dau tien o vi tri %d", k, findFirst(&l, k));
    } else printf("Khong tim thay %d trong List", k);
}