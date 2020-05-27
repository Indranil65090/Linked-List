#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;

void create(int n);
void count();
void display();

int main()
{
	int n,num;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);

	printf("\nDisplay the list:\n");
	display();
	
	count();
	
	return 0;
}

void create(int n)
{
	int value;
	struct node *newnode,*temp;
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
	
}
void display()
{
	struct node *temp;
	temp=head;
	int i=1;
	while(temp->next!=NULL)
	{
		printf("\nData of %d=%d",i,temp->data);
		temp=temp->next;
		i++;
	}
	printf("\nData of %d=%d",i,temp->data);
}
void count()
{
	struct node *temp;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		if(temp->data!=0)
		{
			count++;
			temp=temp->next;
		}
		else
		{
			temp=temp->next;
		}
	}
	printf("\n\nThe total number of non-zero numbers in the list is:%d",count);
}
