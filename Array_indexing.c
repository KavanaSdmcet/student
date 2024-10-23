#include <stdio.h>

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void accessElement(int *arr, int index) {
    printf("Element at index %d: %d\n", index, *(arr + index));
}

void modifyElement(int *arr, int index, int newValue) {
    *(arr + index) = newValue;
    printf("Modified element at index %d: %d\n", index, *(arr + index));
}

void deleteElement(int *arr, int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    (*size)--;
    printf("Array after deletion: ");
    displayArray(arr, *size);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    printf("Original array: ");
    displayArray(arr, size);
    // Accessing an element
    accessElement(arr, 3);
    // Modifying an element
    modifyElement(arr, 3, 99);
    // Deleting an element
    deleteElement(arr, &size, 4);
    return 0;
}
