#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
		struct node*Lnext;
		int data;
		struct node*Rnext;
	};
struct node *head;	
struct node*create_dll()
{
	int i,n;
	struct node *ptr ,*newnode;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			head=(struct node*)malloc(sizeof(struct node));
			head->Lnext=NULL;
			ptr=head;
		}
		else
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			ptr->Rnext=newnode;
			newnode->Lnext=ptr;
			ptr=newnode;
		}
		printf("\n Enter an %dth element : ",i);
	    scanf("%d",&ptr->data);
	}
    ptr->Rnext=NULL;
}
struct node*display_dll(struct node*head)
{
	struct node*ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("node value = %d\n",ptr->data);
		ptr=ptr->Rnext;
	}
}
struct node*search_dll(struct node*head)
{
	struct node*ptr;
	int found=0,key;
	printf("Enter the key:");
	scanf("%d",&key);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			found=1;
			break;
		}
		ptr=ptr->Rnext;
	}
	if(found==1)
	{
		printf("The element found\n");
	}
	else
	{
		printf("The element not found\n");
	}	
}
void insertbeg_dll()
{
	struct node*ptr,*newnode;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->Lnext=NULL;
	printf("Enter the value into newnode:");
	scanf("%d",&newnode->data);
	newnode->Rnext=head;
	head->Lnext=newnode;
	head=newnode;
}
void insertmid_dll()
{
	struct node*newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	int loc,count=1;
	printf("Enter value of mid dll new node:");
	scanf("%d",&newnode->data);
	loc=n/2;
	ptr=head;
	while(count!=loc)
	{
		ptr=ptr->Rnext;
		count++;
	}
	newnode->Rnext=ptr->Rnext;
	ptr->Rnext=newnode;
	newnode->Lnext=ptr;
}
void insertloc_dll()
{
	struct node*newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	int loc=2,count=1;
	ptr=head;
	while(count!=loc)
	{
		ptr=ptr->Rnext;
		count++;
	}
	newnode->Rnext=ptr->Rnext;
	ptr->Rnext=newnode;
	newnode->Lnext=ptr;
}
void insertend_dll()
{
	struct node*newnode,*ptr;
	ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->Rnext=NULL;
	printf("Enter the value into end dll new node:");
	scanf("%d",&newnode->data);
	while(ptr->Rnext!=NULL)
	{
		ptr=ptr->Rnext;
	}
	ptr->Rnext=newnode;
	newnode->Lnext=ptr;
}
void deletebeg_dll()
{
	struct node *ptr;
	ptr=head;
	head=head->Rnext;
	free(ptr);
	ptr = head;
}
void deletemid_dll()
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
void deleteend_dll()
{
	struct node*ptr,*temp;
	ptr=head;
	while(ptr->Rnext!=NULL)
	{
		temp=ptr;
		ptr=ptr->Rnext;
	}
	temp->Rnext=NULL;
	free(ptr);
}
struct node*deleteloc_dll(struct node*head)
{
	int loc,count=0;
	struct node*ptr,*temp;
	printf("Enter the location of a node to delete:");
	scanf("%d",&loc);
	ptr=head;
	while(count!=loc)
	{
		temp=ptr;
		ptr=ptr->Rnext;
		count++;
	}
	temp->Rnext=ptr->Rnext;
	free(ptr);
	return(head);
}
int main()
{
	int j;
	create_dll();
	printf("Enter 1 to create and display linked list\n");
	printf("Enter 2 to search key linked list\n");
	printf("Enter 3 to insert at beggining in linked list\n");
	printf("Enter 4 to insert at middle location in linked list\n");
	printf("Enter 5 to insert at ending in linked list\n");
	printf("Enter 6 to insert at required location in linked list\n");
	printf("Enter 7 to delete at beggining in linked list\n");
	printf("Enter 8 to delete at middle location in linked list\n");
	printf("Enter 9 to delete at ending in linked list\n");
	printf("Enter 10 to delete at required location in linked list\n");
	printf("ENter 11 to exit\n");
	while(1)
	{
		
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		display_dll(head);
		continue;
	}
	else if(j==2)
	{
		search_dll(head);
		continue;
	}
	else if(j==3)
	{
		insertbeg_dll();
		continue;
	}
	else if(j==4)
	{
		insertmid_dll();
		continue;
	}
	else if(j==5)
	{
		insertend_dll();
		continue;
	}
	else if(j==6)
	{
		insertloc_dll();
		continue;
	}
	else if(j==7)
	{
		deletebeg_dll();
		continue;
	}
	else if(j==8)
	{
		deletemid_dll();
		continue;
	}
	else if(j==9)
	{
		deleteend_dll();
		continue;
	}
	else if(j==10)
	{
		deleteloc_dll(head);
		continue;
	}
	else
	{
		break;
	}
}
}
