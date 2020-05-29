#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head,*end;

void create(int n);
void reverse();
void display();

int main()
{
	int n,value;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	
	printf("\nDisplay the list:\n");
	display();
	
	printf("\n\nDisplay the list after reversing:\n");
	reverse();
	
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
	end=p;
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

void reverse()
{
	struct node *temp;
	temp=end;
	int i=1;
	while(temp!=head)
	{
		printf("Data of %d is:%d\n",i,temp->data);
		temp=temp->prev;
		i++;
	}
	printf("Data of %d is:%d",i,temp->data);
}
