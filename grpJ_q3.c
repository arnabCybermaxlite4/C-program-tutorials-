#include <stdio.h>

int main() {
    FILE *marksFile, *resultFile;
    int roll_no, paper1, paper2, paper3, total_marks;
    int num_students;

    // Step 1: Create "marks" file and get input
    marksFile = fopen("marks.txt", "w");
    if (marksFile == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &roll_no);
        printf("Marks in Paper I: ");
        scanf("%d", &paper1);
        printf("Marks in Paper II: ");
        scanf("%d", &paper2);
        printf("Marks in Paper III: ");
        scanf("%d", &paper3);

        // Write to marks file
        fprintf(marksFile, "%d %d %d %d\n", roll_no, paper1, paper2, paper3);
    }
    fclose(marksFile);

    // Step 2: Open "marks" file for reading and "result" file for writing
    marksFile = fopen("marks.txt", "r");
    resultFile = fopen("result.txt", "w");
    if (marksFile == NULL || resultFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Step 3: Read from "marks" and write to "result"
    fprintf(resultFile, "Roll_No Paper_I Paper_II Paper_III Total_Marks\n");
    while (fscanf(marksFile, "%d %d %d %d", &roll_no, &paper1, &paper2, &paper3) != EOF) {
        total_marks = paper1 + paper2 + paper3;
        fprintf(resultFile, "%d %d %d %d %d\n", roll_no, paper1, paper2, paper3, total_marks);
    }

    // Close files
    fclose(marksFile);
    fclose(resultFile);

    printf("Data has been successfully written to 'result.txt'.\n");

    return 0;
}