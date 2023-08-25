#include<stdio.h>
#include<stdlib.h>
struct node
{
		int data;
		struct node *next;
	};
	struct node *head;	
void create_sll()
{
	
	int i,n;
	struct node *ptr;
	printf("Enter no of elements: ");
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
		printf("\n Enter an %dth element : ",i);
	    scanf("%d",&ptr->data);
	}
    ptr->next=NULL;
}
void display_sll(struct node*head)
{
	struct node*ptr;
	ptr=head;
	while(ptr!=0)
	{
		printf("node value = %d\n",ptr->data);
		ptr=ptr->next;
	}
}
struct node*search_sll(struct node*head)
{
	struct node *ptr;
	int flag=0,key;
	printf("\nEnter the key to search : ");
	scanf("%d",&key);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			flag=1;
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
void insertbeg_sll()
{
	struct node*ptr,*newnode;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the value into beg sll new node:");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
}
void insertmid_sll()
{
	struct node*newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	int loc,count=1;
	printf("Enter value of mid sll new node:");
	scanf("%d",&newnode->data);
	loc=n/2;
	ptr=head;
	while(count!=loc)
	{
		ptr=ptr->next;
		count++;
	}
	newnode->next=ptr->next;
}
void insertend_sll()
{
	struct node*ptr,*newnode;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the value into end sll new node:");
	scanf("%d",&newnode->data);
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
}
void deletebeg_sll()
{
	struct node *ptr;
	ptr=head;
	head=head->next;
	free(ptr);
}
void deleteend_sll()
{
	struct node*ptr,*temp;
	ptr=head;
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);
}
void deletemid_sll()
{
	struct node*temp,*ptr;
	int loc,count=1;
	loc=n/2;
	ptr=head;
	while(count!=loc)
	{
		temp=ptr;
		free(ptr);
	}
}
void deleteloc_sll()
{
	int loc,count=0;
	struct node*ptr,*temp;
	printf("Enter the location of a node to delete:");
	scanf("%d",&loc);
	ptr=head;
	while(count!=loc)
	{
		temp=ptr;
		ptr=ptr->next;
		count++;
	}
	temp->next=ptr->next;
	free(ptr);
}
main()
{
	int j;
	create_sll();
	printf("Enter 1 to create and display linked list\n");
	printf("Enter 2 to search key linked list\n");
	printf("Enter 3 to insert at beggining in linked list\n");
	printf("Enter 4 to insert at middle location in linked list\n");
	printf("Enter 5 to insert at ending in linked list\n");
	printf("Enter 6 to delete at beggining in linked list\n");
	printf("Enter 7 to delete at middle location in linked list\n");
	printf("Enter 8 to delete at ending in linked list\n");
	printf("Enter 9 to delete at required location in linked list\n");
	printf("ENter 10 to exit\n");
	while(1)
	{
		
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		display_sll(head);
		continue;
	}
	else if(j==2)
	{
		search_sll(head);
		continue;
	}
	else if(j==3)
	{
		insertbeg_sll();
		continue;
	}
	else if(j==4)
	{
		insertmid_sll();
		continue;
	}
	else if(j==5)
	{
		insertend_sll();
		continue;
	}
	else if(j==6)
	{
		deletebeg_sll();
		continue;
	}
	else if(j==7)
	{
		deletemid_sll();
		continue;
	}
	else if(j==8)
	{
		deleteend_sll();
		continue;
	}
	else if(j==9)
	{
		deleteloc_sll();
		continue;
	}
	else
	{
		break;
	}
}
}
