#include <stdio.h>
int stack[10];
int maxSize = 9;
int ind = -1;
int num1, num2;

void push(int element) // satck me push kiya
{
    if (ind == maxSize)
    {
        printf("\nStack is Full");
    }
    else
    {
        stack[++ind] = element;
    }
}

int pop() // stack se pop kiya , par ab pop is bar ek int return karta he...aur use temp me store karke return kiya he
{
    int temp;
    if (ind == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        temp = stack[ind]; // temp me store kiya
        stack[ind] = 0;
        ind--;
    }
    return temp;
}

int main()
{
    char a[10];
    int size = 0;

    printf("\nPlease Enter the infix expression :- "); //+1*26
    scanf("%s", a);

    while (a[size] != '\0')
    {
        size++;
    }

    for (int i = size - 1; i >= 0; i--) // ab hame user se infix lene ke bad directly operation kiya to hame bahoot difficult jayega...to isliye ham user se infix lenge aur uske bad hamare convenience ke liye use ulta for loop laga ke uthayenge
    {
        int t = (int)a[i]; // typecasting is done, char to integer

        if (t >= 48 && t <= 57) // asckai values ke through only integers ko allow karna he
        {
            push((a[i] - '0')); // its like string ke end ka jo '\0' hota he use hataye keliye aur use integer me convert karne keliye
        }
        else
        {
            int num1 = pop(); // first element jo pop hoga use num1 me dala
            int num2 = pop(); // Second element jo pop hoga use num2 me dala

            switch (a[i]) // operators ke liye switch case lagaya
            {
            case '+':
                num1 = num2 + num1; // jo bhi output aya use firse next operation keliye stack me push karna padega
                push(num1);
                break;

            case '-':
                num1 = num2 - num1;
                push(num1);
                break;

            case '*':
                num2 = num2 * num1;
                push(num2);
                break;

            case '/':
                num2 = num2 / num1;
                push(num2);
                break;
            }
        }
    }
    // for (int i = 0; i <= ind; i++) //for loop lagake print kiya
    // {
    //     printf("%d ", stack[i]);
    // }

    printf("\n Final output :- %d", pop()); // final output

    return 0;
}