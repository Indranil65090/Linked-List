#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void create(int n);
void display();
void deletebeg();
void deleteend();
void deletemiddle();
int n;
int main()
{
	int num,option;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);

	printf("\nDisplay the list:\n");
	display();
	
	printf("\n\nEnter an option between 1-3:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:printf("\nDelete the first element:");
			   deletebeg();
			   break;
		case 2:printf("\nDelete the last element:");
			   deleteend();
			   break;
		case 3:printf("\nDelete the middle element:");
			   deletemiddle();
			   break;				
	}
	return 0;
}
void create(int n)
{
	int value;
	struct node *newnode,*temp;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("\nOverflow");
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
			printf("\nOverflow");
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
	if(head==NULL)
	{
		printf("\nList is empty");
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
void deletebeg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp=head;
		head=head->next;
		printf("\nData to be deleted is:%d",temp->data);
		free(temp);
	}
}
void deleteend()
{
	struct node *temp,*temp1;
	
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp=head;
		temp1=head;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else
		{
			temp1->next=NULL;
		}
		printf("\nData to be deleted is:%d",temp->data);
		free(temp);
	}
}
void deletemiddle()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else if(n%2!=0)
	{
		for(int i=1;i<=n/2;i++)
		{
			temp=temp->next;
		}
		printf("\nData to be deleted is:%d",temp->data);
		free(temp);
	}
	else
	{
		for(int i=1;i<n/2;i++)
		{
			temp=temp->next;
		}
		printf("\nData to be deleted is:%d",temp->data);
		free(temp);
	}
}
