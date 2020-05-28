#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*end;

void create(int n);
void display();
void swap();

int n;
int main()
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);
	printf("\nDisplay the list:\n");
	display();
	swap();
	printf("\nDisplay the list:\n");
	display();
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
void swap()
{
	struct node *temp1,*temp2;
	temp1=end;
	temp2=head;
	while(temp2->next!=end)
	{
		temp2=temp2->next;
	}
	temp2->next=head;
	head=head->next;
	temp1->next=head;
	head=end;
	temp2->next->next=NULL;
	printf("\n");
}
