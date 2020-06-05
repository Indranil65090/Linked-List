#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*start,*end;
void create(int n);
void display();
void insertatanypos();
struct node *newNode;
int n;
int main()
{
	start=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\nMEMORY ALLOCATION NOT POSSIBLE");
	}
	else
	{
		printf("Enter the number of nodes:");
		scanf("%d",&n);
		start->data=n;
		start->next=NULL;
	}
	create(n);
	printf("\nDisplay the list:");
	display();
	insertatanypos();
	return 0;
}
void create(int n)
{
	struct node *temp,*newnode;
	int value;
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
		head->prev=NULL;
		start->next=head;
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
			newnode->prev=temp;
			temp=temp->next;
		}
	}
	end=temp;
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
void insertatanypos()
{
	int data,pos;
	struct node *temp,*temp1;
	temp=head;
	temp1=temp->next;
	printf("\n\nEnter the position at which the new node is to be inserted:");
	scanf("%d",&pos);
	printf("Enter the data to be inserted at psoition %d:",pos);
	scanf("%d",&data);
	newNode=(struct node *)malloc(sizeof(struct node));
	if(pos<=n+1)
	{
		if(newNode==NULL)
		{
			printf("\nMEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			if(pos==1)
			{
				newNode->data=data;
				start->next=newNode;
				newNode->prev=start;
				newNode->next=head;
				head->prev=newNode;
				printf("\nDisplay the list:");
				struct node *temp;
				temp=newNode;
				int i=1;
				if(newNode==NULL)
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
			else if(pos==n+1)
			{
				newNode->data=data;
				end->next=newNode;
				newNode->prev=end;
				newNode->next=NULL;
				printf("\nDisplay the list:");
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
			else
			{
				for(int i=1;i<pos-1;i++)
				{
					temp=temp->next;
					temp1=temp1->next;
				}	
				newNode->data=data;
				temp->next=newNode;
				newNode->prev=temp;
				newNode->next=temp1;
				temp1->prev=newNode;
				printf("\nDisplay the list:");
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
		}
	}
	else
	{
		printf("\nYOU ENTERED WRONG CHOICE");
	}
}
