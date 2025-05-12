#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}snode;

snode *createNode(int ele)
{
	snode *node;
	node=(snode *)malloc(sizeof(snode));
	if(node==NULL)
		printf("\t===================\n\tCan't create node.\n\t===================");
	else
	{
		node->data=ele;
		node->next=NULL;
	}
	return node;
}
snode *push(snode *top,int ele)
{
	snode *newNode=createNode(ele);
	if(newNode!=NULL)
	{
		newNode->next=top;
		top=newNode;
		return top;
	}
}

snode *pop(snode *top)
{
	snode *temp=top;
	int ele;
	if(top==NULL)
		printf("\t================\n\tStack is empty.\n\t================");
	else
	{
		ele=top->data;
		top=top->next;
		free(temp);
		printf("\t========================\n\tPopped element is %d\n\t========================",ele);
	}
	return top;
}

void display(snode *top)
{
	snode *temp=top;
	if(top==NULL)
		printf("\t================\n\tStack is empty.\n\t================");
	else
	{
		printf("\t===========\n\tStack is :");
		while(temp!=NULL)
		{
			printf("\n\t%d",temp->data);
			if(temp==top)
				printf(" <- top");
			temp=temp->next;
		}
		printf("\n\t===========");
	}
}

int main()
{
	int option,element;
	snode *stack=NULL;
	
	do
	{
		printf("\n\t1. Push");
		printf("\n\t2. Pop");
		printf("\n\t3. Display");
		printf("\n\t4. Exit");
		printf("\n\n\tChoose an option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("\t=======================\n\tEnter the element : ");
					scanf("%d",&element);
					stack=push(stack,element);
					break;	
			case 2: stack=pop(stack);
					break;
			case 3: display(stack);
					break;
			case 4: printf("\n\tBye bye");		
		}
	}while(option<=3);
	getch();
	return 0;
}
