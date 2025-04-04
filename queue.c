#include <stdio.h>
#define SIZE 5

int front = -1, rear = -1;
int queue[SIZE];

void add() {
    int data;
    if (rear == SIZE-1 ) { 
        printf("Queue overflowed\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        printf("Enter data to be added: ");
        scanf("%d", &data);
        queue[rear] = data;
    }
}

void delete(){
    front++;
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n"); 
}

int main() {
    int choice;
    while (rear<SIZE-1)
    {
        
        add();
    }
    display();
    delete();
    printf("\n");
    display();
    return 0;
}
