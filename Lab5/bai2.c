#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagDNode {
    int MaSV;
    char Ten[50];
    char Khoa[100];
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

DNode* CreateDNode(int Ma,char Name[50], char Kh[100]) {
    DNode *p = (DNode*) malloc(sizeof(DNode));
    if (p == NULL) {
        printf("Khong du bo nho"); exit(1);
    }
    p->MaSV = Ma;
    strcpy(p->Ten, Name);
    strcpy(p->Khoa, Kh);
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
    if (l->Head == NULL) printf("\nList rong khong the xoa them\n");
    if (l->Head == l->Tail) {
        l->Head = l->Tail = NULL;
        printf("\nDa xoa xong\nList rong\n");
    } else {
        l->Head = l->Head->Next;
        l->Head->Pre = NULL;
    }
}

void deleteTail(DList *l) {
    if (l->Tail == NULL) printf("\nList rong khong the xoa them\n");
    if (l->Head == l->Tail) {
        l->Head = l->Tail = NULL;
        printf("\nDa xoa xong\nList rong\n");
    } else {
        l->Tail = l->Tail->Pre;
        l->Tail->Next = NULL;
    }
}

void deleteX(DList *l, int x) {
    DNode *p = l->Head;
    while (p != NULL) {
        if (p->MaSV == x) {
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
    int n = 0;
    if (p == NULL) {
        printf("\nList rong\n");
        return;
    }
    while (p != NULL) {
        n++;
        printf("SV %d\n", n);
        printf("MaSV: %d\n", p->MaSV);
        printf("Ten: %s\n", p->Ten);
        printf("Khoa: %s\n", p->Khoa);
        p = p->Next;
    }
    printf("\n");
}

int main() {
    DList l;
    CreateList(&l);
    int n;
    printf("Nhap so luong SV muon nhap vao: "); scanf("%d", &n);
    int MaSV;
    char Name[50];
    char Khoa[100];
    int i = 0;
    while (n != 0) {
        i++;
        printf("Nhap thong tin cho SV %d:\n", i);
        printf("MaSV: "); scanf("%d", &MaSV);
        getchar();
        printf("Ten: "); fgets(Name, sizeof(Name), stdin);
        Name[strcspn(Name, "\n")] = '\0';
        printf("Khoa: "); fgets(Khoa, sizeof(Khoa), stdin);
        Khoa[strcspn(Khoa, "\n")] = '\0';
        addTail(&l, CreateDNode(MaSV, Name, Khoa));
        n--;
    }
    printList(l);

    deleteHead(&l);
    deleteTail(&l);
    printf("List sau khi xoa phan tu dau va cuoi: ");
    printList(l);

    int k; printf("Nhap k: "); scanf("%d", &k);
    deleteX(&l, k);

    printf("List sau khi xoa bo phan tu co gia tri bang %d: ", k);
    printList(l);
}