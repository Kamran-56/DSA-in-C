#include <stdio.h>

void delete_at_inedx(int arr[],int size,int index){
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    
}

void delete_at_start(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    
}

void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
int main()
{
   int arr[5] = {1,2,3,4,5};
   int size = 5;
    printf("Before deleteion array : ");
    display(arr,size);
    delete_at_inedx(arr,size,3);
    size--;
    printf("\nAfter deletion : ");
    display(arr,size);
    delete_at_start(arr,size);
    size--;
    printf("\nAfter deletion : ");
    display(arr,size);
    printf("\n%d",size);
   return 0;
}