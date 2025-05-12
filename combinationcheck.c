#include <stdio.h>

int main() {
    char chars[] = {'a', 'b', 'c'};
    int i, j, k;

    // Loop through each possible combination
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%c%c%c\n", chars[i], chars[j], chars[k]);
            }
        }
    }

    return 0;
}