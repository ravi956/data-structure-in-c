#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *next;
};
struct node *top;

void display()
{
        struct node *ptr;
        if(top==NULL)
        {
                printf("\nStack is empty:\n");
                return;
        }
        else
        {
                ptr=top;
                printf("\nStack elements are:\n");
                while(ptr->next!=NULL)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;   
                }
                printf("%d\t",ptr->info );
		
		}       
}
 
void push()
{
     struct node *temp = (struct  node*)malloc(sizeof(struct node));
     if (temp == NULL)
	 {
	 	printf("\n Out of memory.");
	 	return;
     }
     printf("\n Enter the data : ");
     scanf("%d", &temp->info);
	 temp->next = NULL;     
	 if (top==NULL)
	 top=temp;
	 else 
	 {
	    temp->next = top;
		top = temp;	
	 }	
} 

void pop()
{
	struct node *ptr;
	if (top == NULL)
	{
		printf("\n List is empty.");
		return;
	}
	else 
	{
		ptr = top;
		printf("\n The deleted element is : %d",top->info);
		top = top->next;
		free(ptr);
	}
}

int main()
{
        int choice;
        while(1){
                printf("\n                MENU                             \n");
                printf("\n 1.Display    \n");
                printf("\n 2.Push into stack    \n");
                printf("\n 3.Pop from stack  \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        display();
                                        break;
                        case 2:
                                        push();
                                        break;
                        case 3:
                                        pop();
                                        break;
                        case 4:
                                        exit(0);

                }
        }
        return 0;
}
