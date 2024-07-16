#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to find the length of a circular linked list
int findLength(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Find the meeting point of the slow and fast pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // If the list is not circular, return 0
    if (fast == NULL || fast->next == NULL) {
        return 0;
    }

    // Count the length of the list
    int length = 0;
    do {
        slow = slow->next;
        length++;
    } while (slow != fast);

    return length;
}

int main() {
    // Create a circular linked list
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    head->next = node2;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 3;
    node2->next = node3;

    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->data = 4;
    node3->next = node4;

     Node* node5 = (Node*)malloc(sizeof(Node));
    node5->data = 5;
    node4->next = node5;

    node5->next = head; // Make the list circular

    int length = findLength(head);
    printf("Length of the circular linked list: %d\n", length);

    return 0;
}