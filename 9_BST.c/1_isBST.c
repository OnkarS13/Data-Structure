#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Setting the left and right children to NULL
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root) // int BST use kiya because ye function 1 or 0 return kar raha he
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        { // agar root->left BST nahi he to return 0 mtlab vo false he..condition ko false kr dega
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // agar prev null nahi he aur prev ka data root ke data se jyada he to vo BSt nahi hota is liye return 0 karkr false
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p); // InOrder he BST hota he
    printf("\n");

    if (isBST(p)) // isBST ko p pass karne pe...agar isBST 1 return karega matlab vo ek BST he nahi to else me jayega
    {
        printf("This is a bst");
    }
    else
    {
        printf("This is not a bst");
    }
    return 0;
}