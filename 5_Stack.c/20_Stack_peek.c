#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top; // top matlab ye index number he like ind in previous examples
    int *arr;
};

int isEmpty(struct Stack *ptr) // It takes a pointer of data type struct Stack and returns int
{
    if (ptr->top == -1)
    {
        return 0; // stack empty he to pop nahi kar sakte
    }
    else
    {
        return 1;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size - 1)) // it means full ho gaya he
    {
        return 0; // aur ab push nahi kar sakte// means push function chalna nahi chahiye
    }
    else
    {
        return 1;
    }
}

void push(struct Stack *ptr, int val) // return kuch nahi karega ....ek pointer aur ek value lega
{
    if (isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val; // ptr ke arrray me ptr ke top ki value ko val se assign kiya
    }
    else
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
}

int pop(struct Stack *ptr) // ek int return karega aur ek pointer lega
{
    if (isEmpty(ptr))
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    else
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
}

void printStack(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {

        // for (int i = 0; i <= ind; i++) //For Asceding order
        for (int i = ptr->top; i >= 0; i--) // For Descending order it is starting from top index number
        {
            printf("\n%d", ptr->arr[i]); // ptr ke arr ke values print karega
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int peek(struct Stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack)); // sp ko memroy allocate kar ke de di
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int)); // array ko int data type ke sp ke size ke jitne memory allocate kr ke de di
    printf("Stack has been created successfully\n");

    printf("-----------------------------------------------------\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    printf("-----------------------------------------------------\n");

    push(sp, 1); // sp matlab ye push ki huyi value sp me jayegi jaha pe memory allocate karva ke di gayi thi
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values
    // push(sp, 46); // Stack Overflow since the size of the stack is 10

    // for (int i = 0; i <= ind; i++) //For Asceding order
    // for (int i = sp->top; i >= 0; i--) // For Descending order
    // {
    //     printf("%d\n", sp->arr[i]);
    // }

    printStack(sp);

    printf("-----------------------------------------------------\n");

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("-----------------------------------------------------\n");

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!

    printf("-----------------------------------------------------\n");

    // for (int i = sp->top; i >= 0; i--) // For Descending order
    // {
    //     printf("%d\n", sp->arr[i]);
    // }
    printStack(sp);
    printf("-----------------------------------------------------\n");

    printf("%d\n", sp->arr[sp->top]); // it will print top most element present in that array at that moment

    printf("-----------------------------------------------------\n");

    printf("%d\n", sp->top); // it is printing the index value
    
    printf("-----------------------------------------------------\n");

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

    return 0;
}