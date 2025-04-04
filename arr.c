#include <stdio.h>
int search(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==key)
        {
            printf("Found at position %d ",i+1);
            return 1;
        }
    }
    printf("Nahi mila");
    return -1;
}
int del(int a[], int pos, int size) {
    if (pos >= size || pos < 0) {
        printf("\nInvalid position for deletion.\n");
        return size;
    }
    for (int i = pos; i < size - 1; i++) {
        a[i] = a[i + 1];
    }
    size--;
    for (int i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    
    return size;
}
int main()
{
   int arr[5] = {1,2,3,4,5};
   int key = 4;
   search(arr,5,key);
   del(arr,3,5);

   return 0;
}