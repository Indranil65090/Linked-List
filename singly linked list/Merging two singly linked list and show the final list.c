#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head1,*end,*head2;

void create1(int n);
void display1();
void create2(int n);
void display2();
void join();
void display();
int n1,n2;

int main()
{
	printf("Enter the number of nodes for the first list:");
	scanf("%d",&n1);
	printf("\n");
	create1(n1);
	printf("\nDisplay the list:\n");
	display1();
	printf("\n\nEnter the number of nodes for the second list:");
	scanf("%d",&n2);
	printf("\n");
	create2(n2);
	printf("\nDisplay the list:\n");
	display2();
	printf("\n\n***************************JOIN THE TWO LIST***********************************\n");
	join();
	printf("\nDisplay the list:\n");
	display();
	return 0;
}
void create1(int n1)
{
	int value;
	struct node *newnode,*temp;
	head1=(struct node *)malloc(sizeof(struct node));
	if(head1==NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head1->data=value;
		head1->next=NULL;
		temp=head1;
	}
	for(int i=2;i<=n1;i++)
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
void display1()
{
	struct node *temp;
	temp=head1;
	int i=1;
	if(head1==NULL)
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
void create2(int n2)
{
	int value;
	struct node *newnode,*temp;
	head2=(struct node *)malloc(sizeof(struct node));
	if(head2==NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head2->data=value;
		head2->next=NULL;
		temp=head2;
	}
	for(int i=2;i<=n2;i++)
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
void display2()
{
	struct node *temp;
	temp=head2;
	int i=1;
	if(head2==NULL)
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
void join()
{
	end->next=head2;
}
void display()
{
	struct node *temp;
	temp=head1;
	int i=1;
	if(head1==NULL)
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
