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
void deleteatanypos(int pos);
int n;

int main()
{
	int pos;
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
	printf("\n\nEnter the position from ehich the node to be deleted:");
	scanf("%d",&pos);
	deleteatanypos(pos);
	printf("\nDisplay the list:");
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
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
	end=temp;
	end->next=head;
	head->prev=end;
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

void deleteatanypos(int pos)
{
	if(pos==n)
	{
		end->next=NULL;
		head->prev=NULL;
		struct node *temp;
		temp=end;
		end=end->prev;
		printf("\nThe data at position %d to be deleted is:%d\n",pos,temp->data);
		end->next=NULL;
		free(temp);
		end->next=head;
		head->prev=end;
	}
	else if(pos==1)
	{
		end->next=NULL;
		head->prev=NULL;
		struct node *temp;
		temp=head;
		head=head->next;
		printf("\nThe data at position %d to be deleted is:%d\n",pos,temp->data);
		head->prev=NULL;
		free(temp);
		end->next=head;
		head->prev=end;
	}
	else if(pos<n && pos>1)
	{
		end->next=NULL;
		head->prev=NULL;
		struct node *temp;
		temp=head;
		for(int i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		printf("\nThe data at position %d to be deleted is:%d\n",pos,temp->data);
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		end->next=head;
		head->prev=end;
	}
	else
	{
		printf("\nYOU ENTERED WRONG POSITION\n");
	}
}
