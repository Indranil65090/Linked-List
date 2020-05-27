#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*p,*a;
void create(int n);
void deletebeg();
void replaceend();
void display();
int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);
	printf("\nDisplay the list:\n");
	display();
	printf("\nDelete the first element:");
	deletebeg();
	printf("\nDisplay the list:\n");
	display();
	printf("\nReplace the last value with the deleted value:");
	replaceend();
	printf("\nDisplay the list:\n");
	display();
	return 0;
}
void create(int n)
{
	head=(struct node *)malloc(sizeof(struct node));
	int val;
	if(head==NULL)
	{
		printf("\nNo memory to allocate");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&val);
		head->data=val;
		head->next=NULL;
		head->prev=NULL;
		p=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nNo memory to allocate");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&val);
			newnode->data=val;
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
	printf("Data of %d is:%d\n",i,b->data);
	}
}
void deletebeg()
{
	struct node *temp,*newhead,*b;
	temp=head;
	b=head;
	printf("\nThe data to be deleted is:%d\n",temp->data);
	a=head;
	newhead=temp->next;
	newhead->prev=NULL;
	a->next=NULL;
	head=newhead;
}
void replaceend()
{
	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;	
	}	
	temp->data=a->data;
	printf("\nThe new value of the last node is:%d\n",temp->data);
	free(a);
}
