#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int data;
	struct Node* Next;
} Node;

typedef struct tagList {
	Node *Head;
	Node *Tail;
} List;

void CreateList (List *l) {
	l->Head = NULL;
	l->Tail = NULL;
}

Node* CreateNode(int x) {
	Node *n = (Node*) malloc(sizeof(Node));
	
	n->data = x;
	n->Next = NULL;
	
	return n;
}

void addHead(List *l, Node* n) {
	if (l->Head == NULL) {
		l->Head = n;
		l->Tail = l->Head;
	}
	else {
		n->Next = l->Head;
		l->Head = n;
	}
}

void addTail(List *l, Node* n) {
	if (l->Head == NULL) {
		l->Head =  n;
		l->Tail = l->Head;
	}
	else {
		l->Tail->Next = n;
		l->Tail = n;	
	}
}

void printList(List l) {
	Node* n = l.Head;
	
	while (n != NULL) {
		printf("%d ", n->data);
		n = n->Next;
	}
}

int main() {
	List l;
	CreateList(&l);
	for (int i = 0; i<5; i++) {
		addTail(&l, CreateNode(i));
	}
	printList(l);
}