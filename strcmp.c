#include <stdio.h>

// Function to compare two strings lexicographically
int my_strcmp(const char* str1, const char* str2) {
    // Compare each character of both strings
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            // Return the difference in ASCII values if a mismatch is found
            return *str1 - *str2;
        }
        str1++; // Move to the next position in str1
        str2++; // Move to the next position in str2
    }

    // If one string is a prefix of the other, return the difference in lengths
    if (*str1 == '\0' && *str2 != '\0') {
        return -1; // str1 is shorter
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1; // str2 is shorter
    }

    // If all characters match and both strings end at the same time, return 0
    return 0;
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    // Compare str1 and str2
    int result = my_strcmp(str1, str2);

    // Print the result
    if (result < 0) {
        printf("%s is lexicographically smaller than %s\n", str1, str2);
    } else if (result > 0) {
        printf("%s is lexicographically larger than %s\n", str1, str2);
    } else {
        printf("%s and %s are equal\n", str1, str2);
    }

    return 0;
}