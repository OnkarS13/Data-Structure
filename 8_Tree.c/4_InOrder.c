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
    n = (struct node *)malloc(sizeof(struct node)); // memory allocated to n in heap with malloc funct1ion
    n->data = d;
    n->left = NULL;
    n->right = NULL;
    return n; // returning n is important
}

void PreOrder(struct node *root)
{
    if (root != NULL) // Agar root null nahi hoga to hi execute hoga
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node *root)
{
    if (root != NULL) // Agar root null nahi hoga to hi execute hoga
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

void InOrder(struct node *root)
{
    if (root != NULL) // Agar root null nahi hoga to hi execute hoga
    {
        InOrder(root->left);
        InOrder(root->right);
        printf("%d ", root->data);
    }
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

    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2   

    // Linking the nodes with each other
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\nPreOrder :- ");
    PreOrder(p);
    printf(" \n");
    printf("\nPostOrder :- ");
    PostOrder(p);
    printf(" \n");
    printf("\nInOrder :- ");
    InOrder(p);

    return 0;
}

