#include<stdio.h>
#include<conio.h>
#define max 5
int dqueue[max], rear=-1, front=-1, item;
void insertr()
{
if(rear==max-1)
printf("Overflow Condition\n");
else
{
if(front==-1)
rear++, front++;
else
rear++;
printf("Enter the element to be inserted:\n");
scanf("%d",&item);
dqueue[rear]=item;
}
}

void insertf()
{
if(front==0)
printf("Overflow Condition\n");
else
{
if(front==-1)
front++, rear++;
else
front--;
printf("Enter the element to be inserted:\n");
scanf("%d",&item);
dqueue[front]=item;
}
}

void deletef()
{
if(front==-1)
printf("Underflow Condition\n");
else
{
printf("%d is deleted from the queue\n",dqueue[front]);
if(front==rear)
front=rear=-1;
else
front++;
}
}

void deleter()
{
if(rear==-1)
printf("Underflow Condition\n");
else
{
printf("%d is deleted from the queue\n",dqueue[rear]);
if(front==rear)
front=rear=-1;
else
rear--;
}
}

void display()
{
int i;
if(front==-1)
printf("Queue is empty.\n");
else
{
for(i=front; i<=rear; i++)
printf("%d\t",dqueue[i]);
}
}

void main()
{
int ch;
clrscr();
do
{
printf("*** Dequeue ***\n");
printf("1)Insert from rear\n2)Insert from front\n");
printf("3)Delete from front\n4)Delete from rear\n");
printf("5)Display\nEnter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insertr(); break;
case 2: insertf(); break;
case 3: deletef(); break;
case 4: deleter(); break;
case 5: display(); break;
default: printf("Wrong Choice\n");
}
printf("Press 0 for more operation\n");
scanf("%d",&ch);
}while(ch==0);
getch();
}
