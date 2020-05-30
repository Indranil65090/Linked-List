#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;

void create(int n);
void display();
void sort();
int n;


int main()
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);
	printf("\nDisplay the list:\n");
	display();
	sort();
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
	}
}
void sort()
{
	struct node *temp1,*temp2;
	int a;
	temp1=head;
	while(temp1!=NULL)
	{
		temp2=temp1->next;
		while(temp2!=NULL)
		{
			int b=temp1->data;
			int c=temp2->data;
			if(b>c)
			{
				a=0;
				break;
			}
			else 
			{
				a=1;
				break;
			}
		}
		temp1=temp1->next;
	}
	if(a==0)
	{
		printf("\n\n***********************LIST IS UNSORTED***************************\n");
	}
	else
	{
		printf("\n\n***********************LIST IS SORTED*****************************\n");
	}
}
