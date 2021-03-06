#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // data 
    struct node *next; // next pointer to create link with the next node and the previous node  
}*head,*newNode, *temp;

void createList(int n);
void insertNodeAtPos(int data, int position);
void displayList();


int main()
{
    int n, data, position;

    /*
     * create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in the list \n");
    displayList();

    /*
     * insert data at specific position of the singly linked list
     */
    printf("Enter data to insert at specific position of the list: ");
    scanf("%d", &data);
    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
    insertNodeAtPos(data, position);

    printf("\nData in the list \n");
    displayList();
    return 0;
}

/*
 * create a list of n nodes
 */
void createList(int n)
{
   
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));//creating the first node

    /*
     * if unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * input data of node from the user
         */
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
	    head->data = data; // link the data field with data
            head->next = NULL; // link the address field to NULL
	    temp = head;
        /*
         * creates n-1 nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));//

            /* if memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // link the data field of newNode with data
                newNode->next = NULL; // link the address field of newNode with NULL

                temp->next = newNode; // link previous node i.e. temp to the newNode
                temp = temp->next;// jumping to the next nodes
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/*
 * creates a new node and inserts at any position of the linked list.
 */
void insertNodeAtPos(int data, int position)
{
    int i;
    newNode = (struct node*)malloc(sizeof(struct node));
	  if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // link data part
        newNode->next = NULL;
		temp = head;
		/* 
         * traverse to the n-1 position 
         */
        for(i=2; i<=(position-1); i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            /*link address part of new node */
            newNode->next = temp->next; 
			/* link address part of n-1 node */
            temp->next = newNode;

			printf("DATA INSERTED SUCCESSFULLY\n");
       }
       else
       {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
       } 
    }
}
/*
 * display entire list
 */
void displayList()
{
    /*
     * if the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        int i=1;
        while(temp != NULL)
        {
            printf("Data of %d=%d\n",i,temp->data); // print data of current node
            i++;
            temp = temp->next; // move to next node
        }
    }
}
