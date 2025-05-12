#include <stdio.h>
#include <math.h>

// Function to validate if three sides can form a triangle
int validate(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1; // Triangle is valid
    } else {
        return 0; // Triangle is not valid
    }
}

// Function to calculate the area of a triangle using Heron's formula
double area(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int a, b, c;

    // Ask user for three sides of the triangle
    printf("Enter three sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    // Validate if the sides can form a triangle
    if (validate(a, b, c)) {
        // Calculate and print the area of the triangle
        double triangle_area = area(a, b, c);
        printf("The area of the triangle is: %.2f\n", triangle_area);
    } else {
        printf("The sides cannot form a valid triangle.\n");
    }

    return 0;
}