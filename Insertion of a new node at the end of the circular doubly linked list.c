#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*b;

void create(int n);
void display();
void insertend(int value);

int main()
{
	int n,value;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Display the list:\n");
	display();
	printf("\nEnter the value from user:");
	scanf("%d",&value);
	insertend(value);
	printf("Display the list:\n");
	display();
	return 0;
}

void create(int n)
{
	struct node *newnode;
	int value;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Memory allocation not possible");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		head->prev=NULL;
		b=head;
	}
	for(int i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("Memory allocation not possible");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&value);
			newnode->data=value;
			newnode->next=NULL;
			newnode->prev=b;
			b->next=newnode;
			b=b->next;
		}
	}
	/*creation of circular doubly linked list,all codes above are same as that
	of the creation of doubly linked list but the below two lines of code 
	creates the circular doubly linked list*/
	
	b->next=head;//linking the last node with the first node or head node
	head->prev=b;//linking the head node with the last node
	
}

void display()
{
	int i=1;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			printf("Data of %d=%d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
		printf("Data of %d=%d",i,temp->data);
	}
}

void insertend(int value)
{
	b->next=NULL;
	head->prev=NULL;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory cannot be allocated");
	}
	else
	{
		newnode->data=value;//the value of the new node is assigned
		b->next=newnode;//the last node is linked with the new node
		newnode->prev=b;//the new node is linked with the last node
		newnode->next=head;//the new node is connected with the head ndoe
		head->prev=newnode;//the head node is connected with the new node added at the end
    b=newnode;//the new node becomes the last node
	}
}
