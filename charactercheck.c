#include <stdio.h>

int main() {
    char user_input;

    // Ask the user to enter a character
    printf("Enter a character: ");
    scanf(" %c", &user_input);

    // Check the type of character
    if (user_input >= 65 && user_input <= 90) {
        // If the ASCII value is between 65 and 90, it's a capital letter
        printf("You entered a capital letter.\n");
    } else if (user_input >= 97 && user_input <= 122) {
        // If the ASCII value is between 97 and 122, it's a small letter
        printf("You entered a small letter.\n");
    } else if (user_input >= 48 && user_input <= 57) {
        // If the ASCII value is between 48 and 57, it's a digit
        printf("You entered a digit.\n");
    } else {
        // If none of the above, it's a special symbol
        printf("You entered a special symbol.\n");
    }

    return 0;
}