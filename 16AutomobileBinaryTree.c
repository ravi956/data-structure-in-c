#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int year;
    char type[20];
    char company[20];
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

void insert();
struct Node *deletion(struct Node *, int);
struct Node *minValueNode(struct Node *);
void preorder_traversal(struct Node *);
void inorder_traversal(struct Node *);
void postorder_traversal(struct Node *);

int main()
{
    int item, choice;
    do
    {
        printf("Enter a choice: \n 1) Insertion \n 2) Deletion \n 3) Display \n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            insert();
        }
        else if(choice == 2)
        {
            int del_year;
            printf("Enter manufacture year of vehicle to be deleted: \n");
            scanf("%d", &del_year);
            deletion(root, del_year);
        }
        else
        {
            int display_choice;
            printf("Enter type of traversal: \n 1) Pre-order \n 2) In-order \n 3) Post-order \n");
            scanf("%d", &display_choice);
            printf("--------------------------- \n");
            if(display_choice == 1)
                preorder_traversal(root);
            else if(display_choice == 2)
                inorder_traversal(root);
            else
                postorder_traversal(root);
        }
        printf("Want to perform same operation again?(Press 0 for YES)\n");
        scanf("%d", &choice);
    } while(choice == 0);
    return 0;
}

void insert()
{
    struct Node *new_node, *parentptr, *nodeptr;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node == NULL)
        printf("Overflow!");
    else
    {
        int year;
        char company[20], type[20];
        printf("Enter vehicle type: \n");
        scanf("%s", type);
        printf("Enter company name: \n");
        scanf("%s", company);
        printf("Enter manufacture year: \n");
        scanf("%d", &year);
        memcpy(new_node -> type, type, sizeof(new_node -> type));
        memcpy(new_node -> company, company, sizeof(new_node -> company));
        new_node -> year = year;
        new_node -> left = NULL;
        new_node -> right = NULL;
        if(root == NULL)
        {
            root = new_node;
            root -> left = NULL;
            root -> right = NULL;
        }
        else
        {
            parentptr = NULL;
            nodeptr = root;
            while(nodeptr != NULL)
            {
                parentptr = nodeptr;
                if(year < nodeptr -> year)
                    nodeptr = nodeptr -> left;
                else
                    nodeptr = nodeptr -> right;
            }
            if(year < parentptr -> year)
                parentptr -> left = new_node;
            else
                parentptr -> right = new_node;
        }
        printf("Node inserted... \n");
    }
}
struct Node *minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deletion(struct Node *temp, int del_year)
{
    if (temp == NULL) return root;
    if (del_year < root->year)
        temp->left = deletion(temp->left, del_year);
    else if (del_year > root->year)
        temp->right = deletion(temp->right, del_year);
    else
    {
        if (temp->left == NULL)
        {
            struct Node *ptr = temp->right;
            free(temp);
            return ptr;
        }
        else if (temp->right == NULL)
        {
            struct Node *ptr = temp->left;
            free(temp);
            return ptr;
        }
        struct Node* ptr = minValueNode(temp->right);
        temp->year = ptr -> year;
        memcpy(temp -> type, ptr -> type, sizeof(temp -> type));
        memcpy(temp -> company, ptr -> company, sizeof(temp -> company));
        temp->right = deletion(temp->right, ptr->year);
    }
    return temp;
}

void preorder_traversal(struct Node *node)
{
    if(node != NULL)
    {
        printf("Vehicle Type: %s \n", node -> type);
        printf("Company: %s \n", node -> company);
        printf("Year: %d \n", node -> year);
        printf("----------------------------\n");
        preorder_traversal(node -> left);
        preorder_traversal(node -> right);
    }
}

void inorder_traversal(struct Node *node)
{
    if(node != NULL)
    {
        inorder_traversal(node -> left);
        printf("Vehicle Type: %s \n", node -> type);
        printf("Company: %s \n", node -> company);
        printf("Year: %d \n", node -> year);
        printf("----------------------------\n");
        inorder_traversal(node -> right);
    }
}

void postorder_traversal(struct Node* node)
{
     if (node != NULL)
     {
         postorder_traversal(node -> left);
         postorder_traversal(node -> right);
         printf("Vehicle Type: %s \n", node -> type);
         printf("Company: %s \n", node -> company);
         printf("Year: %d \n", node -> year);
         printf("----------------------------\n");
     }
}
