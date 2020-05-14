#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*head,*end;

void create(int n);
void display();
void reverse();

int main()
{
	int n;
	printf("Enter the numebr of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Display the list:\n");
	display();
	printf("\n");
	printf("*******************************************\n");
	printf("Reversed list is:\n");
	reverse();
	display();
	return 0;
}

void create(int n)
{
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Memory allocation not possible");
	}
	else
	{
		int value;
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		end=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		int value;		
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
			end->next=newnode;
			end=end->next;
		}
	}
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		temp=head;
		int i=1;
		while(temp!=NULL)
		{
			printf("Display the value of %d=%d\n",i,temp->data);
			i++;
			temp=temp->next;
		}
	}
}

void reverse()
{
	struct node *a,*b;
	if(head!=NULL)
	{
		a=head;
		b=head->next;
		head=head->next;
		a->next=NULL;
		while(head!=NULL)
		{
			head=head->next;
			b->next=a;
			a=b;
			b=head;
		}
		head=a;
	}
}
