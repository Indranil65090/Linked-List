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
	printf("\n\n************************SORTING THE ELEMENTS OF THE LIST***************************\n");
	sort();
	printf("\nDisplay the list after sorting:\n");
	display();
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
	while(temp1->next!=NULL)
	{
		temp2=temp1->next;
		while(temp2!=NULL)
		{
			if(temp1->data>temp2->data)
			{
				a=temp1->data;
				temp1->data=temp2->data;
				temp2->data=a;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
