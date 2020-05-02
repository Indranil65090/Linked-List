#include<stdio.h>
#include<stdlib.h>

struct node //creating the self referential structure
{
	int data;
	struct node *next;
}*head,*temp,*b;

/*three functions created one for creating the list 
and one for inserting the new node and another for displaying the list*/
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
		printf("Enter the value of new node which should be included at the beginning:");
	    scanf("%d",&data);
		insert(data);
	}
	else
	{
		printf("Wrong choice..!.No insertion possible\n");
	}
	
	printf("The final list after insertion is:");
	display();
	
	return 0;
}


void create(int n)
{
	struct node *newnode;
	int data,i;
	head=(struct node *)malloc(sizeof(struct node)); //memory allocation for the head node
	if(head==NULL)
	{
		printf("NO memory to allocate");
	}
	else
	{
		printf("Enter the value of the 1 node:");
		scanf("%d",&data);		
		head->data=data; //assigning the data part of the head node with the value inserted by the user
		head->next=NULL; //intializing the next part of the head node with NULL
		temp=head; //storing the head node in a temporary pointer
	}
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node)); //allocating memory for rets of n-1 nodes
		if(newnode==NULL)
		{
			printf("NO memory to allocate memory");
		}
		else
		{
			printf("Enter the value of the %d node:",i);
			scanf("%d",&data);
			newnode->data=data; //the data part of the new node is given the value entered by the user
			newnode->next=NULL; //initializing the next part of the new node as NULL
			temp->next=newnode; //next part of the previous node is linked with new node
			temp=newnode;
 
		}
	}
	temp->next=head; //the next part of the last node is linked with head node to form circular linked list 
	
}

void insert(int data)
{
	struct node *newnode;
	
	newnode=(struct node *)malloc(sizeof(struct node)); //allocating memory for the new node to be inserted at the beginning of the list
	
	newnode->data=data; //the data part of the new node is given from the user
	newnode->next=head; //new node is linked with the head node
	
	b=head; //the new head node is temporarily taken in a pointer 
	
	while(b->next!=head)
	{
		b=b->next;
	}
	b->next=newnode; //creating the link to form the circular linked list
	head=newnode;
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
			printf("\nData of %d=%d",i,b->data); //displaying the data of the linked list
			b=b->next; //iterating through the list
			i++;
		}while(b!=head);
	}
}
