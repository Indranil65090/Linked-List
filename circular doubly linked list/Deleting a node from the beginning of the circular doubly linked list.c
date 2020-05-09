#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*end;

void create(int n);
void display();
void deletehead();

int main()
{
	int n;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
		
	printf("Display the list:\n");
	display();
	
	deletehead();
	
	printf("Display the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	int value;	
	head=(struct node *)malloc(sizeof(struct node));
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
		head->prev=NULL;
		end=head;
	}
	for(int i=2;i<=n;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
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
			newnode->prev=end;
			end->next=newnode;
			end=end->next;
		}
	}
  /*creation of circular list*/
	end->next=head;
	head->prev=end;
}
void display()
{
	struct node *temp;
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
		printf("Data of %d=%d\n",i,temp->data);
	}
}
void deletehead()
{
  /*initially we are converting the circular doubly linked list into doubly linked list*/
	end->next=NULL;
	head->prev=NULL;
	
	struct node *temp;
	temp=head;
	printf("The value to be deleted is:%d\n",temp->data);//the data of the node to be deleted is shown
	
	head=head->next;//the node next to the head node is set as new head node
	temp->next=NULL;//the next part of the temp pointer pointing to the previous head(the node to be deleted) is set to NULL so as to disconnect it with the new head node
	head->prev=NULL;//the previous part of the new head node is also set to NULL so as to disconnect it with the node that is to be deleted
	free(temp);//deleting the node
  
	/*the circular list is again created*/
	end->next=head;
	head->prev=end;
}
