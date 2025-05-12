#include <stdio.h>

// Function to copy a string from source to destination
char* my_strcpy(char* dest, const char* src) {
    char* original_dest = dest; // Store the original destination pointer

    // Copy each character from src to dest
    while (*src != '\0') {
        *dest = *src; // Copy character
        dest++;       // Move to the next position in dest
        src++;        // Move to the next position in src
    }

    *dest = '\0'; // Null-terminate the destination string
    return original_dest; // Return the original destination pointer
}

int main() {
    char source[] = "Hello, World!";
    char destination[50]; // Ensure enough space for the copied string

    // Copy source to destination
    my_strcpy(destination, source);

    // Print the copied string
    printf("Copied String: %s\n", destination);

    return 0;
}