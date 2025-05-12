#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *link;
} node;

node *head = NULL;

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("\n");
}

void insertFirst(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;

    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        node *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        newNode->link = head;
        temp->link = newNode;
        head = newNode;
    }
}

void insertEnd(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;

    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        node *temp = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = head;
    }
}

void insertANYpos(int val, int pos)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;

    if (pos < 1)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    if (head == NULL && pos == 1)
    {
        head = newNode;
        newNode->link = head;
        return;
    }

    if (pos == 1)
    {
        insertFirst(val);
        free(newNode);
        return;
    }

    node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->link != head)
    {
        temp = temp->link;
        count++;
    }

    if (count != pos - 1)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;

    if (head->link == head)
    {
        free(head);
        head = NULL;
        return;
    }

    node *last = head;
    while (last->link != head)
    {
        last = last->link;
    }

    head = head->link;
    last->link = head;
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->link == head)
    {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    node *prev = NULL;
    while (temp->link != head)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = head;
    free(temp);
}

void deleteANYpos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    node *temp = head, *prev = NULL;
    int count = 1;

    while (count < pos && temp->link != head)
    {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if (count != pos)
    {
        printf("Position out of bounds.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

int main()
{
    int choice, val, pos;

    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &val);
            insertFirst(val);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter the position: ");
            scanf("%d",&pos);
            insertANYpos(val, pos);
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteANYpos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
// This code implements a circular linked list in C. It includes functions to insert, delete, and display elements in the list. The list is circular, meaning the last node points back to the first node.