#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max 10
int queue[max], f1=-1, r1=-1, f2=max, r2=max, item;

void insert1()
{
if(r1==r2-1)
printf("Overflow Condition\n");
else
{
if(f1==-1)
{
r1++;
f1++;
}
else
r1++;
printf("Enter the item:\n");
scanf("%d",&item);
queue[r1]=item;
printf("%d is inserted in the queue1\n",item);
}
}

void insert2()
{
if(r1==r2-1)
printf("Overflow Condition\n");
else
{
if(f2==max)
{
r2--;
f2--;
}
else
r2--;
printf("Enter the item:\n");
scanf("%d",&item);
queue[r2]=item;
printf("%d is inserted in the queue2\n",item);
}
}

void deletion1()
{
if(f1==-1)
printf("Underflow Condition\n");
else
{
printf("Item deleted is :%d\n",queue[f1]);
if(f1==r1)
{
f1=-1;
r1=-1;
}
else
f1++;
}
}

void deletion2()
{
if(f2==max)
printf("Underflow Condition\n");
else
{
printf("Item deleted is :%d\n",queue[f2]);
if(f2==r2)
{
f2=max;
r2=max;
}
else
f2--;
}
}

void display1()
{
int i;
if(f1==-1)
printf("Queue1 is empty\n");
else
{
printf("Elements in the queue1 are:\n");
for(i=f1; i<=r1; i++)
printf("%d\t",queue[i]);
printf("\n");
}
}

void display2()
{
int i;
if(f2==max)
printf("Queue2 is empty\n");
else
{
printf("Elements in the queue2 are:\n");
for(i=f2; i>=r2; i--)
printf("%d\t",queue[i]);
printf("\n");
}
}

void main()
{
int ch;
do
{
clrscr();
printf("** Queue Menu **\n1)Insert in queue1\n2)Delete in queue1\n");
printf("3)Display queue1\n4)Insert in queue2\n5)Delete in queue2\n");
printf("6)Display in queue2\n7)Exit\nEnter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert1(); break;
case 2: deletion1(); break;
case 3: display1(); break;
case 4: insert2(); break;
case 5: deletion2(); break;
case 6: display2(); break;
case 7: exit(0);
}
printf("Press 0 to continue\n");
scanf("%d",&ch);
} while(ch==0);
getch();
}
