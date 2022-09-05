#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int element)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = element;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
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

    struct node *root = createnode(80);
    root->left = createnode(90);
    root->left->left = createnode(30);
    root->left->right = createnode(45);

    root->right = createnode(100);
    root->right->left = createnode(10);
    root->right->right = createnode(20);

    Inordrdisplay(root);

    // struct node *r = createnode(80);

    // r->left->left->left = createnode(90);
    // r->left->left = createnode(10);
    // r->left = createnode(10);
    // r->left->right = createnode(30);
    // r->left->right->right = createnode(70);

    // r->right->right = createnode(60);
    // r->right = createnode(20);

    // Inordrdisplay(r);

    // struct node *ro = createnode(40);

    // ro->left->left->left = createnode(15);
    // ro->left->left->right = createnode(15);
    // ro->left->left = createnode(25);
    // ro->left->right = createnode(35);
    // ro->left = createnode(30);

    // ro->right->right->right = createnode(70);
    // ro->right->right->left = createnode(55);
    // ro->right->right = createnode(60);
    // ro->right->left = createnode(45);
    // ro->right = createnode(50);

    // Inordrdisplay(ro);
    return 0;
}