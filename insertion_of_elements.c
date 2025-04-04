#include <stdio.h>

void insert_at_beginning(int *arr,int *size,int value){
    
    for (int i = *size; i >=0; i--)
    {
        arr[i+1] = arr[i];
    }
    (*size)++;
    arr[0] = value;
}

void insertion_at_end(int *arr,int *size,int value){
    (*size)++;
    arr[*size-1] = value;
    
}

void insert_at_mid(int *arr, int *size, int value, int index) {
    
    for (int i = *size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
    (*size)++;
}
void display(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Before insertion, array : ");
    display(arr,size);
    printf("\nAfter insertion : ");
    insert_at_beginning(arr,&size,9);
    // size++;
    display(arr,size);
    printf("\nAfter insertion : ");
    insertion_at_end(arr,&size,6);
    display(arr,size);
    printf("\nAfter insertion : ");
    insert_at_mid(arr,&size,6,3);
    display(arr,size);
    
    return 0;
}