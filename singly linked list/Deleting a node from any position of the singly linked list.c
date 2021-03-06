#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
} *head;

void createList(int n);
void deleteNode(int position);
void displayList();

int main()
{
    int n, position;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    
    /*Displaying the list before deleting*/
    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the node position you want to delete: ");
    scanf("%d", &position);

    /*Delete from any position  from list */
    deleteNode(position);
    
    /*Showing the final list*/
    printf("\nData in the list \n");
    displayList();

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
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
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
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
                printf("Enter the data of node %d: ", i);
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
 * Delete from any position of the linked list
 */
void deleteNode(int position)
{
    int i;
    struct node *Delete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        Delete = head;
        prevNode = head;

        for(i=1; i<position; i++)
        {
            prevNode = Delete;
            Delete = Delete->next;

            if(Delete == NULL)
                break;
        }

        if(Delete != NULL)
        {
            if(Delete == head)
                head = head->next;

            prevNode->next = Delete->next;
            Delete->next = NULL;

            /* Delete nth node */
            free(Delete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}

/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;
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
            printf("Data of %d = %d\n",i,temp->data); // Print the data of current node
            temp = temp->next; // Move to next node
            i++;
        }
    }
}
