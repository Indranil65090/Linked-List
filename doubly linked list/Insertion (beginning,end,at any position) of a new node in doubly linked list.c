#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*p,*m;

void create(int n);
void display();
void insertbeg(int value);
void insertend(int value);
void insertpos(int position,int value);
int n;//declaring the number of nodes globally

int main()
{
	int value,option,position;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Display the list:\n");
	display();
	printf("\nEnter the option from user:");
	scanf("%d",&option);
	switch(option)
	{
		case 1: printf("Enter the value from user:");
			scanf("%d",&value);
			insertbeg(value);
			break;
		case 2: printf("Enter the value from user:");
			scanf("%d",&value);
			insertend(value);
			break;
		case 3: printf("Enter the value from user:");
			scanf("%d",&value);
			printf("Enter the position from user:");
			scanf("%d",&position);
			insertpos(position,value);
			break;
		default: printf("Sorry wrong choice..!\n");
			 break;	   	   	   
	}
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

void insertend(int value)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));//memory allocating for the new node 
	newnode->data=value;//data part of the new node is given
	newnode->next=NULL;//the next part of the new node is NULL
	p->next=newnode;/*the next part of the last node of the list is pointing to the new node to create a link between the last node 
	and the newly added node*/
	newnode->prev=p;//the previous part of the new node is pointing to the last node to create a link to the last node
	p=newnode;//the new node becomes the last node
}

void insertpos(int position,int value)
{
	struct node *newnode,*temp;
	temp=head;
	int i=1;
	if(position>n)
	{
		printf("Invalid position\n");
	}
	else
	{
		while(i<position-1 && temp!=NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp!=NULL)
		{
			newnode=(struct node *)malloc(sizeof(struct node));//memory allocating for the new node 
			newnode->data=value;//data part of the new node is given
			newnode->next=temp->next;//next part of the new node is pointing to the node next to the node that temp pointer now points
			newnode->prev=temp;//linking the newnode with the current node or the node which the temp pointer points now
			if(temp->next!=NULL)
			{
				temp->next->prev=newnode;//the new node is entered in the list
			}
			temp->next=newnode;//the next part of the current node now points to the new node
		}
	}
}
