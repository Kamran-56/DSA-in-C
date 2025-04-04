#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void insert(struct node **head, int data, int position) {
    int k = 1; // to keep track of position
    struct node *newnode;
    struct node *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory error: node not found");
        return;
    }

    newnode->data = data;

    if (position == 1) {
        newnode->next = *head;
        newnode->prev = NULL;
        if (*head) {
            (*head)->prev = newnode;
        }
        *head = newnode;
        return;
    }

    temp = *head;
    while ((k < position - 1) && temp != NULL) {
        temp = temp->next;
        k++;
    }

    if (temp == NULL) {
        printf("Desired position does not exist.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void delete(struct node **head, int position) {
    struct node *p;
    struct node *q;
    p = *head;
    int k = 1;
    
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        *head = (*head)->next;
        if (*head) {
            (*head)->prev = NULL;  // Ensure that the new head's previous is NULL
        }
        free(p);
        return;
    }

    while (p != NULL && k < position) {
        p = p->next;
        k++;
    }

    if (p == NULL) {
        printf("Position not found\n");
        return;
    }

    q = p->prev;
    q->next = p->next;
    if (p->next) {
        p->next->prev = q;
    }
    free(p);
}

void display() {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayback() {
    struct node* ptr = head;
    if (ptr == NULL) return;  // check if the list is empty

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    insert(&head, 5, 1);
    insert(&head, 3, 2);
    insert(&head, 8, 3);
    insert(&head, 10, 4);

    printf("Forward display:\n");
    display();

    delete(&head, 3);
    
    printf("Forward display after deletion:\n");
    display();

    printf("Backward display:\n");
    displayback();

    return 0;
}
