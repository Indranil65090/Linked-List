#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*end;

void create(int n);
void display();
void remove();
int n;

int main()
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("\nDisplay the list:\n");
	display();
	remove();
	printf("\n\nDisplay the list after deleting all nodes having negative(-) value:\n");
	display();
	return 0;
}
void create(int n)
{
	int val;
	struct node *temp;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("\nMEMORY ALLOCATION NOT POSSIBLE\n");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&val);
		head->data=val;
		head->next=NULL;
		head->prev=NULL;
		temp=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nMEMORY ALLOCATION NOT POSSIBLE\n");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&val);
			newnode->data=val;
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
		printf("\nLIST IS EMPTY\n");
	}
	else
	{
		while(temp->next!=head)
		{
			printf("Data of %d:%d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
	printf("Data of %d:%d",i,temp->data);
	}
}
void remove()
{
	end->next=NULL;
	head->prev=NULL;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(head->data<0)
		{
			struct node *b;
			b=head;
			head=head->next;
			free(b);
		}
		else if(end->data<0)
		{
			struct node *c;
			c=end;
			end=end->prev;
			free(c);
		}
		else
		{
			if(temp->data<0)
			{
			struct node *a;
			a=temp;
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			free(a);
			}
		}
	temp=temp->next;
	}
	end->next=head;
	head->prev=end;
}
