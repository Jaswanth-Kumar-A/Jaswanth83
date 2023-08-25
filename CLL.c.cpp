#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
		int data;
		struct node *next;
	};
	struct node *head;
struct node*create_cll()
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
			ptr=head;
	    }
	    else
	    {
	    	ptr->next=(struct node*)malloc(sizeof(struct node));
			ptr=ptr->next;
		}
		printf("Enter value of %d node:",i);
		scanf("%d",&ptr->data);
	}
	ptr->next=head;
	return(head);
}
struct node*display_cll(struct node*)
{
	struct node *ptr;
	ptr=head;
	while(ptr->next !=head);	
	{
		printf("Node value= %d\t",ptr->data);
		ptr=ptr->next;
	}	
	printf("%d",ptr->data);
}
struct node*search_cll(struct node*head)
{
	struct node *ptr;
	int flag=0,key;
	printf("\nEnter the key to search : ");
	scanf("%d",&key);
	ptr=head;
	while(ptr->next!=head)
	{
		if(ptr->data==key)
		{
			flag++;
			break;
		}
		ptr=ptr->next;
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
void insertbeg_cll()
{
	struct node*ptr,*newnode;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=head;
	printf("Enter the value into beg sll new node:");
	scanf("%d",&newnode->data);
	newnode->next=head;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
}
void insertmid_cll()
{
	struct node*newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	int loc,count=1;
	loc=n/2;
	ptr=head;
	printf("Enter the value in new node:");
	scanf("%d",&newnode->data);
	while(count!=loc)
	{
		ptr=ptr->next;
		count++;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
}
main()
{
	int j;
	create_cll();
	printf("Enter 1 to create and display linked list\n");
	printf("Enter 2 to search key linked list\n");
	printf("Enter 3 to insert at begging in linked list\n");
	printf("Enter 4 to insert middle location in linked list\n");
	printf("Enter 5 to insert ending in linked list\n");
	printf("Enter 6 to delete begging in linked list\n");
	while(1)
	{
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		display_cll(head);
		continue;
	}
	else if(j==2)
	{
		search_cll(head);
		continue;
	}
	else if(j==3)
	{
		insertbeg_cll();
		continue;
	}
	else if(j==4)
	{
		insertmid_cll();
		continue;
	}
}
}
