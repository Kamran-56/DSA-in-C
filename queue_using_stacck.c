#include <stdio.h>
#define size 5

int stack[size], stack2[size];
int top = -1;  

void push() {
    if (top >= size - 1) {
        printf("Queue overflow\n");
        return;
    }
    int data;
    printf("Enter element to push: ");
    scanf("%d", &data);
    stack[++top] = data;
}

void pop() {
    if (top == -1) {
        printf("Queue underflow\n");
        return;
    }
    
    for (int i = 0; i <= top; i++) {
        stack2[i] = stack[top - i];
    }
    for (int i = 0; i <=top; i++)
    {
        printf("%d ",stack[i]);
    }
    
   
    printf("Popped element: %d\n", stack2[top]);
    top--;  
    
   
    for (int i = 0; i <= top; i++) {
        stack[i] = stack2[top - i];
    }
}


void display() {
    if (top == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    for (int i = 0; i < size; i++) {
        push();
    }
    printf("Initial Queue: ");
    display();
    
    pop();  
    printf("Queue after pop: ");
    display();
    
    return 0;
}
