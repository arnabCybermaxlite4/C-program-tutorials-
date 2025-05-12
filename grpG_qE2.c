#include <stdio.h>

void convertToWords(int n);

int main() {
    int cost;
    printf("Enter the cost of the item in whole numbers: ");
    scanf("%d", &cost);

    if (cost == 0) {
        printf("Zero\n");
    } else {
        convertToWords(cost);
    }

    return 0;
}

void convertToWords(int n) {
    char *ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    char *teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    char *tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    char *hundred = "Hundred";

    if (n >= 100) {
        printf("%s %s ", ones[n / 100], hundred);
        n %= 100;
    }

    if (n >= 10 && n <= 19) {
        printf("%s\n", teens[n - 10]);
    } else {
        if (n >= 20) {
            printf("%s ", tens[n / 10]);
            n %= 10;
        }
        if (n > 0) {
            printf("%s", ones[n]);
        }
        printf("\n");
    }
}