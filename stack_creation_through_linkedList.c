#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head;

struct node* push(struct node* top, int data) {
    struct node* temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return top;
    }
    temp->data = data;
    temp->link = top;
    return temp; 
}


void display() {
    struct node* temp = head; 
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    head = NULL;
    int elements, data;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &elements);

    for (int i = 0; i < elements; i++) {
        printf("Enter element to be pushed at position %d: ", i);
        scanf("%d", &data);
        head = push(head, data); 
    }

    display();

    return 0;
}
