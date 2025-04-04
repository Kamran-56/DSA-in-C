#include <stdio.h>

int search(int a[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            printf("\nElement found at position %d\n", i + 1);
            return i;
        }
    }
    printf("\nElement not found.\n");
    return -1;
}

void display(int a[], int size) {
    printf("Elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
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
    display(a, size);
    return size;
}

int delwv(int a[], int num, int size) {
    int pos = search(a, size, num);
    if (pos != -1) {
        size = del(a, pos, size);
    }
    return size;
}

int delb(int a[], int size) {
    // Delete first element
    size = del(a, 0, size);
    return size;
}

int delta(int a[], int size) {
    // Delete last element
    size = del(a, size - 1, size);
    return size;
}

int main() {
    int n;
    printf("Enter size of integer array: ");
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element at %d index: ", i);
        scanf("%d", &a[i]);
    }

    display(a, n);
    
    // Uncomment the functions you'd like to test
    // search(a, n, 12);
    // n = del(a, 2, n);
    // n = delwv(a, 12, n); // Example of deleting specific value
    // n = delb(a, n); // Delete first element
    n = delta(a, n); // Delete last element

    return 0;
}
