#include<stdio.h>
#include<stdlib.h>

struct node//creating self-referential structure
{
	int data;
	struct node *next;
}*head,*b;

/*creating three functions to create,display,insert*/ 

void create(int n);
void insert(int data,int position);
void display();

int main()
{
	int value,n,position;
	printf("Enter the number of nodes to be inserted:");
	scanf("%d",&n);
	
	create(n);
	
	printf("Enter the data to be inserted:");
	scanf("%d",&value);
	printf("Enter the position(other than 1)at which we need to inserted the new element in:");
	scanf("%d",&position);
	
	insert(value,position);
	
	printf("Display the list:");
	
	display();
	
	return 0;
}

void create(int n)
{
	struct node *temp;
	int value;
	head=(struct node *)malloc(sizeof(struct node));//allocating memory for the first node
	if(head==NULL)
	{
		printf("Memory cannot be allocated");
	}
	else
	{
		printf("Enter the data for the node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		temp=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory for the rest of the n-1 nodes
		if(newnode==NULL)
		{
			printf("Memory cannot be allocated");
		}
		else
		{
			printf("Enter the data for the node %d:",i);
			scanf("%d",&value);
			newnode->data=value;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		}
	}
	temp->next=head;
}

void insert(int value,int position)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node *)malloc(sizeof(struct node));//new node to be inserted is created.
	if(newnode==NULL)
	{
		printf("List is empty");
	}
	else
	{
		newnode->data=value;
		temp=head;
		for(i=1;i<position-1;i++)
		{	
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void display()
{
	int i=1;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		b=head;
		do
		{
			printf("\nData of %d=%d",i,b->data);//displaying the list
			b=b->next;
			i++;
		}while(b!=head);
	}
}
