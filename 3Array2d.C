#include<stdio.h>
#include<conio.h>
int arr[3][3],i,j,choice,item,m,n;

void main()
{
clrscr();
printf("Enter the elements of 2D array\n");
for(i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
scanf("%d",&arr[i][j]);
}
}
printf("Enter the choice:\n1)Insertion\n2)Deletion\n3)Traversal\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the item and index(row and column value)\n");
scanf("%d %d %d",&item,&m,&n);
arr[m][n]=item;
for(i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
printf("%d ",arr[i][j]);
}
printf("\n");
}
break;

case 2:
printf("Enter the item to be deleted\n");
scanf("%d",&item);
for(i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
if(arr[i][j]==item)
printf("%d ",0);
else
printf("%d ",arr[i][j]);
}
printf("\n");
}
break;

case 3:
for(i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
printf("%d ",arr[i][j]);
}
printf("\n");
}
break;

default:printf("Wrong Option\n");
}
getch();
}
