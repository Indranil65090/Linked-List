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
void remove_negative_1();

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
	remove_negative_1();
	printf("\n\nDisplay the list:");
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
void remove_negative_1()
{
	end->next=NULL;
	head->prev=NULL;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(head->data==-1)
		{
			struct node *a;
			a=head;
			head=head->next;
			free(a);
		}
		else if(end->data==-1)
		{
			struct node *a;
			a=end;
			end=end->prev;
			free(a);
		}
		else
		{
			if(temp->data==-1)
			{
			struct node *a;
			a=temp;
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			free(a);
			}
		}
		temp=temp->next;	
	}
	end->next=head;
	head->prev=end;
}
