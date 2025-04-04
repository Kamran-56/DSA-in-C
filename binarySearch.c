#include <stdio.h>

int bsearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = bsearch(arr, size, key);

    if (result != -1) {
        printf("Element found at position: %d\n", result+1);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
