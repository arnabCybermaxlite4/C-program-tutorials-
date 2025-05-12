#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL; 

void display() 
{
    Node *temp = head;
    if (head == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) 
	{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertFirst(int value) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int value) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
	{
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(int value, int pos) 
{
    if (pos < 1) 
	{
        printf("Invalid position!\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (pos == 1) 
	{
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }
	int i;
    Node *temp = head;
    for (i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) 
	{
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFirst() 
{
    if (head == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = head;
    head = head->next;
    
    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteEnd() 
{
    if (head == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    if (head->next == NULL) 
	{
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPos(int pos) 
{
    if (head == NULL || pos < 1) 
	{
        printf("List is empty or position invalid.\n");
        return;
    }

    Node *temp = head;
    if (pos == 1) 
	{
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }
	int i;
    for ( i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) 
	{
        printf("Position out of range.\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

int main() 
{
    int choice, value, pos;

    do 
	{
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPos(value, pos);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice!=8);

    return 0;
}
