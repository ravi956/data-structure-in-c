#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
struct node
{
int info;
struct node *next;
};
struct node *start=NULL, *ptr, *newptr;
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
struct node *ptr1=start;
printf("The linked list is : start");
while(ptr1 !=NULL)
{
printf("-->  %d",ptr1->info);
ptr1=ptr1->next;
}
printf("\n");
}

void insbeg()
{
ptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
ptr->info=item;
ptr->next=start;
start=ptr;
}

void insend()
{
newptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
newptr->info=item;
ptr=start;
while(ptr->next !=NULL)
{
ptr=ptr->next;
}
newptr->next=ptr->next;
ptr->next=newptr;
}

void insafter()
{
int n;
newptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
newptr->info=item;
printf("Enter the item after which the insertion to be done\n");
scanf("%d",&n);
ptr=start;
while(ptr->info !=n)
{
ptr=ptr->next;
}
newptr->next=ptr->next;
ptr->next=newptr;
}

int main()
{
int ch;
char input;
creatlist();
display();
do
{
printf("1)Insertion at beginning\n2)Insertion at end\n3)Insertion after\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insbeg(); display(); break;
case 2: insend(); display(); break;
case 3: insafter(); display(); break;
}
printf("For more insert operation press 'y'\n");
scanf(" %c",&input);
}while(input=='y' || input=='Y');
getch();
return 0;
}
