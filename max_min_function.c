#include <stdio.h>

// Function to return the minimum of two numbers
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Function to return the maximum of two numbers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2;

    // Ask user for two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call min and max functions
    int minimum = min(num1, num2);
    int maximum = max(num1, num2);

    // Print results
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    return 0;
}