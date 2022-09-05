#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left; // struct node ka left banaya
    struct node *right;
};

struct node *createNode(int d)
{
    struct node *n;                                 // Declared the pointer n with data type node
    n = (struct node *)malloc(sizeof(struct node)); // memory allocated to n in heap with malloc function
    n->data = d;
    n->left = NULL;
    n->right = NULL;
    return n; // returning n is important
}

void Inordrdisplay(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    Inordrdisplay(ptr->left);
    printf("%d ", ptr->data);
    Inordrdisplay(ptr->right);
}

int main()
{

    /* Old Method

    // Constructing the root node 
    struct node *p; // yaha pe node data type ka ek pointer banaya
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p1->data = 3;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    // Linking the nodes with each other
    p->left = p1;
    p->right = p2;

    */

    struct node *p; 
    p = createNode(2);

    struct node *p1; 
    p1= createNode(3);

    struct node *p2; 
    p2 = createNode(4);

    // Linking the nodes with each other
    p->left = p1;
    p->right = p2;

    Inordrdisplay(p);

    return 0;
}