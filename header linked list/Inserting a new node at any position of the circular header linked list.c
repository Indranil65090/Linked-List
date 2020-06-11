#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*start,*end;

void create(int n);
void display();
void insertatanypos();
void display();
int n;

int main()
{
	
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
	insertatanypos();
	printf("\nDisplay the list:");
	display();
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
			temp=temp->next;
		}
	}
	end=temp;
	end->next=head;
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
		while(temp->next!=head)
		{
			printf("\nData of %d=%d",i,temp->data);
			temp=temp->next;
			i++;
		}
		printf("\nData of %d=%d",i,temp->data);
	}
}
void insertatanypos()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	int val,pos;
	if(newnode==NULL)
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		printf("\n\nEnter the position:");
		scanf("%d",&pos);
		if(pos==1)
		{
			end->next=NULL;
			printf("The data to be inserted at the beginning is:");
			scanf("%d",&val);
			newnode->data=val;
			start->next=newnode;
			newnode->next=head;
			head=newnode;
			end->next=head;
		}
		else if(pos==n)
		{
			end->next=NULL;
			printf("\n\nThe data to be inserted at the end is:");
			scanf("%d",&val);
			newnode->data=val;
			end->next=newnode;
			end=newnode;
			end->next=head;
		}
		else if(pos<n)
		{
			end->next=NULL;
			printf("\n\nThe data to be inserted at the position %d is:",pos);
			scanf("%d",&val);
			struct node *temp,*temp1;
			temp=head;
			temp1=temp->next;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
				temp1=temp1->next;
			}
			newnode->data=val;
			temp->next=newnode;
			newnode->next=temp1;
			end->next=head;
		}
		else
		{
			printf("\n\nYOU ENTERED WRONG POSITION");
		}
	}
}
