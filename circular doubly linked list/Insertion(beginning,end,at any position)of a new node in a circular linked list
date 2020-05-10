#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*end;

void create(int n);
void display();
void insertbeg(int value);
void insertend(int value);
void insertatanypos(int value,int pos);
int n;

int main()
{
    int value,option,pos;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    create(n);
    printf("Display the list:\n");
    display();
    printf("Enter the option from user:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:printf("Enter the value to be inserted by user:");
               scanf("%d",&value);
               insertbeg(value);
               break;
        case 2:printf("Enter the value to be inserted by user:");
                scanf("%d",&value);
                insertend(value);
                break;       
        case 3:printf("Enter the position at which the new node to be inserted:");
                scanf("%d",&pos);
                printf("Enter the value to be inserted by the user:");
                scanf("%d",&value);
                insertatanypos(value,pos);
                break;
        default:printf("You entered wrong choice..!");
                break;        
    } 
    printf("Display the list after insertion:\n");
    display();

    return 0;           
}

void create(int n)
{
    int value;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        printf("Enter the value of the node 1:");
        scanf("%d",&value);
        head->data=value;
        head->next=NULL;
        head->prev=NULL;
        end=head;
    }
    for(int i=2;i<=n;i++)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory cannot be allocated");
        }
        else
        {
            printf("Enter the value of the node %d:",i);
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
            newnode->prev=end;
            end->next=newnode;
            end=end->next;
        }
    }
    end->next=head;
    head->prev=end;
}

void display()
{
    struct node *temp;
    temp=head;
    int i=1;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp->next!=head)
        {
            printf("Data of %d=%d\n",i,temp->data);
            temp=temp->next;
            i++;
        }
        printf("Data of %d=%d",i,temp->data);
    }
}

void insertbeg(int value)
{
    end->next=NULL;
    head->prev=NULL;

    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        newnode->data=value;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;

        end->next=head;
        head->prev=end;
    }
}

void insertend(int value)
{
    end->next=NULL;
    head->prev=NULL;

    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        newnode->data=value;
        end->next=newnode;
        newnode->prev=end;
        end=newnode;

        head->prev=end;
        end->next=head;
    }
}

void insertatanypos(int value,int pos)
{
    end->next=NULL;
    head->prev=NULL;
    
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int i=1;
    if(newnode==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        if(pos>n)
        {
            printf("You entered wrong position..!\n");
        }
        else if(pos==1)
        {
            insertbeg(value);
	    }
        else
        {
            while(i<pos-1 && temp!=NULL)
            {
                temp=temp->next;
                i++;
            }
            if(temp!=NULL)
            {
                newnode=(struct node *)malloc(sizeof(struct node));
                newnode->data=value;
                newnode->next=temp->next;
                newnode->prev=temp;
                if(temp->next!=NULL)
                {
                    temp->next->prev=newnode;
                }
                temp->next=newnode;
            }
        }
        head->prev=end;
        end->next=head;
    }
}
