#include<stdio.h>
int binary_search(int a[],int key,int n)
{
    int start=0;
	int end=n-1;
	int mid;
    while(start<=end)
	{
		mid=(start+end)/2;
		if(a[mid]==key)
        {
            return mid;
        }
        if(a[mid]<key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n,i,key,search;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter the search element:");
    scanf("%d",&key);
    search=binary_search(a,key,n);
    if(search!=-1)
    {
        printf("Search element %d is found at index %d",key,search);
    }
    else
    {
        printf("Search element is not found");
    }
}
