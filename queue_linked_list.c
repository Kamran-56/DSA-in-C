#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next; 
};

struct node* front = NULL;
struct node* rear = NULL;

struct node* add(struct node *rear) {
    struct node* temp = malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = rear->next;
    }
    return rear;
}

void display() {
    struct node* temp = front; 
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int elements;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &elements);

    for (int i = 0; i < elements; i++) {
        rear = add(rear);
    }

    display();
    return 0;
}
