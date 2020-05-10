#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure containing three fields data,next pointer,previous pointer 
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*p;

/**
creating three functions one for creating the circular doubly linked list 
and another function for displaying the  circular doubly linked list
and another for deleting the node at any position
*/

void create(int n);
void deleten(int position);
void display();

int main()
{
	
	int n,value,position;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("Display the list:\n");
	display();
	
	printf("Enter the position (except first and last position) from user:");
	scanf("%d",&position);
	deleten(position);//deleting the node at any position
	
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
  
	/*creation of circular doubly linked list*/
  
    p->next=head;
    head->prev=p;
}

void display()
{
	struct node *b;
	
	int i=1;
	if(head==NULL)
	{
		printf("List is empty");	
	}
	else
	{
        b=head;
		while(b->next!=head)
		{
			printf("Data of %d is:%d\n",i,b->data);
			b=b->next;
			i++;
		}
	printf("Data of %d is:%d\n",i,b->data);
	}
}

void deleten(int position)
{
	/*breaking the link which made this list circular*/
  
    p->next=NULL;
    head->prev=NULL;

	struct node *temp;
	int i;
	temp=head;
  
	for(i=1;i<position && temp!=NULL;i++)
	{
		temp=temp->next;
	}
  
	printf("The data that needs to be deleted is:%d\n",temp->data);
  
	temp->prev->next=temp->next;/*the temp variable now points to its previous node which now creates 
	a new link with temp variable's next node*/
  
	temp->next->prev=temp->prev;/*the temp variable now points to its next node which now creates a new link with
	temp variable's previous node*/
  
	free(temp);//freeing the memory allocated for temp variable

	/*recreating the link to form circular linked list again*/
  
	p->next=head;
    	head->prev=p;
}
