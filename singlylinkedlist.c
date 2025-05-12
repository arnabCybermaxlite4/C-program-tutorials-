#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} node;

node *head = NULL;

void display()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
    printf("\n");
}

void ins_first()
{
	node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    int item;
    printf("Enter the Item: ");
    scanf("%d", &item);
    newnode->data = item;
    newnode->link = NULL;
	if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head = newnode;
		newnode->data = item; 
    }
}

void ins_last()
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    int item;
    printf("Enter the Item: ");
    scanf("%d", &item);
    newnode->data = item;
    newnode->link = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}

void ins_any_pos()
{
	int pos;
	node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    int item;
    printf("Enter the Item: ");
    scanf("%d", &item);
    printf("Enter the position you want to Insert:");
    scanf("%d",&pos);
    newnode->data = item;
    newnode->link = NULL;
    if(pos == 1)
    {
        newnode->link=head;
        head=newnode;
        return;
	}
	node *ptr = head;
	int i;
	for(i=1;ptr!=NULL && i<pos-1;i++)
	{
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("Invalid position\n");
		free(newnode);
		return;
	}
	newnode->link=ptr->link;
	ptr->link=newnode;
}

void del_first()
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return;	
	}
	node *ptr=head;	
	head=head->link;
	printf("The deleted element is: %d\n", ptr->data);
	free(ptr);
} 

void del_last()
{
    if (head == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("The deleted element is: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    node *ptr = head;
    node *prev = NULL;
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    printf("The deleted element is: %d\n", ptr->data);
    free(ptr);
    prev->link = NULL;
}

void del_any_pos()
{
	int pos;
	if (head == NULL)
    {
        printf("The List is Empty\n");
        return;
    }
    printf("Enter the position:");
    scanf("%d",&pos);
    node *ptr=head;
    if(pos == 1)
    {
    	head=ptr->link;
    	free(ptr);
    	return;
	}
	node *prev=NULL;
	int i;
	for(i=1;ptr!=NULL && i<pos;i++)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("Invalid position\n");
		return;
	}
	prev->link=ptr->link;
	free(ptr);
}

void search()
{
	int position=1;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    node *ptr = head;
    int item;
    printf("Enter the Item: ");
    scanf("%d", &item);
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {	
            printf("Item found at position: %d\n",position);
            return;
        }
        ptr = ptr->link;
        position++;
    }
    printf("Item not found\n");
}

int main()
{
    int ch;
    do
    {
        printf("\nOptions:\n");
        printf("1. Display\n2. Insert at First\n3. Insert at the End\n4. Insert at any position\n5. Delete from First\n6. Delete from the End\n7. Delete from any position\n8. Search\n9. Exit\n");
        printf("Enter your choice(1-5): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
        	ins_first();
        	break;
        case 3:
            ins_last();
            break;
		case 4:
			ins_any_pos();
			break;
		case 5:
			del_first();
			break;
        case 6:
            del_last();
            break;
        case 7:
        	del_any_pos();
        	break;
        case 8:
            search();
            break;
        case 9:
            printf("Exiting from the program\n");
            break;
        default:
            printf("Wrong Choice\nTry Again\n");
        }
    } while (ch != 9);
    return 0;
}
