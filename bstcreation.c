#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;

}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    else {
        return root;
    }

    return root;
}

void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 14);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 18);
    root = insertNode(root, 6);
    root = insertNode(root, 21);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 14);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 18);

    printf("Inorder Traversal :");
    printInorder(root);
    printf("\n");

    printf("Preorder Traversal :");
    printPreorder(root);
    printf("\n");

    return 0;
}