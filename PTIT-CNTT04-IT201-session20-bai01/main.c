#include <stdio.h>
#include <stdlib.h>

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
int main(void) {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);

    return 0;
}