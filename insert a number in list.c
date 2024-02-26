#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int number;
    printf("Enter a number to insert at the beginning: ");
    scanf("%d", &number);
    head = insertAtBeginning(head, number);
    printf("Initial List: ");
    displayList(head);
    printf("Enter another number to insert at the beginning: ");
    scanf("%d", &number);
    head = insertAtBeginning(head, number);
    printf("List after inserting at the beginning: ");
    displayList(head);
    return 0;
}

