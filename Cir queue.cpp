#include<stdio.h>
#define max 100
int front=-1,rear=-1;
int queue[max];
void enqueue()
{
	int data;
	if(rear==max-1)
	{
		printf("Queue is full\n");
	}
	if(front==-1)
	{
		rear++;
		front++;
		printf("Enter the value in the queue:");
		scanf("%d",&data);
		queue[rear]=data;
	}
	else
	{
		rear++;
		printf("Enter the value into the queue:");
		scanf("%d",&data);
		queue[rear]=data;
	}
	printf("Sucessfully inserted\n");
}
void dequeue()
{
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Dleleted sucessfully\n");
		printf("Deleted element=%d\n",queue[front]);
		front=(front+1)%max;
		if(front==max)
		{
			front=rear=-1;
		}
	}
}
void display()
{
	int i=front;
	if(i==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue elements are:");
		while(i!=rear)
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
