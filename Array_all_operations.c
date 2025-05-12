#include <stdio.h>
#include <stdlib.h>
int *arr;
int size;
void display()
{
    int i;
    if (size == 0)
    {
        printf("The array is empty\n");
        return;
    }
    printf("Array:-\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

void ins_beg()
{
    int i, ele, *temp;
    temp = (int *)realloc(arr, (size + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    for (i = size - 1; i >= 0; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }
    printf("Enter the element you want to Insert:");
    if (scanf("%d", &ele) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        return;
    }
    *arr = ele;
    size++;
}

void ins_end()
{
    int i, ele, *temp;
    temp = (int *)realloc(arr, (size + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    printf("Enter the element you want to Insert:");
    if (scanf("%d", &ele) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        return;
    }
    *(arr + size) = ele;
    size++;
}

void ins_any_pos()
{
    int i, ele, pos, *temp;
    temp = (int *)realloc(arr, (size + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    printf("Enter the element you want to Insert:");
    if (scanf("%d", &ele) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        return;
    }
    printf("Enter the position you want to Insert the element:");
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > size + 1)
    {
        printf("Invalid input!Please enter a position between 1 and %d.\n", size + 1);
        return;
    }
    if (pos != size + 1)
    {
        for (i = size - 1; i >= pos - 1; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }
    }
    *(arr + pos - 1) = ele;
    size++;
}

void del_beg()
{
    int i, *temp;
    for (i = 0; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    temp = (int *)realloc(arr, (size - 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    size--;
}

void del_end()
{
    int *temp;
    temp = (int *)realloc(arr, (size - 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    size--;
}
void del_any_pos()
{
    int i, pos, *temp;
    printf("Enter the position you want to Delete the element:");
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > size)
    {
        printf("Invalid input!Please enter a position between 1 and %d.\n", size);
        return;
    }
    for (i = pos - 1; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    temp = (int *)realloc(arr, (size - 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    size--;
}

void search()
{
    int i, ele, pos;
    printf("Enter the element you want to Search:");
    if (scanf("%d", &ele) != 1)
    {
        printf("Invalid Input! Try again\n");
        return;
    }
    for (i = 0; i < size; i++)
    {
        if (*(arr + i) == ele)
        {
            printf("The Element has been found at postion %d", i + 1);
            return;
        }
    }
    printf("Item not found in the array\n");
}

void count()
{
    printf("There are %d Elements in the array", size);
}

void sort()
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}

void reverse()
{
    int i, temp;
    for (i = 0; i < size / 2; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
    printf("Array reversed successfully.\n");
}

int main()
{
    int i, ch;
    printf("Enter the number of Elements:");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    printf("Enter the %d elements one by one:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }
    do
    {
        printf("\nChoice:-");
        printf("\n1.Display the array\n2.Insert an item at the beginning of the array\n3.Insert an item at the end of the array\n4.Insert an item at any position of the array\n5.Delete an item from the beginning of the array\n6.Delete an item from the end of the array\n7.Delete an item from a particular position from the array\n8.Search for an item and it's position\n9.Count the number of items currently in the array\n10.Sort the array\n11.Reverse the array\n12.Exit\n");
        printf("Enter your choice(1-12):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            ins_beg();
            break;
        case 3:
            ins_end();
            break;
        case 4:
            ins_any_pos();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_any_pos();
            break;
        case 8:
            search();
            break;
        case 9:
            count();
            break;
        case 10:
            sort();
            break;
        case 11:
            reverse();
            break;
        case 12:
            printf("Exiting from the program\n");
            break;
        default:
            printf("\nInvalid Choice\nTry Again\n");
        }
    } while (ch < 12);
    free(arr);
    return 0;
}
