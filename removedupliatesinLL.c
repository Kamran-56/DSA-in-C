#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

// Remove duplicates from a sorted linked list
struct node* removeduplicates() {
    struct node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct node* duplicate = temp->next;
            temp->next = temp->next->next;
            free(duplicate);
        } else {
            temp = temp->next;
        }
    }

    return head;
}

// Insert new nodes into the linked list
void insert(struct node** head, int data) {
    struct node* newdata = (struct node*)malloc(sizeof(struct node));
    newdata->data = data;
    newdata->next = *head;
    *head = newdata;
}

// Display linked list
void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    int nodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    for (int i = 0; i < nodes; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original linked list: ");
    display();

    head = removeduplicates();

    printf("Linked list after removing duplicates: ");
    display();

    return 0;
}
