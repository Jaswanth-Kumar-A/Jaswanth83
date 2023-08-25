#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
		int data;
		struct node *lnext;
		struct node *rnext;
	};
	struct node *head;
struct node*create_cdll()
{
	struct node*ptr,*newnode;
	int n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			head=(struct node*)malloc(sizeof(struct node));
			head->lnext=NULL;
			ptr=head;
	    }
	    else
	    {
	    	newnode=(struct node*)malloc(sizeof(struct node));
			ptr->rnext=newnode;
			newnode->lnext=ptr;
			ptr=newnode;
		}
		printf("Enter value of %d node:",i);
		scanf("%d",&ptr->data);
	}
	ptr->rnext=head;
	head->lnext=ptr;
	return(head);
}
struct node*display_cdll(struct node*)
{
	struct node*ptr;
	ptr=head;
	while(ptr->rnext!=ptr);	
	{
		printf("Node value= %d\n",ptr->data);
		ptr=ptr->rnext;
	}	
}
struct node*search_cdll(struct node*head)
{
	struct node *ptr;
	int flag=0,key;
	printf("\nEnter the key to search : ");
	scanf("%d",&key);
	ptr=head;
	while(ptr!=head)
	{
		if(ptr->data==key)
		{
			flag++;
			break;
		}
		ptr=ptr->rnext;
	}
	if(flag==1)
	{
		printf("The element is found\n");
	}
	else
	{
		printf("The element is not found\n");
	}
}
struct node*insertbeg_cdll(struct node*head)
{
	struct node*ptr,*newnode;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->lnext=head;
	printf("Enter the value into beg sll new node:");
	scanf("%d",&newnode->data);
	newnode->lnext=head->lnext;
	head->lnext->rnext=newnode;
	newnode->rnext=head;
	head->lnext=newnode;
	return (head);
}
struct node*insert_beforeloc_cdll(struct node*head)
{
	struct node*ptr,*newnode;
	int loc;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the required location:");
	scanf("%d",&loc);
	printf("Enter the value into new node:");
	scanf("%d",&newnode->data);
	if(loc==1)
	{
		newnode->rnext=head;
		newnode->lnext=head->lnext;
		head->lnext=newnode;
		newnode->lnext->rnext=newnode;
		return newnode;
	}
	else
	{
		while(loc<2)
		{
			ptr=ptr->rnext;
			loc--;
		}
		newnode->rnext=ptr->rnext;
		newnode->lnext=ptr;
		newnode->rnext->lnext=newnode;
		ptr->rnext=newnode;
		return head;
	}
}
struct node*insert_afterloc_cdll(struct node*head)
{
	struct node*ptr,*newnode;
	int loc;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the requird loc:");
	scanf("%d",&loc);
	printf("Enter the value into newnode:");
	scanf("%d",&newnode->data);
	if(loc==1)
	{
		newnode->rnext=head->rnext;
		newnode->lnext=head;
		newnode->rnext->lnext=newnode;
		head->rnext=newnode;
	}
	else
	{
		while(loc>1)
		{
			head=head->rnext;
			loc--;
		}
		if(head->rnext!=NULL)
		{
			newnode->rnext=head;
			newnode->rnext->lnext=newnode;
			head->rnext=newnode; 
		}
		else
		{
			newnode->lnext=head;
			newnode->rnext=head->rnext;
			head->rnext=newnode;
			newnode->rnext->lnext=newnode;
		}
	}
}
void insertend_cdll()
{
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\n stack over flow");
    }
    else
    {
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            head=ptr;
            ptr->rnext=head;
            ptr->lnext=head;
        }
        else
        {
            temp=head;
            while(temp->rnext!=head)
            {
                temp=temp->rnext;
            }
            temp->rnext=ptr;
            ptr->lnext=temp;
            head->lnext=ptr;
            ptr->rnext=head;
        }
    }
}
void deletebeg_cdll()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("\n under flow");
    }
    else if(head->rnext==head)
    {
        head=NULL;
        free(head);
    }
    else
    {
        temp=head;
        while(temp->rnext!=head)
        {
            temp=temp->rnext;
        }
        temp->rnext=head->rnext;
        head->rnext->lnext=temp;
        free(head);
        head=head->rnext;
    }
}
main()
{
	int j;
	create_cdll();
	while(1)
	{
	printf("Enter 1 to create and display linked list\n");
	printf("Enter 2 to search key linked list\n");
	printf("Enter 3 to insert at begging in linked list\n");
	printf("Enter 4 to insert at before location in linked list\n");
	printf("Enter 5 to insert at after location in linked list\n");
	printf("Enter 6 to insert ending in linked list\n");
	printf("Enter 7 to delete begging in linked list\n");
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		display_cdll(head);
		continue;
	}
	else if(j==2)
	{
		search_cdll(head);
		continue;
	}
	else if(j==3)
	{
		insertbeg_cdll(head);
		continue;
	}
	else if(j==4)
	{
		insert_beforeloc_cdll(head);
		continue;
	}
	else if(j==5)
	{
		insert_afterloc_cdll(head);
		continue;
	}
	else if(j==6)
	{
		insertend_cdll();
		continue;
	}
	else if(j==7)
	{
		deletebeg_cdll();
		continue;
	}
    }
}
