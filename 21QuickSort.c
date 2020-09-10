#include<stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low , int high)
{
	int pivot = arr[high];
	int i = low-1;
	int j;

	for(j=low; j<=high-1; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

void printarray(int arr[],int size)
{
	int i;
	printf("***Sorted elements are:***\n");
	for(i=0; i<size; i++)
	{
		printf("%d	",arr[i]);
	}
}

int main()
{
	int n,i;
	printf("****QUICK SORT****\n");
	printf("How many elements you want to enter?\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	quicksort(arr,0,n-1);
	printarray(arr,n);
	return 0;
}
