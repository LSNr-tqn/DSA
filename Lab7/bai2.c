#include <stdio.h>
#include <stdlib.h>

typedef struct tagTNode {
    int key;
    struct tagTNode *left, *right;
} TNode;

typedef TNode *Tree;

typedef struct tagQueueNode {
    TNode *node;
    struct tagQueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

void createQueue(Queue *q) {q->front = q->rear = NULL;}
int isEmptyQueue(Queue q) {return q.front == NULL;}
void enQueue(Queue *q, TNode *x) {
    QueueNode *qn = (QueueNode*) malloc(sizeof(QueueNode));
    qn->node = x;
    qn->next = NULL;
    if (q->rear == NULL) {
        q->front = qn;
        q->rear = q->front;
    }
    else {
        q->rear->next = qn;
        q->rear = qn;
    }
}

TNode* deQueue(Queue *q) {
    if (isEmptyQueue(*q)) return NULL;
    QueueNode *temp = q->front;
    TNode *n = temp->node;
    q->front = q->front->next;
    if(!q->front) q->rear = NULL;
    free(temp);
    return n;
}

void createTree(Tree *t) {*t = NULL;}

TNode* createNode(int x) {
    TNode *n = (TNode*) malloc(sizeof(TNode));
    if(!n) exit(1);
    n->key = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TNode* addNode(Tree *t, int x) {
    if (!(*t)) {
        *t = createNode(x);
        return *t;
    } else if (x < (*t)->key) addNode(&(*t)->left, x);
    else if (x > (*t)->key) addNode(&(*t)->right, x);
}

void NLR(Tree t) {
    if (!t) return;
    printf("%d ", t->key);
    NLR(t->left);
    NLR(t->right);
}

void LNR(Tree t) {
    if(!t) return;
    LNR(t->left);
    printf("%d ", t->key);
    LNR(t->right);
}

void LRN(Tree t) {
    if(!t) return;
    LRN(t->left);
    LRN(t->right);
    printf("%d ", t->key);
}

void BFS(Tree t) {
    if (!t) return;
    Queue q;
    createQueue(&q);
    enQueue(&q, t);

    while (!isEmptyQueue(q)) {
        TNode *temp = deQueue(&q);
        printf("%d ", temp->key);
        if(temp->left) enQueue(&q, temp->left);
        if(temp->right) enQueue(&q, temp->right);
    }
}

int countLeaves(Tree t) {
    if (!t) return 0;
    if(!t->left && !t->right) return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int max(int a, int b) {return a > b ? a : b;}

int height(Tree t) {
    if(!t) return 0;
    return 1 + max(height(t->left), height(t->right));
}

int main() {
    Tree t;
    createTree(&t);
    int a[] = {10, 5, 15, 3, 7, -1, 18};
    for (int i = 0; i< 7; i++) {
        addNode(&t, a[i]);
    }

    printf("\nNLR: "); NLR(t);
    printf("\nLNR: "); LNR(t);
    printf("\nLRN: "); LRN(t);
    printf("\nBFS: "); BFS(t);
    printf("\nSo la cua cay: %d", countLeaves(t));
    printf("\nChieu cao cua cay: %d", height(t));
}