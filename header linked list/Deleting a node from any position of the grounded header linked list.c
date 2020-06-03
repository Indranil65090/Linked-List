#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*start,*end;
void create(int n);
void display();
void displaynewlist();
void deleteatanypos();
int n;
int main()
{
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
	deleteatanypos();
	printf("\n\nDisplay the list:");
	displaynewlist();
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
			temp->next=newnode;
			temp=temp->next;
		}
		end=temp;
	}
	
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
void deleteatanypos()
{
	struct node *temp,*temp1,*a;
	int pos;
	
	printf("\n\nEnter the position at which the element is to be deleted:");
	scanf("%d",&pos);
	if(pos==1)
	{
		temp=head;
		head=head->next;
		start->next=head;
		printf("\nThe data to be deleted is:%d",temp->data);
		free(temp);
	}
	else if(pos==n)
	{
		temp=head;
		struct node *a;
		while(temp->next!=end)
		{
			temp=temp->next;
		}
		a=end;
		printf("\nThe data to be deleted is:%d",a->data);
		temp->next=NULL;
		free(a);
	}
	else
	{
		temp=head;
		temp1=temp->next;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
			temp1=temp1->next;
		}
		a=temp1;
		temp->next=temp1->next;
		printf("\nThe data to be deleted is:%d",temp1->data);
		free(a);
	}
}
void displaynewlist()
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
