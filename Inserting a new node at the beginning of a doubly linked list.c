#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure containing three fields data,next pointer,previous pointer 
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*m,*p;

/**
creating three functions one for creating the doubly linked list 
and another function for displaying the doubly linked list
and another for inserting at the beginning of the list  
*/

void create(int n);
void insertbeg(int value);
void display();

int main()
{
	int n,value;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("Display the list:\n");
	display();
	
	printf("\nEnter the value of the new node:");
	scanf("%d",&value);
	insertbeg(value);
	
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
		m=head;
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

void insertbeg(int value)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));//memory allocating for the new node 
	newnode->data=value;//data part of the new node is given
	newnode->next=m;//next part of the new node is having the address of the head node to create a link with the head node
	m->prev=newnode;//the previous part of the head node is now having the address of the new node to create a link with the new node
	newnode->prev=NULL;//the previous part of the new node is set to NULL
	head=newnode;//now the head is the new node  
}
