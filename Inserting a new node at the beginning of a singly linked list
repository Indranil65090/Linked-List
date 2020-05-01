#include <stdio.h>
#include <stdlib.h>


/* structure of a node */
struct node {
    int data;          // data 
    struct node *next; // next pointer to create the link
}*head,*newNode,*temp;

void createList(int n);
void insertNodeAtBeginning(int data);
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
	/*
	*display the singly linked list
	*/
    printf("\nData in the list \n");
    displayList();

    /*
    * insert data at the beginning of the singly linked list
    */
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);
    /*
	* display the singly linked list after insertion
	*/
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

    head = (struct node *)malloc(sizeof(struct node));
    
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

        head->data = data; // link data field with data
        head->next = NULL; // link address field to NULL
	    temp = head; // taking a temporary pointer to node which stores the value of the head node 

        /*
        * create n-1 nodes and adds to linked list
        */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

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

                newNode->data = data; // data field of the newnode is given,it's value is entered by the user
                newNode->next = NULL; // link address field of newNode with NULL

                temp->next = newNode; // link previous node i.e. temp to the newNode
                
                temp = temp->next; //incrementing the temp pointer
            }
        }
	
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/*
 * create a new node and inserts at the beginning of the linked list.
 */
void insertNodeAtBeginning(int data)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // newnode to be inserted is created and data part is linked 
        newNode->next = head; // link address part

        head = newNode;  // make newNode as first node or head node

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
            temp = temp->next;                 // move to next node or incrementing through the linked list
        }
    }
}
