#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void finsert(int element)
{
    struct Node *ptr = malloc(sizeof(struct Node *)); 
    ptr->data = element;
    ptr->next = head;
    head = ptr;
}

void fdelete(void)
{
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("\nUnderFlow !");
    }
    else
    {
        head = ptr->next;
        free(ptr);
    }
}

void length(void)
{
    struct Node *ptr = head;
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    printf("\nThe number of nodes :- %d ", cnt);
}

void display(void)
{
    struct Node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("\n%d ", ptr->data);
        printf(" %d", ptr->next);
        ptr = ptr->next; // ptr update karte raho
    }
}

int Menulist(void)
{
    int cho;
    printf("\n");
    printf("\n0. Exit :-");
    printf("\n1. First Insert :-");
    printf("\n2. First Delete :-");
    printf("\n3. length :-");
    printf("\n4. display :-");

    printf("\nPlease Enter Your Choice:- \n");
    scanf("%d", &cho);
    return cho; // ye jo bhi choice hogi vo Menulist ko return karge ...aur use choice se assign kiya he...aur 0 availabe nhi he to vo function exit kar dega
}

int main()
{
    int choice;
    int p;

    printf("\nProgram Started :- ");
    while ((choice = Menulist()) != 0)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to add :-");
            scanf("%d", &p);
            finsert(p);
            break;

        case 2:
            fdelete();
            break;

        case 3:
            length();
            break;

        case 4:
            display();
            break;

        default:
            printf("\nPlease Enter valid choice !");
            break;
        }
    }

    return 0;
}