#include<stdio.h>
#include<conio.h>
void insertion();
void deletion();
void display();
void menu();
int a[50],n;

void main()
{
clrscr();
menu();
getch();
}

void menu()
{
int choice;
printf("Enter your choice\n1)Insertion\n2)Deletion\n3)Display\n4)Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertion(); break;
case 2:deletion(); break;
case 3:display(); break;
case 4:break;
}
}

void insertion()
{
int i,pos,k;
printf("Enter how many elements you want to enter:\n");
scanf("%d",&n);
printf("Enter your elements:\n");
for(i=0; i<n; i++)
scanf("%d",&a[i]);
printf("Enter the element to be inserted:\n");
scanf("%d",&k);
printf("Enter the position:\n");
scanf("%d",&pos);
for(i=n-1; i>=pos-1; i--)
{
a[i+1]=a[i];
}
a[pos-1]=k;
n++;
menu();
}

void deletion()
{
int i,pos;
printf("Enter position of element you want to delete:\n");
scanf("%d",&pos);
for(i=pos-1; i<n; i++)
{
a[i]=a[i+1];
}
menu();
}

void display()
{
int i;
for(i=0; i<n; i++)
{
printf("%d\t",a[i]);
}
printf("\n");
menu();
}
