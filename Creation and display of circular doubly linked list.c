#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;

void create(int n);
void display();

int main()
{
	int n;
  
	printf("Enter the number of nodes:");
	scanf("%d",&n);
  create(n);
  
	printf("Display the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	struct node *newnode,*temp;
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
  
	/*creation of circular doubly linked list,all codes above are same as that
	of the creation of doubly linked list but the below two lines of code 
	creates the circular doubly linked list*/
	
	temp->next=head;//linking the last node with the first node or head node
	head->prev=temp;//linking the head node with the last node
	
}

void display()
{
	int i=1;
	struct node *temp;
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
