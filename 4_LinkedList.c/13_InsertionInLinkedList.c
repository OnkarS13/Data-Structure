#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data; // for data section
    struct Node * next; // for address section
};

void linkedListTraversal(struct Node *ptr) // traversal function ko ham pointer provide karte he...to argument me head jayega to vo jabtak null nahi hota tab tak chalega matlab start se leke end tak traverse hoga
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){ // ye struct node * ke data type ka ptr or head return karega
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head; // ptr ke next me head dal diya
    // head = ptr; //or return ptr is same
    return ptr; 
}

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){ 
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head; // p nam ka pointer banaya aur use head se assign kiya to ab pointer p head se matlab start se start hoga aur use jab tak index nahi ata tab tak age badhaya jayega
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("\nLinked list before insertion\n");// 7 11 41 66
    linkedListTraversal(head); // old value vale head ko run kiya 

    printf("\nLinked list after First insertion\n");
    head = insertAtFirst(head, 56); // 56 7 11 41 66
    linkedListTraversal(head);
    
    printf("\nLinked list after insertion at index\n");
    head = insertAtIndex(head, 66, 1); // 56 66 7 11 41 66
    linkedListTraversal(head);

    printf("\nLinked list after insertion at end\n");
    head = insertAtEnd(head, 99); // 56 66 7 11 41 66 99
    linkedListTraversal(head);

    printf("\nLinked list after insertion at afternode\n");
    head = insertAfterNode(head, third, 45);
    linkedListTraversal(head);
    

    
    return 0;
}