#include <stdio.h>
void print_table(int n); // function prototype
int main() {
    int n;
    printf("enter a number which you want to print table:\n");
    scanf("%d", &n);
    print_table(n); // function call
    return 0;
}
void print_table (int n) { // function definition
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}
// This program takes an integer input from the user and prints its multiplication table from 1 to 10 using a function.