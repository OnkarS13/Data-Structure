#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void Preordrdisplay(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("%d ", ptr->data);
    Preordrdisplay(ptr->left);
    Preordrdisplay(ptr->right);
}

struct node *insert(struct node *root, int n)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node *));
        temp->right = NULL;
        temp->left = NULL;
        temp->data = n;
        return temp;
    }
    else if (n < root->data)
    {
        root->left = insert(root->left, n);
    }
    else if (n > root->data)
    {
        root->right = insert(root->right, n);
    }

    return root;
}

struct node *max(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    printf("\nGreatest Number is %d", root->data);
    return root;

}

struct node* min(struct node *root)
{
    struct node* ptr1;
    while (root->left != NULL)
    {
        ptr1=root;
        root = root->left;
    }
    printf("\nLowest Number is %d", root->data);
    return ptr1;
}

struct node *delete (struct node *root, int n)
{
    if (root == NULL)
    {
        printf("\nUnderflow !");
        // return;
    }
    else if (n < root->data)
    {
        root->left = delete (root->left, n);
    }
    else if (n > root->data)
    {
        root->right = delete (root->right, n);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            temp->data = root->data;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            temp->data = root->data;
            free(temp);
            
        }
        else
        {
            struct node *temp;
            temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, root->data);
        }
    }
    return root;
}

int Menulist()
{
    int cho;
    printf("\n");
    printf("\n0. Exit :-");
    printf("\n1. Insert Element :-");
    printf("\n2. Maximum Element :-");
    printf("\n3. Minimum element :-");
    printf("\n4. Delete element :-");
    printf("\nPlease Enter Your Choice:- \n");
    scanf("%d", &cho);
    return cho;
}

int main()
{
    struct node *root = NULL;

    // root = insert(root, 30);
    // root = insert(root, 15);
    // root = insert(root, 45);
    // root = insert(root, 18);
    // root = insert(root, 12);
    // Preordrdisplay(root);
    // max(root);
    // min(root);

    int choice;
    int p;
    int d;

    printf("\nProgram started !\n");
    choice = Menulist();
    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            printf("Enter the number you want to add :-");
            scanf("%d", &p);
            root = insert(root, p);
            printf("\n Here is the list!");
            printf("\n");
            Preordrdisplay(root);

            break;

        case 2:
            max(root);
            break;

        case 3:

            min(root);
            break;

        case 4:
            printf("Enter the number you want to Delete :-");
            scanf("%d", &d);
            delete(root, d);
            Preordrdisplay(root);
            break;

        default:
            printf("Please Enter valid Choice !");
            break;
        }
        choice = Menulist();
    }

    return 0;
}