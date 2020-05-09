/**
Doubly linked list has three fields one for data part 
another to point to the next node and 
another field contains the address of the previous node 
*/
#include<stdio.h>
#include<stdlib.h>

struct node//creating the self referential structure containing three fields data,next pointer,previous pointer 
{
	int data;
	struct node *next;
	struct node *prev;
};

int main()
{
	int n,i,value;
	struct node *newnode,*p,*head;
	printf("Enter the no. of nodes:");
	scanf("%d",&n);
	printf("Enter the value of the node 1:");
	scanf("%d",&value);
	head=(struct node *)malloc(sizeof(struct node));//allocating memory block for the first node
	if(head==NULL)
	{
		printf("No memory to allocate");
	}
	else
	{
		head->data=value;
		head->next=NULL;
		head->prev=NULL;
		p=head;
	} 
	for(i=2;i<=n;i++)
	{
		printf("Enter the value of the node %d:",i);
		scanf("%d",&value);
		newnode=(struct node *)malloc(sizeof(struct node));//allocating memory block for the rest n-1 nodes
		if(newnode==NULL)
		{
			printf("No memory to allocate");
		}
		else
		{
		newnode->data=value;
		newnode->next=NULL;
		newnode->prev=p;
		p->next=newnode;
		p=p->next;
	    }
	}
	printf("The list is:\n");
	struct node *b;
	b=head;
	i=1;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
	while(b->next!=NULL)
	{
		printf("Data of %d=%d\n",i,b->data);
		i++;
		b=b->next;
	}
	printf("Data of %d=%d",i,b->data);//showing data of the last node as now b points to the last node
	}
	return 0;
}
