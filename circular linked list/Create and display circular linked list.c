#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure
{
	int data;
	struct node *next;
}*head;

/*creating two functions,one for creating and another for displaying the circular list*/
void createlist(int n);
void displaylist();

int main()
{
	int n;

	printf("Enter the number of nodes:");
	scanf("%d",&n);
	createlist(n);
	
	printf("Display the list:");
	displaylist();
	
	return 0;
}

void createlist(int n)
{
	int i,value;
	struct node *temp,*newnode;
	head=(struct node *)malloc(sizeof(struct node));//allocating memory for the head node 
	if(head==NULL)//if unable to allocate memory
	{
		printf("No memory");
	}
	else
	{
		printf("Enter data for node 1:");
		scanf("%d",&value);
		head->data=value;//assign the data part of the head node with the value inserted by the user
		head->next=NULL;//initializing the next part of the head node as NULL
		temp=head;//now temp pointer variable pointing to the head node
	}
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory for the rest n-1 nodes
		if(newnode==NULL)//if unable to allocate memory
		{
			printf("No memory");
		}
		else
		{
			printf("Enter data for node %d:",i);
			scanf("%d",&value);
			newnode->data=value;//assign the data part of the rest of the nodes with the value inserted by the user
			newnode->next=NULL;//initially the next part of the newly created node with NULL
			temp->next=newnode;//the link of the new node with the head node is created 
			temp=newnode;//now temp pointer is pointing to the newnode
		}
	}
	temp->next=head;/*out of the loop so now temp variable will point to the last node of the list 
	whose address part or next part is now pointing to the head node to create the circular list*/
}

void displaylist()
{
	struct node *temp;
	int i=1;
	if(head==NULL)//if the list is empty 
	{
		printf("List is empty");
	}
	else
	{
		temp=head;//initializing the temp pointer variable with the head node
		do
		{
		printf("\nData of %d=%d",i,temp->data);//iterating through the list and showing the datas of the nodes of the list
		temp=temp->next;//iteration
		i++;
		}while(temp!=head);
	}
}
