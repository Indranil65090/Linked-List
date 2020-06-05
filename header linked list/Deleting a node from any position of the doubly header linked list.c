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
			temp->next=newnode;
			newnode->prev=temp;
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
void deleteatanypos()
{
	struct node *temp,*a;
	int pos;
	printf("\n\nEnter the position from user:");
	scanf("%d",&pos);
	if(pos<=n)
	{
		if(pos==1)
		{
			struct node *temp,*a;
			temp=start;
			a=head;
			head=head->next;
			temp->next=head;
			head->prev=NULL;
			printf("\nThe data at position %d to be deleted is:%d",pos,a->data);
			free(a);
			temp=head;
			int i=1;
			printf("\n\nDisplay the list:");
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
		else if(pos==n)
		{
			struct node *temp,*a;
			temp=head;
			a=end;
			while(temp->next!=end)
			{
				temp=temp->next;
			}
			printf("\nThe data at position %d to be deleted is:%d",pos,a->data);
			temp->next=NULL;
			free(a);
			temp=head;
			int i=1;
			printf("\n\nDisplay the list:");
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
		else
		{
			struct node *temp,*temp1,*a;
			temp=head;
			temp1=temp->next;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
				temp1=temp1->next;
			}
			a=temp1;
			temp->next=temp1->next;
			temp1->next->prev=temp;
			printf("\nThe data at position %d to be deleted is:%d",pos,temp1->data);
			free(a);
			temp=head;
			int i=1;
			printf("\n\nDisplay the list:");
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
	}
	else
	{
		printf("\nYOU ENTERED WRONG CHOICE");
	}
}
