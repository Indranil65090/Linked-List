#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*start,*end;
void create(int n);
void display();
void insertend();
void displaylist();
struct node *newNode;
int main()
{
	int n;
	start=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\nMEMORY ALLOCATION NOT POSSIBLE");
	}
	else
	{
		printf("Enter the number of nodes:");
		scanf("%d",&n);
		start->data=n;
		start->next=NULL;
	}
	create(n);
	printf("\nDisplay the list:");
	display();
	insertend();
	printf("\nDisplay the list:");
	displaylist();
	return 0;
}
void create(int n)
{
	struct node *temp,*newnode;
	int value;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		head->prev=NULL;
		start->next=head;
		temp=head;
	}
	for(int i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nOVERFLOW");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&value);
			newnode->data=value;
			newnode->next=NULL;
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
	end=temp;
}
void display()
{
	struct node *temp;
	temp=head;
	int i=1;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nData of %d=%d",i,temp->data);
			temp=temp->next;
			i++;
		}
	}
}
void insertend()
{
	int data;
	printf("\n\nEnter the data to be inserted at the end:");
	scanf("%d",&data);
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("\nMEMORY ALLOCATION NOT POSSIBLE");
	}
	else
	{
		newNode->data=data;
		end->next=newNode;
		newNode->prev=end;
		newNode->next=NULL;
	}
}
void displaylist()
{
	struct node *temp;
	temp=head;
	int i=1;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nData of %d=%d",i,temp->data);
			temp=temp->next;
			i++;
		}
	}
}
