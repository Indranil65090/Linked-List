#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;// Data 
    struct node *next; // Address 
}*head,*temp;


void createList(int n);
void deleteFirstNode();
void displayList();



int main()
{
    int n, choice;

    /*
     * Create and display a singly linked list of n nodes
     */
    printf("Enter the total number of nodes:");
    scanf("%d", &n);
    createList(n);
    
	/*Display the list*/
    printf("\nData in the list are:\n");
    displayList();
    
    printf("\nPress 1 to delete first node:\n");
    scanf("%d", &choice);

    /* Delete first node from list */
    
	  if(choice == 1)
    {
    	deleteFirstNode();
	  }
    else
    {
    	printf("Wrong choice..! Data at the beginning cannot be deleted...Sorry..!\n");
	  }
	/*Displaying the elements of list after deletion*/
    printf("\nDatas in the final list are:\n");
    displayList();

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * In data of node from the user
         */
        printf("Enter the data of node 1:");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n-1 nodes and adds to linked list
         */
            for(i=2; i<=n; i++)
            {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d:", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/*
 * Deletes the first node of the linked list
 */
void deleteFirstNode()
{
    struct node *Delete;
	
    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        Delete = head;
        head=head->next;

        printf("\nData deleted=%d\n", Delete->data);

        /* Clears the memory occupied by first node*/
        free(Delete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
/*
 * Displays the entire list
 */
void displayList()
{
    int i=1;
    /*
     * If the list is empty i.e. head = NULL
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
            printf("Data of %d=%d\n",i,temp->data); // Print data of current node
            temp = temp->next;// Move to next node
            i++;
        }
    }
}
