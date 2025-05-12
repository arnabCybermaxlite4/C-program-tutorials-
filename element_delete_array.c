#include <stdio.h>

// Function to delete an element from an array
void delete_element(int arr[], int* size, int pos) {
    // Validate the position
    if (pos < 0 || pos >= *size) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the left
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Update the size of the array
    (*size)--;

    printf("Element deleted successfully\n");
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    printf("Original array: ");
    print_array(arr, size);

    int pos;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);

    delete_element(arr, &size, pos);

    printf("Updated array: ");
    print_array(arr, size);

    return 0;
}