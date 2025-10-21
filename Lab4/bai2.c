#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tagNode {
	int heso;
	int mu;
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

Node* CreateNode(int x, int a) {
	Node *n = (Node*) malloc(sizeof(Node));
	
	n->heso = x;
	n->mu = a;
	n->Next = NULL;
	return n;
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

void printPoly(List l) {
	Node* n = l.Head;
	
	int first = 1;
	while (n != NULL) {
		int a = n->heso;
		int b = n->mu;
		
		
		// bo qua neu he so bang 0
		if(a == 0){
			n = n->Next;
			continue;
		}
		
		
		// in dau
		if (first) {
			if(a<0) printf("-");
		} else {
			if(a<0) printf(" - ");
			else printf(" + ");
		}
		
		int ab = abs(a);
		
		if(b == 0) {
			printf("%d", ab);
		} else if(b == 1) {
			if (ab == 1) printf("x");
			else printf("%dx", ab);
		} else {
			if (ab == 1) printf("x^%d", b);
			else printf("%dx^%d", ab, b);
		}
		
		first = 0;
		n = n->Next;
	}
	
	printf("\n");
}

int main() {
	List l;
	CreateList(&l);
	char str[1001];
	if (!fgets(str, sizeof(str), stdin)) return 0;
	str[strcspn(str, "\n")] = '\0';
	int length = strlen(str);
	int i = 0;
	
	while (i < length) {
		while (i < length && isspace((unsigned char)str[i])) i++; // bo dau cach
		
		if (i > length) break;
		
		int sign = 1;
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') sign = -1;
			i++;
			while (i < length && isspace((unsigned char)str[i])) i++;
		}
		
		int num_read = 0;
		int num = 0;
		int startnum = i;
		while (i < length && isdigit((unsigned char)str[i])) {
			num = num*10 + (str[i] - '0');
			i++;
			num_read = 1;
		}
		
		int hasX = 0;
		int mu = 0;
		
		if (i < length && (str[i] == 'x' || str[i] == 'X')) {
			hasX = 1;
			i++; // bo qua x
			
			if(i < length && str[i] == '^') {
				i++;
				int signmu = 0;
				if (i < length && str[i] == '-') {
					signmu = 1;
					i++;
				}
				
				if (i>=length && !isdigit((unsigned char)str[i])) mu = 1; // sai dinh dang
				else {
					while (i<length && isdigit((unsigned char)str[i])) {
						mu = mu*10 + (str[i] - '0');
						i++;
					}
					
					if (signmu == 1) mu*= -1;
				}
			} else mu = 1;
		}
		
		if (hasX) { // co x
			if(num_read) num = num * sign; // co he so
			else num = 1*sign;
		} else {// khong x
			if (num_read) num = num * sign; // co he so
			else {
				i++;
				continue;
			}
			mu = 0;
		}
		
		addTail(&l, CreateNode(num, mu));
	}
	
	printPoly(l);
}