#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display();
struct node
{
int info;
struct node* prev;
struct node* next;
};
struct node* start=NULL, *ptr,*newptr,*ptr1,*temp;
int item;
struct node* getnode()
{
struct node* newptr1=(struct node*)malloc(sizeof(struct node));
return newptr1;
}
void createlist()
{
char ch;
ptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
ptr->info=item;
ptr->prev=ptr->next=NULL;
start=ptr;
printf("To insert more elements press 'y'\n");
scanf(" %c",&ch);

while(ch=='y' || ch=='Y')
{
newptr=getnode();
printf("Enter the value to insert\n");
scanf("%d",&item);
newptr->info=item;
newptr->prev=ptr;
newptr->next=NULL;
ptr->next=newptr;
ptr=ptr->next;
printf("To insert more items press 'y'\n");
scanf(" %c",&ch);
}
display();
}

void display()
{
struct node* ptr1=start;
printf("The linked list is: start");
while(ptr1!=NULL)
{
printf("<--> %d",ptr1->info);
ptr1=ptr1->next;
}
printf("\n");
}

void insbeg()
{
newptr=getnode();
printf("Enter the element to insert:\n");
scanf("%d",&item);
newptr->info=item;
newptr->prev=NULL;
newptr->next=start;
start=newptr;
display();
}

void insend()
{
newptr=getnode();
printf("Enter the element to insert:\n");
scanf("%d",&item);
newptr->info=item;
newptr->next=NULL;
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=newptr;
newptr->prev=ptr;
display();
}

void insafter()
{
int n;
newptr=getnode();
printf("Enter the item after which insertion to be done:\n");
scanf("%d",&n);
printf("Enter the item to insert:\n");
scanf("%d",&item);
newptr->info=item;
ptr=start;
while(ptr->info!=n)
{
ptr=ptr->next;
}
ptr1=ptr->next;
newptr->prev=ptr;
newptr->next=ptr->next;
ptr1->prev=newptr;
ptr->next=newptr;
display();
}

void delbeg()
{
temp=getnode();
temp=start;
start=start->next;
printf("%d is deleted...\n",temp->info);
free(temp);
display();
}

void delend()
{
temp=getnode();
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
printf("%d is deleted...\n",temp->info);
(temp->prev)->next=NULL;
free(temp);
display();
}

void delafter()
{
temp=getnode();
temp=start;
printf("Enter the item to be deleted:\n");
scanf("%d",&item);
while(temp->info !=item)
{
temp=temp->next;
}
(temp->prev)->next=temp->next;
(temp->next)->prev=temp->prev;
printf("%d is deleted...\n",item);
free(temp);
display();
}

int main()
{
int choice;
char ch;
createlist();
do
{
printf("***Doubly Linked List***\n");
printf("1)Insert at begin.\n2)Insert at End\n3)Insert after\n");
printf("4)Delete at begin.\n5)Delete at End\n6)Delete element\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insbeg(); break;
case 2:insend(); break;
case 3:insafter(); break;
case 4:delbeg(); break;
case 5:delend(); break;
case 6:delafter(); break;
default: printf("Invalid Option\n");
}
printf("For more operations press 'y':\n");
scanf(" %c",&ch);
}while(ch=='y' || ch=='Y');
getch();
return 0;
}
