#include <stdio.h>

int main()
{
    int i;
    int arr[] = {1, 5, 3, 99, 56, 36};
    int key = 5;
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position: %d\n", i + 1);
            break;
        }
    }

    if (i == n) 
    {
        printf("Not found\n");
    }

    return 0;
}
