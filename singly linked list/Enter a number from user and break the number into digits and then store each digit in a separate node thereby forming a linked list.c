#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*temp;

int main()
{
	int n,count=0;
	
	printf("Enter a number from user:\n");
	scanf("%d",&n);
	
	int a=n;
	while(a!=0)
	{
		int c=a%10;
		count++;
		a=a/10;
	}
	
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("\nMEMORY ALLOCATION NOT POSSIBLE");
	}
	else
	{
		int c=n%10;
		head->data=c;
		printf("The value of node 1:%d\n",head->data);
		head->next=NULL;
		temp=head;
		n=n/10;	
	}
	
	for(int i=2;i<=count;i++)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nMEMORY ALLOCATION NOT POSSIBLE");
		}
		else
		{
			int c=n%10;
			newnode->data=c;
			printf("The value of node %d:%d\n",i,newnode->data);
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
			n/=10;
		}
	}
	
return 0;
}
