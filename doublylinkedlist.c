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

void display() {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void displayback(){
    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    
}

int main() {
    insert(&head, 5, 1);
    insert(&head, 3, 2);
    display();
    printf("\n");
    displayback();
    return 0;
}
