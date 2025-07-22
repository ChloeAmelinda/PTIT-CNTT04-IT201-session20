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

int countLeaves(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        // Đây là một lá
        return 1;
    }

    // Đệ quy kiểm tra cả hai nhánh
    return countLeaves(root->left) + countLeaves(root->right);
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

    preOrder(root);
    printf("\n");
    printf("count leaves: %d\n", countLeaves(root));


    return 0;
}