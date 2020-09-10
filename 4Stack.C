#include<stdio.h>
#include<conio.h>
#define max 10

void display();
void push();
void pop();


int stack[max];
int top=-1,i,element;

void menu()
{
int ch;
printf("Enter from the following choice:\n1)Display\n2)Push\n3)Pop\n4)Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:display();
	break;
case 2:push();
	break;
case 3:pop();
	break;
case 4:break;
}
}
void display()
{
if(top==-1)
{
printf("There are no elements in the stack.\n");
menu();
}
else
{
printf("Elements in the stack:\n");
for(i=0; i<=top; i++)
printf("%d\t",stack[i]);
printf("\n");
menu();
}
}

void push()
{
if(top==max-1)
{
printf("Overflow Condition.\n");
menu();
}
else
{
printf("Enter the element to be pushed in:\n");
scanf("%d",&element);
top++;
stack[top]=element;
menu();
}
}

void pop()
{
if(top==-1)
{
printf("Underflow Condition.\n");
menu();
}
else
{
printf("Popped out element is %d\n",stack[top]);
top--;
menu();
}
}

void main()
{
clrscr();
menu();
getch();
}