 #include <stdio.h>

int main() {
    int daysLate;

    // Input: Get the number of days the book is late
    printf("Enter the number of days the book is late: ");
    scanf("%d", &daysLate);

    // Check conditions for fines
    if (daysLate > 30) {
        printf("Your membership is canceled due to late return.\n");
    } else if (daysLate > 10) {
        printf("The fine for returning the book late is Rs. 5.\n");
    } else if (daysLate >= 6) {
        printf("The fine for returning the book late is Rs. 2.\n");
    } else if (daysLate >= 1) {
        printf("The fine for returning the book late is Rs. 1.\n");
    } else {
        // No fine for returning on time or not late
        printf("No fine. The book is returned on time.\n");
    }

    return 0;
}