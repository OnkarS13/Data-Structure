#include <stdio.h>
#include <stdlib.h>

struct Node // Struct Node is data type
{
    int data;
    struct Node *next; // next named pointer is created of struct Node data type
};

void linkedListTraversal(struct Node *ptr) // creted a function with taking input a pointer...ki jo har ek pointer kon access kar sakta he
{
    while (ptr != NULL)
    {
        printf("\nElement is :- %d", ptr->data);
        ptr = ptr->next; // ptr ko update karta rahega
    }
}

int main()
{

    struct Node *head; // here head named pointer is created
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node)); // here head ko struct Node ke data type me typecast kiya aur usi node ki memory ko allocate kiya heap me in linked list
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 11;     // head ke data section me 11 dala aur
    head->next = second; // head ke next matlab address section me second node ka address dala

    // Link second and third nodes
    second->data = 22;
    second->next = third;

    // Link third and fourth nodes
    third->data = 33;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 44;
    fourth->next = NULL; // At the end last element ko NULL se assign kiya

    linkedListTraversal(head); // head pointer is passed to that function

    return 0;
}