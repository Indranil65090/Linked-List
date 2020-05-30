#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*temp,*end;

void create(int n);
void display();
void showfromend(int m);
int n;
int main()
{
	int m;
  
	printf("ENTER THE NUMBER OF NODES:");
	scanf("%d",&n);
	printf("\n");
  	create(n);
  	printf("\nDISPLAY THE LIST:\n\n");
	display();
	printf("\n\nEnter the position whose value is to be find:");
	scanf("%d",&m);
	showfromend(m);
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
	end=temp;

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
		while(temp->next!=NULL)
		{
			printf("Data of %d=%d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
		printf("Data of %d=%d",i,temp->data);
	}
}
void showfromend(int m)
{
	temp=end;
	if(m<=n)
	{
		for(int i=n-1;i>=m;i--)
		{
			temp=temp->prev;
		}
		printf("\nThe value of node %d is:%d",m,temp->data);
	}
	else
	{
		printf("\nYou entered wrong position\n");
	}
}
