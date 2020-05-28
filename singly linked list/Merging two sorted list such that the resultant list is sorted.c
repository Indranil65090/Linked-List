#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head1,*head2,*end;

void create1(int n1);
void display1();
void create2(int n2);
void display2();
void join();
void display();
void sort();
void displaysort();
int n1,n2;

int main()
{
	printf("Enter the number of nodes for the first sorted list:");
	scanf("%d",&n1);
	printf("\n");
	create1(n1);
	printf("\nDisplay the first sorted list:\n");
	display1();
	printf("\n\nEnter the number of nodes for the second sorted list:");
	scanf("%d",&n2);
	printf("\n");
	create2(n2);
	printf("\nDisplay the second sorted list:\n");
	display2();
	join();
	printf("\n\n****************************SORTING THE LIST***************************");
	sort();
	displaysort();
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

void sort()
{
	struct node *temp1,*temp2;
	int a;
	temp1=head1;
	while(temp1->next!=NULL)
	{
		temp2=temp1->next;
		while(temp2!=NULL)
		{
			if(temp1->data>temp2->data)
			{
				a=temp1->data;
				temp1->data=temp2->data;
				temp2->data=a;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void displaysort()
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
