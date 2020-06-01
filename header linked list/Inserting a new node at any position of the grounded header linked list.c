 #include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*start,*end;

void create(int n);
void display();
void insertatanypos(int val,int pos);
int n;

int main()
{
	int pos,val;
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
	printf("\n\nEnter the position from user:");
	scanf("%d",&pos);
	printf("\nEnter the value of the node to be inserted at position %d:",pos);
	scanf("%d",&val);
	insertatanypos(val,pos);
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

void insertatanypos(int val,int pos)
{
	if(pos==1)
	{
		struct node *a;
		a=(struct node *)malloc(sizeof(struct node));
		if(a==NULL)
		{
			printf("\nNO MEMORY TO ALLOCATE");
		}
		else
		{
			a->data=val;
			start->next=a;
			a->next=head;
		}
		struct node *temp;
		temp=a;
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
	else if(pos==n)
	{
		struct node *a;
		a=(struct node *)malloc(sizeof(struct node));
		if(a==NULL)
		{
			printf("\nNO MEMORY TO ALLOCATE");
		}
		else
		{
			a->data=val;
			end->next=a;
			a->next=NULL;
		}
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
		struct node *a,*b,*temp;
		a=head;
		b=a->next;
		temp=(struct node *)malloc(sizeof(struct node));
		if(pos<n && pos>0)
		{
			if(temp==NULL)
			{
				printf("\nUNABLE TO ALLOCATE MEMORY");
			}
			else
			{
				for(int i=1;i<pos-1;i++)
				{
					a=a->next;
					b=b->next;
				}
				temp->data=val;
				a->next=temp;
				temp->next=b;
			}
			struct node *flag;
			flag=head;
			int i=1;
			if(head==NULL)
			{
				printf("\nLIST IS EMPTY");
			}
			else
			{
				while(flag!=NULL)
				{
					printf("\nData of %d=%d",i,flag->data);
					flag=flag->next;
					i++;
				}
			}
		}
		else
		{
			printf("\n\nYOU ENTERED WRONG POSITION");
		}
	}
}
