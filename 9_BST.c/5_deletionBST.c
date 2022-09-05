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

struct node *search(struct node *root, int key) // argument me ek pointer lega aur ek integer lega
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key); // isme koi recursive condition eg. while loop nahi laga he is liye isse return me search me dala he
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *searchIter(struct node *root, int key) // argument me ek pointer lega aur ek integer lega
{
    while (root != NULL) // agar root NULL nahi hoga tab hi condition me ghusega
                         // while loop use kar rahe he is liye function me function ko call karne ki jaroorat nahi he
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left; // yaha pe root ka update kiya he matlab root ko left pe shift kiya
        }
        else
        {
            root = root->right; // ise update kar ke right pe shift kiya
        }
    }
    return NULL; // otherwise NULL return karega
}

void insert(struct node *root, int key) // yaha pe void use kiya because ye kuch return nahi kar raha ... ye ek pointer aur integer lega
{
    struct node *prev = NULL; // ek prev nam ka pointer banaya ar usse NULL kar diya

    while (root != NULL) // while loop me ghusne ke bad ek condition me to key aur root->data jayega
    {
        prev = root; // root ko liya aur use prev se assign kar diya
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return; // yaha pe return kiya because jo element already present he usse add nahi kar sakte so is function se exit hona padega
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    } // while loop se bahar ane ke bad ek to return hoga ...to function vahi khatam...nahi to left pe jaga hogi yato right pe
      // isliye node pointer banake use add karna he

    struct node *new;      // new nam ka pointer banaya
    new = createNode(key); // jis key ko hame node add karna he use node pointer ke form me lagana padega to uss key ko createNode me pass karke use pointer banayenge...aur use new me store kiya

    if (key < prev->data)
    { // prev matlab ye root he ....upar root ko prev me store kiya tha //key ko hame add karna he
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node *inOrderPrecessor(struct node *root) // inOrderPrecessor ye hamesha left subTree ka sabse right most child hota he //ye ek pointer root return karega , ek root leke
{
    root = root->left; // left subtree me enter kiya
    while (root->right != NULL)
    {
        root = root->right; // right most child is found
    }
    return root; // returned that root
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *prev; // prev nam ka pointer banaya

    // If root is NULL
    if (root == NULL)
    {
        return NULL; // kuch bhi nahi to NULL return kar do
    }
    // For leaf node case
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL; // root ko free karne ke bad use pointer ko NULL kar do
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when node is found
    else
    {
        prev = inOrderPrecessor(root); // inOrderPreccseor hamesha left me hota he // root ka inOrderPrecessor nikala with the help of that function bvy passing root to it aur use prev me store kiya
        root->data = prev->data;       // usi prev ke data ko root ke data se assign kiya
        root->left = deleteNode(root->left, prev->data);
    }
    return root; // deleteNode ek root ko return karta he, to jo element delete hua use delete kiya
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

    inOrder(p);
    printf("\n");
    deleteNode(p, 5);
    printf("inOrder after deleting Node");
    printf("\n");
    inOrder(p);

    return 0;
}

