#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*end;

void create(int n);
void display();
void nodeatanypos(int pos);
int n;

int main()
{
	int pos;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Display the list:\n");
	display();
	printf("\n*********************SINGLY LINKED LIST CREATED************************\n");
	printf("\nEnter the position from user:");
	scanf("%d",&pos);	
	nodeatanypos(pos);
	return 0;
}

void create(int n)
{
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Memory allocation not possible");
	}
	else
	{
		int value;
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		end=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		int value;		
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("Memory allocation not possible");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&value);
			newnode->data=value;
			newnode->next=NULL;
			end->next=newnode;
			end=end->next;
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
		printf("Display the value of %d=%d\n",i,temp->data);
		i++;
		temp=temp->next;
	}
}

void nodeatanypos(int pos)
{
	struct node *temp;
	temp=head;
	if(pos<=n)
	{
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}	
	}
	else
	{
		printf("You entered wrong choice..!");
	}
	printf("The value at position %d is %d",pos,temp->data);
}
