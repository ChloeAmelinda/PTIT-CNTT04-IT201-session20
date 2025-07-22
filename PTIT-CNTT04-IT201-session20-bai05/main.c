#include <stdio.h>
#include <stdlib.h>

typedef  struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode( int capacity) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed in insert()\n");
        exit(0);
    }
    temp->data = capacity;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int findMax(Node* root) {
    if (root == NULL) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;

    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(void) {
    int n=0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);
    printf("Max: %d\n", findMax(root));
    preOrder(root);

    return 0;
}