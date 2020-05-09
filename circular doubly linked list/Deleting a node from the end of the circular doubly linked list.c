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
void deleteend();

int main()
{
	int n;
	
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
		
	printf("Display the list:\n");
	display();
	
	deleteend();
	
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
void deleteend()
{
	  end->next=NULL;
	  head->prev=NULL;
	  
	  struct node *temp;
	  temp=end;
	  printf("The value to be deleted is:%d\n",temp->data);
	  end=end->prev; 
	  temp->prev=NULL;
	  end->next=NULL;
	  free(temp);
	  
	  head->prev=end;
	  end->next=head;
}
