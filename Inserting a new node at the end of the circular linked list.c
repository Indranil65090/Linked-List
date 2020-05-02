#include<stdio.h>
#include<stdlib.h>

struct node//creating the self-referential structure
{
	int data;
	struct node *next;
}*head,*temp,*b;

/*the three functions for creation,insertion,display*/

void create(int n);
void insert(int data);
void display();

int main()
{
	int data,n,choice;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	create(n);
	
	printf("Displaying the list:");
	display();
	
	
	printf("\nEnter the choice:");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		printf("Enter the value of new node which should be included at the end:");
		scanf("%d",&data);
	
		insert(data);
	}
	else
	{
		printf("\nNo insertion possible!!!!!!!\n");
	}
	
	
	printf("\nThe final list after insertion is:");
	display();
	
	return 0;
}


void create(int n)
{
	struct node *newnode;
	int data,i;
	head=(struct node *)malloc(sizeof(struct node));//allocating memory for the head node
	if(head==NULL)
	{
		printf("NO memory to allocate");
	}
	else
	{
		printf("Enter the value of the 1 node:");
		scanf("%d",&data);		
		head->data=data;//the data part of the node is given by the user
		head->next=NULL;//the next part initially taken as NULL
		temp=head;
	}
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory for the rest n-1 nodes
		if(newnode==NULL)
		{
			printf("NO memory to allocate memory");
		}
		else
		{
			printf("Enter the value of the %d node:",i);
			scanf("%d",&data);
			newnode->data=data;//the data part of the new node is given by the user
			newnode->next=NULL;//initializing the next part of the new node as NULLL
			temp->next=newnode;//linking the previous node with the current node
			temp=temp->next;//iterating through the list
		}
	}
	temp->next=head;//linking the last node with the head node to create a circular linked list
	b=temp;
}

void insert(int data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));//new node to be inserted is created 
	newnode->data=data;//the data part of the new node is given as specified by the user
  
	while(b->next!=head)
	{
		b=b->next;
	}
	b->next=newnode;//linking the last node to the new node
	newnode->next=head;//the next part of the last node is now pointing to the head node
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
		b=head;
		do
		{
			printf("\nData of %d=%d",i,b->data);//dispalying the data of each node of the list
			b=b->next;//iterating through the list
			i++;
		}while(b!=head);
	}
}
