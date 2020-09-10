#include<stdio.h>
#include<conio.h>
#include<process.h>
struct node
{
int info;
struct node *next;
};
struct node *start=NULL, *ptr, *newptr, *prev, *nex;
int item;
struct node* getnode()
{
struct node *newptr1=(struct node *) malloc( sizeof(struct node));
return newptr1;
}

void creatlist()
{
char ch;
ptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
ptr->info=item;
ptr->next=start;
start=ptr;
printf("To insert more items press 'y'\n");
scanf(" %c",&ch);

while(ch=='y' || ch=='Y')
{
newptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
newptr->info=item;
newptr->next=ptr->next;
ptr->next=newptr;
ptr=ptr->next;
printf("To insert more items press 'y'\n");
scanf(" %c",&ch);
}
}

void display()
{
if(start==NULL)
printf("List is empty\n");
else
{
struct node *ptr1=start;
printf("The linked list is : start");
while(ptr1 !=NULL)
{
printf("-->  %d",ptr1->info);
ptr1=ptr1->next;
}
printf("\n");
}
}

void delbeg()
{
ptr=start;
if(ptr!=NULL)
{
start=start->next;
free(ptr);
}
}

void delend()
{
ptr=start;
if(ptr!=NULL)
{
if(ptr->next==NULL)
{
start=start->next;
free(ptr);
}
else
{
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=ptr->next;
free(ptr);
}
}
}

void delafter()
{
ptr=start;
if(ptr!=NULL)
{
int n;
printf("Enter the item after which deletion to be done:\n");
scanf("%d",&n);
while(ptr->info !=n)
{
ptr=ptr->next;
nex=ptr->next;
}
if(ptr->next==NULL)
printf("There is no node after %d\n",n);
else
{
ptr->next=nex->next;
free(nex);
}
}
}

int main()
{
int ch;
char input;
clrscr();
creatlist();
display();
do
{
printf("1)Deletion at beginning\n2)Deletion at end\n3)Deletion after\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: delbeg(); display(); break;
case 2: delend(); display(); break;
case 3: delafter(); display(); break;
default: printf("Wrong choice\n");
}
printf("For more deletion operation press 'y'\n");
scanf(" %c",&input);
}while(input=='y' || input=='Y');
getch();
return 0;
}
