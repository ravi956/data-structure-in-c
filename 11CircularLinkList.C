#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *next;
};
struct node *start=NULL,*ptr,*ptr1,*newptr,*temp;
int item;
struct node * getnode()
{
struct node *newptr1=(struct node*)malloc(sizeof(struct node));
return newptr1;
}
void createlist()
{
char ch;
if(start==NULL)
{
ptr=getnode();
printf("Enter value to insert:\n");
scanf("%d",&item);
ptr->info=item;
ptr->next=ptr;
start=ptr;
}
else
{
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
newptr=getnode();
printf("Enter value to insert:\n");
scanf("%d",&item);
newptr->info=item;
newptr->next=ptr->next;
ptr->next=newptr;
}
printf("For inserting more nodes press 'y':\n");
scanf(" %c",&ch);
if(ch=='y' || ch=='Y')
{
createlist();
}
}

void display()
{
if(start==NULL)
printf("List is empty...\n");
else
{
ptr1=start;
printf("The linked list is: start");
while(ptr1->next!=start)
{
printf("--> %d",ptr1->info);
ptr1=ptr1->next;
}
printf("--> %d-->%d",ptr1->info,ptr1->next->info);
printf("\n");
}
}

void insbeg()
{
newptr=getnode();
printf("Enter the item to insert:\n");
scanf("%d",&item);
newptr->info=item;
newptr->next=start;
ptr1=start;
while(ptr1->next!=start)
{
ptr1=ptr1->next;
}
ptr1->next=newptr;
start=newptr;
display();
}

void insend()
{
newptr=getnode();
printf("Enter the item to insert:\n");
scanf("%d",&item);
newptr->info=item;
ptr1=start;
while(ptr1->next!=start)
{
ptr1=ptr1->next;
}
newptr->next=ptr1->next;
ptr1->next=newptr;
display();
}

void delbeg()
{
temp=start;
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=start->next;
start=start->next;
free(temp);
display();
}

void delend()
{
ptr=start;
temp=start;
while(temp->next!=start)
{
ptr=ptr->next;
temp=ptr->next;
}
ptr->next=temp->next;
free(temp);
display();
}

int main()
{
int choice;
char ch;
createlist();
display();
do
{
printf("*** Circular Linked List ***\n");
printf("1)Insert at beginning\n2)Insert at End\n3)Delete at beginning\n");
printf("4)Delete at end\nEnter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insbeg(); break;
case 2:insend(); break;
case 3:delbeg(); break;
case 4:delend(); break;
default: printf("Invalid Option\n");
}
printf("For more operations press 'y':\n");
scanf(" %c",&ch);
}while(ch=='y' || ch=='Y');
getch();
return 0;
}
