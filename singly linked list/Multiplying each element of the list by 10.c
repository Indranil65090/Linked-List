#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void create(int n);
void mul();
void display();
int n;
int main()
{
	int num;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n");
	create(n);

	printf("\nDisplay the list:\n");
	display();
	
	mul();
	
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
	while(temp!=NULL)
	{
		printf("\nData of %d=%d",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void mul()
{
	struct node *temp;
	temp=head;
	printf("\n\nThe data of all the nodes after multiplying by 10:\n");
	for(int i=1;i<=n;i++)
	{
		printf("\nData of %d=%d",i,(temp->data)*10);
		temp=temp->next;
	}
}
