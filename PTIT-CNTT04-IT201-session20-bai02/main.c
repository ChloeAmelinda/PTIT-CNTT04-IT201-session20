#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//duyet
void preOrder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);

}
void inOrder(Node *node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}
void postOrder(Node *node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}
//levelOder
typedef struct Queue {
    Node* item[MAX_QUEUE];
    int front, rear;
}Queue;
void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}
int isQueueEmpty(Queue *queue) {
    return queue->rear == queue->front;
}
int isQueueFull(Queue *queue) {
    return queue->rear == MAX_QUEUE;
}
void enQueue(Queue *queue,Node *node) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->item[queue->rear++]= node;
}
Node *deQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->item[queue->front++];
}
void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, root);
    while (!isQueueEmpty(&queue)) {
        Node *node = deQueue(&queue);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enQueue(&queue, node->left);
        }
        if (node->right != NULL) {
            enQueue(&queue, node->right);
        }
    }
}
int main(void) {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);
    printf("Pre-order traversal:\n");
    preOrder(root);
    printf("\n");
    printf("In-order traversal:\n");
    inOrder(root);
    printf("\n");
    printf("Post-order traversal:\n");
    postOrder(root);
    printf("\n");
    printf("Level order traversal:\n");
    levelOrder(root);
    return 0;
}