#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void Finsert(int element)
{
    struct Node *ptr = malloc(sizeof(struct Node *));
    ptr->data = element;
    if (head == NULL) // zero elements are present aur ek hi element add karna pad raha he
    {   
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct Node * trav = head;
        if(trav->next != head)
        {
            trav = trav->next;
        }
        struct Node * sptr = head;
        head = ptr;
        ptr->next = sptr;
        trav->next = head;
    }
}

void fDelete(void)
{
}

void lInsert(int element)
{
    struct Node *ptr = malloc(sizeof(struct Node *));

    ptr->data = element;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct Node * trav = head;
        if(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = ptr;
        ptr->next = head;
        printf("\nElement is addes at last");
    }
}

void lDelete(void)
{
}

void Display(void)
{
    struct Node *ptr = head; // ek pointer banaya aur use head se assign kiya
    do                       // circular linked list me traversal ke liye do while use karte
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // jab tak ptr head nahi hota tab tak traverse karo...matlab ek pura circle
}

int Menulist(void)
{
    int cho;
    printf("\n");
    printf("\n0. Exit :-");
    printf("\n1. First Insert :-");
    printf("\n2. First Delete :-");
    printf("\n3. Last Insert :-");
    printf("\n4. Last Delete :-");
    printf("\n5. Display :-");

    printf("\nPlease Enter Your Choice:- ");
    scanf("%d", &cho);
    return cho; // ye jo bhi choice hogi vo Menulist ko return karge ...aur use choice se assign kiya he...aur 0 availabe nhi he to vo function exit kar dega
}

int main()
{
    int choice;
    int p;
    int q;

    printf("\nProgram Started of Queue Using Linked LIst:- ");
    while ((choice = Menulist()) != 0)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to add at first:-");
            scanf("%d", &p);
            Finsert(p);
            break;

        case 2:
            fDelete();
            break;

        case 3:
            printf("Enter the number you want to add at Last:-");
            scanf("%d", &q);
            lInsert(q);
            break;

        case 4:
            //lDelete();
            break;
            
        case 5:
            Display();
            break;

        default:
            printf("\nPlease Enter valid choice !");
            break;
        }
    }
    return 0;
}