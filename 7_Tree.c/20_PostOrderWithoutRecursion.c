#include <stdio.h>
#include <stdlib.h>

// This is like default syantax...ind matlab index number he

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *stack[10]; // stack having capacity of 10 elements
int maxSize = 9;
int ind = -1;

struct node *output[10];
int indOut = -1;

struct node *createnode(int element)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = element;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void push(struct node *element) // void matlab ye kuch nhi return karta
{
    stack[++ind] = element; // to yaha pe ++ind kiya because ind ko -1 se 0 increment kiya...bcoz, index 0 se start hota he to stack[o] = element assign hoga
                            // printf("\nElement is added :- %d", element);
}

struct node *pop()
{
    //  Aur bad me remove kiya...remove karne ke bad ek element kam hoga to 4 elements rahenge aur top ke element ka index 3 hoga
    struct node *n = stack[ind];
    stack[ind] = 0; // this ind is index wise value staring from 0, 1, 2, and so on...ise 0 kiya matlab remove kiya
    ind--;
    return n; // Decrement matlab agale time remove karte time uss ind ke niche wala remove hoga..
}

void PostOrder(struct node *root)
{
    struct node *top = root;
    push(root);
    while (ind > -1)
    {
        top = pop();
        output[++indOut] = top;

        if (top->left)
        {
            push(top->left);
        }
        if (top->right)
        {
            push(top->right);
        }
    }
    int i = indOut;
    while (i >= 0)
    {
        printf("%d ", output[i]->data);
        i--;
    }
}

int main()
{

    struct node *root = createnode(80);
    root->left = createnode(90);
    root->left->left = createnode(30);
    root->left->right = createnode(45);

    root->right = createnode(100);
    root->right->left = createnode(10);
    root->right->right = createnode(20);

    // struct node *ptr = root;
    PostOrder(root);

    // push(root);
    // if (root == NULL)
    // {
    //     //return 0;
    // }
    // //printf("nnn");
    // while (ind!=-1)
    // {
    //     //printf("nnn");
    //     ptr = pop();
    //     printf("%d  ", ptr->data);
    //     if (ptr->right)
    //     {
    //         push(ptr->right);
    //     }
    //     if (ptr->left)
    //     {
    //         push(ptr->left);
    //     }
    // }

    return 0;
}