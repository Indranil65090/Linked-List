#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*temp;

void create(int n);
void display();
void sort();

int main()
{
	int n;
  
	printf("ENTER THE NUMBER OF NODES:");
	scanf("%d",&n);
	printf("\n");
  	create(n);
  	printf("\nDISPLAY THE LIST:\n\n");
	display();
	sort();
	printf("\n\n*******************DISPLAY THE LIST AFTER SORTING***************************\n\n");
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
		temp=head;
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
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
	temp->next=head;
	head->prev=temp;
	
}
void display()
{
	int i=1;
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
void sort()
{
	temp->next=NULL;
	head->prev=NULL;
	
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
	
	temp->next=head;
	head->prev=temp;
}
