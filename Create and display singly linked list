#include<stdio.h>
#include<stdlib.h>

/*creation of self referential structure*/
 typedef struct node
{
	int data;
	struct node *next;
}node;
struct node *temp,*start,*end,*new_node;
int main()
{
	int n,i=1,element,value;
	printf("Enter the total no. of nodes:");
	scanf("%d",&n);
	printf("The value of the node %d:",i);
	scanf("%d",&element);
	
	temp=(struct node*)malloc(sizeof(struct node));//first node creation
	temp->data=element;
	temp->next=NULL;
	start=temp;
	end=start;
	
	/*entering the values of other nodes and moving from one node to other thus linking the nodes*/
	
	for(i=2;i<=n;i++)  //other nodes creation
	{
		printf("The value of the node %d:",i);
		scanf("%d",&element);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=element;
		temp->next=NULL;
		start->next=temp; 
		start=start->next;
	}
	
	/*the output is shown*/
	
	printf("The output is:");
	start=end;
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
    }
 	return 0;
}
