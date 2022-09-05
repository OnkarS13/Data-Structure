#include <stdio.h>

int element;
int queue[10];
int maxsize = 9;
int front = -1; // ise front aur rear ko globally -1 karna jaroori he because at the start ye empty hi hota he aur empty matlab front = -1, rear = -1
int rear = -1;
int t; // global ka int t aur, local int t alag hota he
       // global t initialize kiya to vo pure program me overite hota rahate he .....agar global me initilize kiya to function ko value return karni nahi padti...aur agar local me kiya to vahase value function ko return karni padati he nahi to agar local me hi initialize kiya to ussi function me print karna padega

void printQueue()
{
    for (int i = 0; i <= maxsize; i++)
    {
        printf("%d ", queue[i]);
    }
}
void enqueue() // enqueue me front constant rahata he aur rear (pichese )update hota rahata he
{
    if (rear == maxsize) // condition for queue is full
    {
        printf("\nQueue is Full");
        return;
    }
    else if (front == -1 && rear == -1) // condition for when queue is empty and you want to add first element
    {
        front = 0; // it means that ek hi element he jiski dono front and rear value ek hi hogi
        rear = 0;  // it means that ek hi element he jiski dono front and rear value ek hi hogi
    }
    else
    {
        rear++; // agar koi element alredy he to...rear ++ karke rear me add kar do
                // queue[rear] = element;
    }

    int e;
    printf("\nPlease Enter the number you want to Enqueue :- ");
    scanf("%d", &e);
    queue[rear] = e; // aur queue me element add kiya
    printQueue();
    printf("\n%d is added to queue", e);
}

void dequeue() // deenqueue me rear constant rahata he aur front (agese)update hota rahata he matlab agese queue se value mikalti rahati he
{
    if (front == -1 && rear == -1) // queue is empty condition
    {
        printf("\nQueue is Empty !");
    }
    else if (front == rear) // agar ek hi element present hoga to...use mikal do
    {
        front = -1;       // setting it to -1 means stack is empty karna
        rear = -1;        // setting it to -1 means stack is empty karna
        queue[front] = 0; // queue se element ko 0 assign kiya matlab nikal diya
        printQueue();
    }
    else
    {
        queue[front] = 0; // agar remove karna ho to... queue usse first 0 se assign karo aur... front ko update kar ke use kam kardo
        front++;
        printQueue();
    }
}

void show()
{
    if (front == -1 && rear == -1) // agar empty raha to empty show kar do
    {
        printf("\nQueue is Empty !");
        printf("\n");
        for (int i = 0; i <= maxsize; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        printf("\nQueue :- ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void t_size(int f, int r)
{
    t = r - f + 1;
}

// agar mene function se value return liya to case :-

// int t_size(int f, int r)
// {
//     int t;
//     t = r - f + 1;
//     return t; //muze return karna padega
// }

// Agar return nhi karna to

// void t_size(int f, int r)
// {
//     int t;
//     t = r - f + 1;
//     printf("%d ", t); // usi function me print karna padega agar return nhi karna to2
// }

int menuList()
{
    int cho;
    printf("\n");

    printf("\n0. Exit :- ");
    printf("\n1. To Enqueue :- ");
    printf("\n2. To Dequeue :- ");
    printf("\n3. To show Queue :- ");
    printf("\n4. To show Size :- ");
    printf("\n");
    printf("\nPlease Enter your choice :- ");
    scanf("%d", &cho);
    return cho;
}

int main()
{
    int choice;

    int e;
    printf("\nQueue program started :- ");

    while ((choice = menuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            printf("\nElement is removed! ");
            dequeue();
            break;

        case 3:
            printf("\nElements :- ");
            show();
            break;

        case 4:

            t_size(front, rear);
            printf("\nSize :- ");
            printf("%d ", t);
            break;

        default:
            printf("Please Enter valid Choice !");
            break;
        }
    }

    return 0;
}