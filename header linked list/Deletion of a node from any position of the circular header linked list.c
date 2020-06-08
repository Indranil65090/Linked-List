#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
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
	}
	end=temp;
	end->next=head;
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
void deleteatanypos()
{
	int pos;
	printf("\n\nEnter the position from user:");
	scanf("%d",&pos);
	if(pos==1)
	{
		struct node *temp;
		if(temp==NULL)
		{
			printf("LIST IS EMPTY");
		}
		else
		{
			end->next=NULL;
			temp=head;
			head=head->next;
			printf("The data at %d to be deleted is:%d",pos,temp->data);
			free(temp);
			end->next=head;
		}
	}
	else if(pos==n)
	{
		struct node *temp,*temp1;
		temp=head;
		temp1=end;
		if(temp==NULL)
		{
			printf("LIST IS EMPTY");
		}
		else
		{
			end->next=NULL;
			while(temp->next!=end)
			{
				temp=temp->next;
			}
			temp->next=head;
			printf("The data at %d to be deleted is:%d",pos,temp1->data);
			free(temp1);
		}
	}
	else if(pos<n && pos>1)
	{
		struct node *temp,*temp1;
		temp=head;
		temp1=temp->next;
		if(temp==NULL)
		{
			printf("LIST IS EMPTY");
		}
		else
		{
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
				temp1=temp1->next;
			}
			temp->next=temp1->next;
			printf("The data at %d to be deleted is:%d",pos,temp1->data);
			free(temp1);
		}
	}
	else
	{
		printf("YOU ENTERED WRONG POSITION.NO DELETION POSSIBLE");
	}	
}
