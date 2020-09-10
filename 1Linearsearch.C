#include<stdio.h>
#include<conio.h>
int linear_search(int[],int,int);
void main()
{
int arr[100],search,c,n,position;
clrscr();
printf("Insert the no. of elements:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(c=0; c<n; c++)
{ scanf("%d",&arr[c]);
}
printf("Enter the element to be searched:\n");
scanf("%d",&search);
position=linear_search(arr,n,search);
if(position==-1)
printf("%d is not present in the given array\n");
else
printf("%d is present at index %d",search,position);
getch();
}

int linear_search(int arr[],int n, int search)
{
int i;
for (i=0; i<n; i++)
if(arr[i]==search)
return i;
return -1;
}