#include <stdio.h>

// Recursive function to calculate nCr
long long nCr(int n, int r) {
    if (r > n) 
        return 0; // Invalid case
    if (r == 0 || n == r) 
        return 1; // Base cases
    
    // Recursive case
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Main function
int main() {
    int n = 5, r = 3; // Example values for n and r
    long long result = nCr(n, r); // Call nCr function
    printf("%lld\n", result); // Print the result
    return 0;
}