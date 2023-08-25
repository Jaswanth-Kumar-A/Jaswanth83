
#include<stdio.h>
#define max 100
int front=-1,rear=-1;
int queue[max];
void enqueue()
{
	int data;
	if(rear==max-1)
	{
		printf("Queue is empty\n");
	}
	if(front==-1)
	{
		rear++;front++;
		printf("ENter the value into queue:");
		scanf("%d",&data);
		queue[rear]=data;
	}
	else
	{
		rear++;
		printf("Enter the value into queue:");
		scanf("%d",&data);
		queue[rear]=data;
	}
	printf("Sucessfullu inserted\n");
}
void dequeue()
{
	int removed_data;
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		removed_data=queue[front];
		front++;
		printf("Removed data=%d",removed_data);
	    printf("Value removed sucessfully\n");
	    if(front>rear)
	    {
		    front-1;
		    rear=-1;
	    }
	}
}
void display()
{
	int i=front;
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue elements are:");
		while(i<=rear)
		{
			printf("%d\n",queue[i]);
			i=(i+1)%max;
		}
	}
}
main()
{
	int i=0,j;
	printf("Enter 1 to enqueue \n");
	printf("Enter 2 to dequeue\n");
	printf("Enter 3 to display\n");
	printf("Enter 4 to exit\n");
	while(1)
	{
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		enqueue();
		continue;
	}
	else if(j==2)
	{
		dequeue();
		continue;
	}
	else if(j==3)
	{
		display();
		continue;
	}
	else
	{
		break;
	}
}
}
