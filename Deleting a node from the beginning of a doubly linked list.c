#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure containing three fields data,next pointer,previous pointer 
{
	int data;
	struct node *prev;
	struct node *next;
}*head;

/**
creating three functions one for creating the doubly linked list 
and another function for displaying the doubly linked list
and another for deleting the first node
*/

void create(int n);
void deletebeg();
void display();

int main()
{
	int n,value;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("Display the list:\n");
	display();
	
	deletebeg();//delete the first node
	
	printf("Display the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	int value;
	struct node *p;
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

void deletebeg()
{
	struct node *a,*temp,*newhead;

	temp=head;
	printf("\nThe data to be deleted is:%d\n",temp->data);
	a=head;
	newhead=temp->next;//the node next to the head node 
	newhead->prev=NULL; //making the previous part of the new head as NULL to disconnect head and new head
	a->next=NULL;//making the next part of the head node/first node as NULL so as to disconnect head and the new head
	head=newhead;//the node next to the head becomes the new head
	free(temp);//freeing the memory allocated for the head node
}
