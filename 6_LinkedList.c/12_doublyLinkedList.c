#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void firstInsert(int element)
{
    struct Node *ptr = malloc(sizeof(struct Node *));

    ptr->data = element;
    ptr->next = head;
    ptr->prev = NULL;
}

void LastInsert(int element)
{
    struct Node *ptr = malloc(sizeof(struct Node *));
    ptr->data = element;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;

}

int main()
{

    return 0;
}