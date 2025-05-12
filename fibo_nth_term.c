#include <stdio.h>

int main() {
    int n; // number of terms
    int a = 0; // first term
    int b = 1; // second term
    int temp; // temporary variable

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    printf("%d %d ", a, b); // print initial terms

    for (int i = 2; i < n; i++) {
        temp = a + b; // calculate next term
        a = b; // update a
        b = temp; // update b
        printf("%d ", temp ); // print next term
    }
    
    return 0;
}