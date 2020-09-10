#include<stdio.h>

int main()
{
	int n,i,j,temp;
	printf("How many elements you want to enter?\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0; i<n-1; i++)
	{
		int flag=0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j+1]<arr[j])
			{
				flag=1;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(flag==0)
		break;
	}
	printf("***Sorted elements are:***\n");
	for(i=0; i<n; i++)
	{
		printf("%d	",arr[i]);
	}
	return 0;
}
