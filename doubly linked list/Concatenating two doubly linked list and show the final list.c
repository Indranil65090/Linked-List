#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head1,*end,*head2;

void create1(int n1);
void display1();
void create2(int n2);
void display2();
void join();
void display();

int main()
{
	int n1,n2;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n1);
	printf("\n");
	create1(n1);
	printf("\nDisplay the list:\n");
	display1();
	
	printf("\n******************FIRST DOUBLY LINKED LIST IS CREATED********************\n");
	
	printf("\nEnter the number of nodes:");
	scanf("%d",&n2);
	printf("\n");
	create2(n2);
	printf("\nDisplay the list:\n");
	display2();
	
	printf("\n******************SECOND DOUBLY LINKED LIST IS CREATED*******************\n");
	
	printf("\nDISPLAY THE FINAL LIST AFTER ADDING TWO DOUBLY LINKED LIST\n");
	
	join();
	printf("\n");
	printf("Display the final list:\n");
	display();
	
	return 0;
}
void create1(int n1)
{
	struct node *temp;
	head1=(struct node *)malloc(sizeof(struct node));
	int val;
	if(head1==NULL)
	{
		printf("\nNo memory to allocate");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&val);
		head1->data=val;
		head1->next=NULL;
		head1->prev=NULL;
		temp=head1;
	}
	for(int i=2;i<=n1;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nNo memory to allocate");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&val);
			newnode->data=val;
			newnode->next=NULL;
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
	end=temp;
}
void display1()
{
	struct node *b;
	b=head1;
	int i=1;
	if(head1==NULL)
	{
		printf("List is empty");	
	}
	else
	{
		while(b->next!=NULL)
		{
			printf("Data of %d is:%d\n",i,b->data);
			b=b->next;
			i++;
		}
	printf("Data of %d is:%d\n",i,b->data);
	}
}
void create2(int n2)
{
	struct node *temp;
	head2=(struct node *)malloc(sizeof(struct node));
	int val;
	if(head2==NULL)
	{
		printf("\nNo memory to allocate");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&val);
		head2->data=val;
		head2->next=NULL;
		head2->prev=NULL;
		temp=head2;
	}
	for(int i=2;i<=n2;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nNo memory to allocate");
		}
		else
		{
			printf("Enter the value of node %d:",i);
			scanf("%d",&val);
			newnode->data=val;
			newnode->next=NULL;
			newnode->prev=temp;
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void display2()
{
	struct node *b;
	b=head2;
	int i=1;
	if(head2==NULL)
	{
		printf("List is empty");	
	}
	else
	{
		while(b->next!=NULL)
		{
			printf("Data of %d is:%d\n",i,b->data);
			b=b->next;
			i++;
		}
	printf("Data of %d is:%d\n",i,b->data);
	}
}
void join()
{
	end->next=head2;
	head2->prev=end;
}
void display()
{
	struct node *temp;	
	temp=head1;
	int i=1;
	while(temp->next!=NULL)
	{
		printf("Data of %d is:%d\n",i,temp->data);
		temp=temp->next;
		i++;
	}
	printf("Data of %d is:%d\n",i,temp->data);
}
