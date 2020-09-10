#include<stdio.h>

int main()
{
	int n, temp, i, j;
	printf("****SELECTION SORT****\n");
	printf("How many elements you want to enter:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0; i<n-1; i++)
	{
		int imin=i;
		int flag=0;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[imin])
			{
				imin=j;
				flag=1;
			}
		}
		if(flag==0)
		break;
		temp=arr[imin];
		arr[imin]=arr[i];
		arr[i]=temp;
	}
	printf("***Sorted elements are:***\n");
	for(i=0; i<n; i++)
	{
		printf("%d	",arr[i]);
	}
	return 0;
}
