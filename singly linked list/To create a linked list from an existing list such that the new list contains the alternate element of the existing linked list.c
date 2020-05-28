#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;

void create(int n);
void display();
void newlist();
int n;

int main()
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);
	printf("\nDisplay the list:\n");
	display();
	printf("\n\nNew list is:\n");
	newlist();
	return 0;
}
void create(int n)
{
	int value;
	struct node *newnode,*temp;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		temp=head;
	}
	for(int i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nOVERFLOW");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&value);
			newnode->data=value;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void display()
{
	struct node *temp;
	temp=head;
	int i=1;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nData of %d=%d",i,temp->data);
			temp=temp->next;
			i++;
		}
		printf("\n\n**********************************");
	}
}
void newlist()
{
	struct node *a;
	int x=1;
	a=head;
	for(int i=1;i<=n;i++)
	{
		if(n%2!=0)
		{
			if(a->next!=NULL)
			{
				printf("\nData of %d=%d",x,a->data);
				a=a->next->next;
				x++;
			}
			else
			{
				printf("\nData of %d=%d",x,a->data);
				break;
			}
		}
		else
		{
			while(a!=NULL)
			{
				printf("\nData of %d=%d",x,a->data);
				a=a->next->next;
				x++;
			}
		}
	}
}
