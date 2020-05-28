#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;

void create(int n);
void max();
void min();
void display();
int n;
int MAX=-1;
int MIN=99999;

int main()
{
	int num;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);
	printf("\nDisplay the list:\n");
	display();
	min();
	max();
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
	
}
void display()
{
	struct node *temp;
	temp=head;
	int i=1;
	while(temp!=NULL)
	{
		printf("\nData of %d=%d",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void max()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		int a=temp->data;
		if(a>MAX)
		{
			MAX=a;
		}
		else 
		{
			a=MAX;
		}
		temp=temp->next;
	}
	printf("\n\nThe largest number in the list is:%d",MAX);
}
void min()
{
	struct node *temp;
	temp=head;
	for(int i=1;i<=n;i++)
	{
		int c=temp->data;
		if(c<MIN)
		{
			MIN=c;
		}
		else
		{
			c=MIN;
		}
		temp=temp->next;
	}
	printf("\n\nThe smallest number in the list is:%d",MIN);
}
