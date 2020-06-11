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
void insertatanypos(int pos);
int n;

int main()
{
	int pos;
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
	printf("\n\nEnter the position at which the new node to be inserted:");
	scanf("%d",&pos);
	insertatanypos(pos);
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
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
	end=temp;
	end->next=head;
	head->prev=end;
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
void insertatanypos(int pos)
{
	int val;
	if(pos<=n && pos>1)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("MEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			end->next=NULL;
			head->prev=NULL;
			struct node *temp,*temp1;
			printf("Enter the value to be inserted at position %d:",pos);
			scanf("%d",&val);
			newnode->data=val;
			temp=head;
			temp1=temp->next;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
				temp1=temp1->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=temp1;
			temp1->prev=newnode;
			end->next=head;
			head->prev=end;
		}
	}
	else if(pos==1)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("MEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			end->next=NULL;
			head->prev=NULL;
			printf("Enter the value to be inserted at position %d:",pos);
			scanf("%d",&val);
			newnode->data=val;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
			end->next=head;
			head->prev=end;
		}
	}
	else if(pos==n+1)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("MEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			end->next=NULL;
			head->prev=NULL;
			printf("Enter the value to be inserted at position %d:",pos);
			scanf("%d",&val);
			newnode->data=val;
			end->next=newnode;
			newnode->prev=end;
			newnode->next=head;
			head->prev=newnode;
			end=newnode;
			end->next=head;
			head->prev=end;
		}
	}
	else
	{
		printf("\nYOU ENTERED WRONG POSITION...SORRY!!!\n");
	}
}
