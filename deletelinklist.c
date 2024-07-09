#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data);
void printList(struct Node* node);
void deleteNode(struct Node** head_ref, int key);

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);

    printf("Original linked list: \n");
    printList(head);

    int key = 30;

    
    deleteNode(&head, key);

    printf("Linked list after deletion of %d: \n", key);
    printList(head);

    return 0;
}

void insertAtEnd(struct Node** head_ref, int new_data) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));


    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head_ref, int key) {
    
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;


    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);               
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) return;

    
    prev->next = temp->next;
    free(temp);
}
