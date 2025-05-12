#include <stdio.h>
#include <stdlib.h>

char *str, *str1, *str2, *cpy_str;
int size;

int len(char *s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

void rev()
{
    int i, temp;
    int length = len(str1);
    for (i = 0; i < length / 2; i++)
    {
        temp = str1[i];
        str1[i] = str1[length - i - 1];
        str1[length - i - 1] = temp;
    }
    printf("Reversed String is: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void cpy()
{
    int i;
    int length = len(str1);
    cpy_str = (char *)malloc((length + 1) * sizeof(char));
    if (cpy_str == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    for (i = 0; i < length; i++)
    {
        cpy_str[i] = str1[i];
    }
    cpy_str[i] = '\0';
    printf("Copied String is: %s\n", cpy_str);
    free(cpy_str);
}

void concat()
{
    int i, j;
    int length1 = len(str1);
    printf("Enter the Second String: ");
    getchar(); 
    i = 0;
    char ch;
    str2 = (char *)malloc(1 * sizeof(char));
    if (str2 == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str2[i++] = ch;
        str2 = (char *)realloc(str2, (i + 1) * sizeof(char));
        if (str2 == NULL)
        {
            printf("Memory Allocation Failed\n");
            return;
        }
    }
    str2[i] = '\0';
    str1 = (char *)realloc(str1, (length1 + len(str2) + 1) * sizeof(char));
    if (str1 == NULL)
    {
        printf("Memory Allocation Failed\n");
        free(str2);
        return;
    }
    str1[length1] = ' ';
    length1++;
    for (j = 0; str2[j] != '\0'; j++, length1++)
    {
        str1[length1] = str2[j];
    }
    str1[length1] = '\0';
    printf("Concatenated String is: %s\n", str1);
    free(str2);
}

void sort()
{
    int i, j, length = len(str1);
    char temp;
    for (i = 0; i < length - 1; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (str1[i] > str1[j])
            {
                temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }
    printf("Sorted String is: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void slice()
{
    int i, j, start, end;
    int length = len(str1);
    printf("Enter the Starting Index: ");
    scanf("%d", &start);
    printf("Enter the Ending Index: ");
    scanf("%d", &end);
    if (start < 0 || start >= length || end < 0 || end >= length || start > end)
    {
        printf("Invalid Index\n");
        return;
    }
    str2 = (char *)malloc((end - start + 2) * sizeof(char));
    if (str2 == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    for (i = start, j = 0; i <= end; i++, j++)
    {
        str2[j] = str1[i];
    }
    str2[j] = '\0';
    printf("Sliced String is: %s\n", str2);
    free(str2);
}

void frequency()
{
    int i, j, count;
    int length = len(str1);
    for (i = 0; i < length; i++)
    {
        count = 1;
        if (str1[i] != '0')
        {
            for (j = i + 1; j < length; j++)
            {
                if (str1[i] == str1[j])
                {
                    count++;
                    str1[j] = '0';
                }
            }
            printf("Frequency of %c is: %d\n", str1[i], count);
        }
    }
}

void freq_particular()
{
    int i, count = 0;
    char ch;
    int length = len(str1);
    printf("Enter the Character to find its Frequency: ");
    scanf(" %c", &ch);
    for (i = 0; i < length; i++)
    {
        if (str1[i] == ch)
        {
            count++;
        }
    }
    printf("Frequency of %c is: %d\n", ch, count);
}

void palindrome()
{
    int i, j, length = len(str1);
    for (i = 0, j = length - 1; i < length / 2; i++, j--)
    {
        if (str1[i] != str1[j])
        {
            printf("Not a Palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}

int main()
{
    int choice;
    int i = 0;
    char ch, *temp;
    size = 1;
    str = (char *)malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    printf("Enter a string (press Enter to finish): ");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[i++] = ch;
        size++;
        temp = (char *)realloc(str, size * sizeof(char));
        if (temp == NULL)
        {
            printf("Memory Allocation Failed");
            free(str);
            return 1;
        }
        str = temp;
    }
    if (i == 0)
    {
        printf("Empty string entered.\n");
        free(str);
        return 1;
    }
    str[i] = '\0';
    str1 = (char *)malloc((len(str) + 1) * sizeof(char));
    if (str1 == NULL)
    {
        printf("Memory Allocation Failed\n");
        free(str);
        return 1;
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        str1[i] = str[i];
    }
    str1[i] = '\0';

    do
    {
        printf("=====================================\n");
        printf("        STRING OPERATIONS MENU       \n");
        printf("=====================================\n");
        printf(" -> 1.Reverse the String\n");
        printf(" -> 2.Length of the String\n");
        printf(" -> 3.Copy the String\n");
        printf(" -> 4.Concatenate two Strings\n");
        printf(" -> 5.Sort the String\n");
        printf(" -> 6.Slice the String\n");
        printf(" -> 7.Frequency of Characters\n");
        printf(" -> 8.Frequency of a Particular Character\n");
        printf(" -> 9.Palindrome Check\n");
        printf(" -> 10.Exit\n");
        printf("=====================================\n");
        printf("Enter your choice(1-10): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            rev();
            break;
        case 2:
            printf("Length of the String is: %d\n", len(str1));
            break;
        case 3:
            cpy();
            break;
        case 4:
            concat();
            break;
        case 5:
            sort();
            break;
        case 6:
            slice();
            break;
        case 7:
            frequency();
            break;
        case 8:
            freq_particular();
            break;
        case 9:
            palindrome();
            break;
        case 10:
            printf("Exiting From the CODE\n");
            break;
        default:
            printf("Wrong Choice\tTry Again\n");
            break;
        }
    } while (choice != 10);

    free(str);
    free(str1);
    return 0;
}
