#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *next;
};
struct node *front, *rear;

void display()
{
        struct node *ptr;
        if(front==NULL)
        {
                printf("\nQueue is empty:\n");
                return;
        }
        else
        {
                ptr=front;
                printf("\nQueue elements are:\n");
                while(ptr!=rear)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;   
                }
                printf("%d\t",ptr->info );
		
		}       
}
 
void insert_queue()
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
	 if (front==NULL)
	 {
	   front=temp;
	   rear=temp;
     } 
	 else 
	 {
	    rear->next = temp ;
		rear = temp;	
	 }	
} 

void delete_queue()
{
	struct node *ptr;
	if (front == NULL)
	{
		printf("\n Queue is empty.");
		return;
	}
	else 
	{
		ptr = front;
		printf("\n The deleted element is : %d",front->info);
		front = front->next;
		free(ptr);
	}
}

int main()
{
        int choice;
        while(1){
                printf("\n                MENU                             \n");
                printf("\n 1.Display    \n");
                printf("\n 2.Insert into queue    \n");
                printf("\n 3.Delete from queue  \n");
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
                                        insert_queue();
                                        break;
                        case 3:
                                        delete_queue();
                                        break;
                        case 4:
                                        exit(0);

                }
        }
        return 0;
}
