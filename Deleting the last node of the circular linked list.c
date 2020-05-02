#include<stdio.h>
#include<stdlib.h>
/*creating the self referential structure*/
struct node
{
	int data;
	struct node *next;
}*head;

/*creating three functions one for creating one for displaying 
and another for deleting the last node*/

void create(int n);
void delete_last();
void display();

int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	create(n);
	
	printf("Display the list:\n");
	display();
	
	delete_last();//calling the function for deleting the last node of the circular linked list
	
	printf("\nDisplay the list:\n");
	display();
	
	return 0;
}

void create(int n)
{
	int value,i;
	struct node *temp,*newnode;
	head=(struct node *)malloc(sizeof(struct node));//allocating memory for the first node
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
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory for the rest of the n-1 nodes
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

void delete_last()
{
	struct node *b,*p;
	b=head;//b is storing the head node 
	p=head;//p is storing the head node 
	while(b->next!=head)//moving the loop until last node is reached
	{
		b=b->next;//traversing the list to shift b to the last node
	}
	while(p->next!=b)//p is also shifted till the second last node
	{
		p=p->next;//traversing till the second last node of the list
	}
	printf("The data to be deleted is:%d",b->data);//showing data of the last node
	b->next=NULL;//breaking the link between the last node and the head node 
	p->next=head;//creating a new link between the second last node and the head node to form the circular linked list
	free(b);//freeing the memory allocated for last node 
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
