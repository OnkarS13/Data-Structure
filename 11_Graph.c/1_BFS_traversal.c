#include <stdio.h>
#include <stdlib.h>

// Sara code queue ka use kiya he .. Breadth first traversal me Queue use kiya jata he

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{ // isEmpty namk ka ek function banaya
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 1; //1 se visit karna start kiya
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = {// yaha pe links ko jod diya gaya he...graphical representation
                   {0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    printf("%d ", i);
    visited[i] = 1; // 1 ka meaning he ki vo visited he. 0 matlab non visited  
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q)) // jab tak empty nahi hota tab tak loop chalaoo
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)  // iska matlab ye he ki a[][] ye agar 1 hoga to matlab do node me edge exist karta he aur j= [] = 0 he matlab vo visited nahi hoga to vo add karna he... visited nahi hoga tohi condition me ghusega
            {
                printf("%d ", j); //to j ko print karo
                visited[j] = 1; // aur jth ke position pe 1 likhdo ....use visited ke list me add karo...matlab ki vo visit ho chuka he
                enqueue(&q, j); // aur q me j ko enqueue karo
            }
        }
    }
    return 0;
}
