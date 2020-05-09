#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*p;

void create(int n);
void insertpos(int value,int pos);
void display();


int main()
{
	int value,pos,n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("Display the list:\n");
	display();
	
	printf("\nEnter the position at which the new node to be inserted:");
	scanf("%d",&pos);
	printf("Enter the value of the new node:");
	scanf("%d",&value); 
	insertpos(value,pos);
	
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

void insertpos(int value,int pos)
{
	struct node *newnode,*temp;
	temp=head;
	int i=1;
	while(i<pos-1 && temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(temp!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=value;
		newnode->next=temp->next;
		newnode->prev=temp;
		if(temp->next!=NULL)
		{
			temp->next->prev=newnode;
		}
		temp->next=newnode;
	}
}	
	
