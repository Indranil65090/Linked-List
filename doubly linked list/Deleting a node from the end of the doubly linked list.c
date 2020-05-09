#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure containing three fields data,next pointer,previous pointer 
{
	int data;
	struct node *prev;
	struct node *next;
}*head;

struct node *p;
/**
creating three functions one for creating the doubly linked list 
and another function for displaying the doubly linked list
and another for deleting the last node
*/

void create(int n);
void deleteend();
void display();

int main()
{
	
	int n,value;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("Display the list:\n");
	display();
	
	deleteend();//deleting the last node
	
	printf("Display the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	int value;
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("The value of node 1 is:");
	scanf("%d",&value);
	if(head==NULL)
	{
		printf("No memory to allocate");
	}
	else
	{
		head->data=value;
		head->next=NULL;
		head->prev=NULL;
		
		p=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("The value of node %d is:",i);
		scanf("%d",&value);
		if(newnode==NULL)
		{
			printf("No memory to allocate");
		}
		else
		{
			newnode->data=value;
			newnode->next=NULL;
			newnode->prev=p;
			p->next=newnode;
			p=p->next;
		}
	}
}

void display()
{
	struct node *b;
	b=head;
	int i=1;
	if(head==NULL)
	{
		printf("List is empty");	
	}
	else
	{
		while(b->next!=NULL)
		{
			printf("Data of %d is:%d\n",i,b->data);
			b=b->next;
			i++;
		}
	printf("Data of %d is:%d",i,b->data);
	}
}

void deleteend()
{
	struct node *m;
	m=head;
	printf("\nThe data to be deleted is:%d\n",p->data);
	while(m->next!=p)
	{
		m=m->next;
	}
	p->prev=NULL;//the previous part of the last node is set to NULL to disconnect it with the secondlast node
	m->next=NULL;//the next part of secondlast node is set to NULL to disconnect it with the last node
	p=m;//making the previous node as the last node
}
