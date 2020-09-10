#include<stdio.h>

int main()
{
	int n,i,j,key;
	printf("****INSERTION SORT****\n");
	printf("How many elements you want to enter?\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("***Sorted elements are:***\n");
	for(i=1; i<n; i++)
	{
		j=i-1;
		key=arr[i];
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	for(i=0; i<n; i++)
	{
		printf("%d	",arr[i]);
	}
	return 0;
}
