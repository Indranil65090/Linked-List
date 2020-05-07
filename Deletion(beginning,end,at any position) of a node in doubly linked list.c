#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*start, *end;
 

void create(int n);
void Deletebeg();
void DeleteLast();
void DeleteAnyNode(int pos);
void display();

int main()
{
    int n,num1,pos;
	  printf("Doubly Linked List\n");
	  printf("----------------------------------------------------------------------------------\n");	   	
    printf("Input the number of nodes:");
    scanf("%d", &n);
    create(n); 
   
    display();
    printf("Input the position ( 1 to %d ) to delete a node:",n);
    scanf("%d", &pos);
	  if(pos<1 || pos>n)
    {
     	  printf("Invalid position. Try again.\n");
    }
	  else
    {
    	  DeleteAnyNode(pos); 
    	  display();
    }    
    return 0;
}
 
void create(int n)
{
    int i, num;
    struct node *temp;
 
    if(n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
 
        if(start!= NULL)
        {
            printf("Input data for node 1:");//assigning data in the first node
            scanf("%d", &num);
 
            start->data = num;
            start->prev = NULL;
            start->next = NULL;
            end = start;
            for(i=2; i<=n; i++)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                if(temp != NULL)
                {
                    printf("Input data for node %d:",i);
                    scanf("%d", &num);
                    temp->data = num;
                    temp->prev = end;//new node is linking with the previous node
                    temp->next = NULL;//set next address of temp is NULL
                    end->next = temp;//previous node is linking with the new node
                    end = temp;//assign new node as last node
                }
                else
                {
                    printf("Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf("Memory can not be allocated.");
        }
    }
}

void DeleteAnyNode(int pos)
{
    struct node *temp;
    int i;
 
    temp=start;
    for(i=1; i<pos && temp!=NULL; i++)
    {
        temp = temp->next;
    }
 
    if(pos == 1)
    {
        Deletebeg();
    }
    else if(temp== end)
    {
        DeleteLast();
    }
    else if(temp != NULL)
    {
    	  printf("Tha data to be deleted is:%d\n",temp->data);//the data of the node to be deleted is shown
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
 		    free(temp);//Delete the n node
    }
    else
    {
        printf("The given position is invalid!\n");
    }
} 

void Deletebeg()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("Delete is not possible.No data in the list.\n");
    }
    else
    {
        temp= start;
        start = start->next;//move the next address of starting node to second node 
        start->prev = NULL;//set previous address of staring node is NULL
        printf("Tha data to be deleted is:%d\n",temp->data);//the data of the node to be deleted is shown
        free(temp);//delete the first node from memory
    }
}

void DeleteLast()
{
    struct node *temp;
 
    if(end== NULL)
    {
        printf("Delete is not possible. No data in the list.\n");
    }
    else
    {
        temp= end;
        end = end->prev;//move the previous address of the last node to scondlast node
        end->next = NULL;//set the next address of last node to NULL
        printf("Tha data to be deleted is:%d\n",temp->data);//the data of the node to be deleted is shown
        free(temp);//delete the last node
    }
}
void display()
{
    struct node *temp;
    int n=1;
    if(start==NULL)
    {
        printf("No data found in the list yet.");
    }    
    else
    {
        printf("The list is:\n");
        temp = start;
        while(temp != NULL)
        {
            printf("Data of %d:%d\n",n,temp->data);
            n++;
            temp = temp->next;//current pointer moves to the next node
        }
    }
}
