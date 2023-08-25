#include<stdio.h>
#define max 100
int stack[max];
int top=-1;
void push()
{
	int data;
	printf("Enter the data to insert into the stack:");
	scanf("%d",&data);
	if(top=max-1)
	{
		printf("Stack Over flow\n");
	}
	else
	{
		top++;
		stack[top]=data;
		printf("The data is succefully inserted into the stack\n");
	}
}
void pop()
{
	int delete_data;
	if(top==-1)
	{
		printf("Stack under flow\n");
	}
	else
	{
		delete_data=stack[top];
		top--;
		printf("Removed data=%d\n",delete_data);
	}
}
void Top()
{
	int top_data;
	top_data=stack[top];
	printf("Top data in the stack =%d",top_data);
}
void display()
{
	int i;
	if(top>=0)
	{
		printf("The elements in Stack");
		for(i=top;i>=0;i--)
		{
			printf("The element in stack is :%d",stack[i]);
		}
	}
	else
    {
        printf("\n The STACK is empty");
    }
}
main()
{
	int i=0,j;
	printf("Enter 1 to push \n");
	printf("Enter 2 to pop\n");
	printf("Enter 3 to top\n");
	printf("Enter 4 to display\n");
	printf("Enter 5 to exit\n");
	while(1)
	{
	printf("Enter the choice:");
	scanf("%d",&j);
	if(j==1)
	{
		push();
		continue;
	}
	else if(j==2)
	{
		pop();
		continue;
	}
	else if(j==3)
	{
		Top();
		continue;
	}
	else if(j==4)
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
