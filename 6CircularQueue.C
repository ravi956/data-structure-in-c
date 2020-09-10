#include<stdio.h>
#include<conio.h>
#define max 3
int cqueue[max];
int front=-1, rear=-1;

void insert()
{
int item;
if(front==(rear+1)%max)
printf("** Overflow : Queue is full **\n");
else
{
if(front==-1)
rear=0, front=0;
else
rear=(rear+1)%max;
}
printf("Enter the item to be inserted:\n");
scanf("%d",&item);
cqueue[rear]=item;
printf("%d is inserted in the queue\n",item);
}

void deletion()
{
if(front==-1)
printf("** Underflow : Queue is empty **\n");
else
{
printf("%d is deleted from the queue\n",cqueue[front]);
if(front==rear)
front=-1, rear=-1;
else
front=(front+1)%max;
}
}

void display()
{
int i;
if(front==-1)
printf("** The Queue is empty **\n");
else
{
if(rear<front)
{
for(i=front; i<max; i++)
printf("%d\t",cqueue[i]);
for(i=0; i<=rear; i++)
printf("%d\t",cqueue[i]);
}
else
for(i=front; i<=rear; i++)
printf("%d\t",cqueue[i]);
}
printf("\n");
}

void main()
{
int ch;
do
{
clrscr();
printf("** Circular Queue **\nEnter your choice:\n");
printf("1)Insert\n2)Delete\n3)Display\n4)Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
	break;
case 2: deletion();
	break;
case 3: display();
	break;
case 4: exit(0);
}
printf("Press 0 to continue\n");
scanf("%d",&ch);
}while(ch==0);
getch();
}


