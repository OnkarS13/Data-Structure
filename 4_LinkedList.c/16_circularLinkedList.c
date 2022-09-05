#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head; // ek pointer banaya aur use head se assign kiya
    do // circular linked list me traversal ke liye do while use karte
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // jab tak ptr head nahi hota tab tak traverse karo...matlab ek pura circle
}

struct Node *insertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // memory allocate kar di
    ptr->data = element;

    struct Node *p = head->next; // pointer p banaya use head ka next banaya
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    
}

int main()
{
    struct Node *head; // nodes banaye
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node)); // memory allocate kar di
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 4;
    head->next = second;
 
    // Link second and third nodes
    second->data = 3;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head; // isse head se assign kiya matlab circular banaya

    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    printf("\n");
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
    
    return 0;
}