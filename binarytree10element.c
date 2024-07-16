#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void inOrderTraversal(Node* root, int* count) {
    if (root == NULL) return;

    inOrderTraversal(root->left, count);

    (*count)++;
    if (*count == 10) {
        printf("10th element: %d\n", root->data);
    }

    inOrderTraversal(root->right, count);
}

int main() {
   
    Node* root = createNode(10);
    root->left = createNode(8);
    root->right = createNode(7);
    root->left->left = createNode(6);
    root->left->right = createNode(1);
    root->right->left = createNode(2);
    root->right->right = createNode(18);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(16);
    root->left->right->left = createNode(15);

    int count = 0;
    inOrderTraversal(root, &count);

    return 0;
}