#include <stdio.h>
#define SIZE 5
int top = -1;
int stack[SIZE];

void push(int top){
    if (top>SIZE)
    {
        printf("Error: Stack Overflow");
    }
    
    printf("Enter an element you want to push : ");
    int data;
    scanf("%d",&data);
    stack[top] = data;
}

int main()
{
    while (top<SIZE)
    {

        top++;
        push(top);
    }
    
   
   for (int i = 0; i < top; i++)
   {
        printf("\nElement in stack at position %d is: %d ",i+1,stack[i]);
   }
   
   return 0;
}