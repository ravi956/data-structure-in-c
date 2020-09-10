#include<stdio.h>
#include<conio.h>
#define max 10
int queue[max], front=-1, rear=-1, element;
void insertion();
void deletion();
void display();
void menu();

void main()
{
clrscr();
menu();
getch();
}

void menu()
{
int ch;
printf("Enter the choice:\n1)Insertion\n2)Deletion\n3)Display\n4)Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insertion();
	break;
case 2:deletion();
	break;
case 3:display();
	break;
case 4: break;
default: printf("Wrong Choice\n");
}
}

void insertion()
{
if(rear==max-1)
{
printf("Overflow Condition.\n");
}
else if(front==-1)
{
rear++;
front++;
}
else
{
rear++;
}
printf("Enter the element to be inserted:\n");
scanf("%d",&element);
queue[rear]=element;
menu();
}

void deletion()
{
if(front==-1)
{
printf("Underflow Condition\n");
}
else
{
printf("Item deleted is: %d\n",queue[front]);
if (front==rear)
{
front=-1;
rear=-1;
}
else
{
front++;
}
}
menu();
}

void display()
{
int i;
if(front==-1)
{
printf("Queue is empty.\n");
}
else
{
printf("Elements in the queue are:\n");
for(i=front; i<=rear; i++)
{
printf("%d\t",queue[i]);
}
printf("\n");
}
menu();
}
