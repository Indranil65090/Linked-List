#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // data 
    struct node *next; // next pointer to create the link with next node
}*head,*newNode,*temp,*a;


void createList(int n);
void insertNodeAtend(int data);
void displayList();


int main()
{
    int n, data;
    
    /*
     * create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    
    /*display the list*/
	printf("\nData in the list \n");
    displayList();

    /*
     * insert data at the end of the singly linked list
     */
    printf("\nEnter data to insert at the endof the list: ");
    scanf("%d", &data);
    insertNodeAtend(data);
    
    /*display the final the list after insertion*/
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

    head = (struct node *)malloc(sizeof(struct node));//allocating memory for the first node
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
         * input data of the first node from the user
         */
        printf("Enter the data of node 1:");
        scanf("%d", &data);

        head->data = data; // link data field with data
        head->next = NULL; // link address field to NULL
	      temp = head;

        /*
         * create n-1 nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));//allocating memory for the rest of the nodes

            /* if memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d:",i);
                scanf("%d", &data);

                newNode->data = data; // link data field of newNode with data
                newNode->next = NULL; // link address field of newNode with NULL

                temp->next = newNode; // link previous node i.e. temp to the newNode
                
                temp = temp->next; //jumping to the next node
            }
        }
		    a=temp; //taking the last node in a temporary node
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/*
 * create a new node and inserts at the end of the linked list.
 */
void insertNodeAtend(int data)
{
        struct node *b;
	      b=a; //the last node is now present in a new node 
        newNode = (struct node*)malloc(sizeof(struct node)); //allocating memory for the new node to be inserted at last
        if(newNode == NULL)
        {
        printf("Unable to allocate memory.");
        } 
        else
        {
        newNode->data = data; // link data part
        b->next=newNode; //next part of the last node is now pointing to the newly created node instead of NULL
        newNode->next = NULL; // next part of the new node is NULL

        b = newNode;// make new node as last node

        printf("DATA INSERTED SUCCESSFULLY\n");
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
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // print data of current node
            temp = temp->next; // move to next node
        }
    }
}
