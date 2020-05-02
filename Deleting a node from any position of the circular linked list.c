#include<stdio.h>
#include<stdlib.h>
/*creating the self referential structure*/
struct node
{
	int data;
	struct node *next;
}*head;


/*creating three functions one for creating one for displaying 
and another for deleting the node*/

void create(int n);
void delete_npos(int position);
void display();

int main()
{
	int n,position;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	create(n);
	
	printf("Display the list:\n");
	display();
	
	printf("Enter the position:");
	scanf("%d",&position);
	delete_npos(position);//calling the function for deleting a node from any position of the circular linked list
	
	printf("\nDisplay the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	int value,i;
	struct node *temp,*newnode;
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
		temp=head;
	}
	for(i=2;i<=n;i++)
	{
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
			temp->next=newnode;
			temp=temp->next;
		}
	}
	temp->next=head;
}

void delete_npos(int position)
{
	 struct node *b,*c;
	 b=head;
	 int k=1; 
	 while(k!=position)
	 {
	 	c=b;
	 	b=b->next;
	 	k++;
	 }
	 c->next=b->next;
	 printf("The node to be deleted is:%d",b->data);
	 free(b);
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
