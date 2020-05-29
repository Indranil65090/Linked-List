#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*end,*temp;

void create(int n);
void display();
void top();
int n;

int main()
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("\nDisplay the list:\n");
	display();
	top();
	printf("\nDisplay the list:\n");
	display();
	return 0;
}
void create(int n)
{
	int val;
	
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("MEMORY ALLOCATION NOT POSSIBLE");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&val);
		head->data=val;
		head->next=NULL;
		head->prev=NULL;
		temp=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("MEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&val);
			newnode->data=val;
			newnode->next=NULL;
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void display()
{
	temp=head;
	int i=1;
	while(temp!=NULL)
	{
		printf("Data of %d:%d\n",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void top()
{
	temp=head;
	for(int i=0;i<n/2;i++)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	temp->next=head;
	head->prev=temp;
	head=temp;
}
