#include<stdio.h>
#include<stdlib.h>

/*creating the self 
referential structure*/

struct node
{
	int data;
	struct node *next;
}*head;

/*creating three functions
one for creating one for displaying and 
another for deleting a node from beginning
*/

void create(int n);
void delete_beg();
void display();

int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	create(n);
	
	printf("Display the list:\n");
	
	display();
	
	delete_beg();//calling the function for deleting the node 
	
	printf("\nDisplay the list:\n");
	
	display();
	
	return 0;
}

void create(int n)
{
	int value,i;
	struct node *temp,*newnode;
	head=(struct node *)malloc(sizeof(struct node));//allocating memory for the first node or head node
	if(head==NULL)
	{
		printf("Memory cannot be allocated");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&value);
		head->data=value;
		head->next=NULL;
		temp=head;
	}
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory for the rest n-1 number of nodes
		if(newnode==NULL)
		{
			printf("Memory cannot be allocated");
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
	temp->next=head;
}

void delete_beg()
{
	struct node *b,*store;
	b=head;//b is storing the head node 
	while(b->next!=head)//moving the loop until last node is reached
	{
		b=b->next;//traversing the list to shift b to the last node
	}
	store=head;//storing the head in the temporary variable
	head=head->next;//shifting the head to the next node so that the next node becomes the new head 
	printf("The deleted node is:%d",store->data);//showing the data that is needed to be deleted
	b->next=head;//next part of b is now pointing to the new head
	free(store);//freeing the memory allocated for the head node
}

void display()
{
	int i=1;
	struct node *a;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		a=head;
		do
		{
		 
			printf("Data of %d:%d\n",i,a->data);
			a=a->next;
			i++;
		}while(a!=head);
	}
}
