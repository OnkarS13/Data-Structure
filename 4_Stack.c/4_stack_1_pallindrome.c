#include <stdio.h>

char Stack[10];
int maxSize = 9;
int ind = -1; // ind -1 se start ho raha he

void push(char element) // yaha void matlab ye kuch return nahi kar raha
{
    if (ind == maxSize) // agar ind aur maxSize same huye to iska matlab stack full hua he
    {
        printf("Stack is Full");
    }
    else
    {
        Stack[++ind] = element; // otherwise stack ham stack me push kar sakte he
                                // ++ind kiya aur element ko stack me dal diya
    }
}

char pop() // Here it is returning char in stack...and takes no argument
{
    char ret;      // char ret banaya aur pop function ko ret return karega
    if (ind == -1) // agar ind = -1 matlab ki last element he hi nahi he to pop nahi hoga
    {
        printf("Stack is Underflow");
    }
    else
    {
        ret = Stack[ind]; // otherwise pop hoga, aur stack ke sabse upar jo hoga usse ret ko dega aur ind-- karega...matlab ret return karega
        ind--;
    }
    return ret;
}

int main()
{
    char a[10]; // eg. a = nayan = ['\n', '\a', '\y', '\a', '\n', '\0'] har ek ke last me \0 hota hi he
    int cnt = 0;

    printf("\nEnter the word :- ");
    scanf("%s", a); // string ko & use nahi karte

    for (int i = 0; a[i] != '\0'; i++) // ye for loop nayan ke har ek charcter ko scan karega ki jab tak \0 nahi ata tabtak scan karke push karta rahega
    {
        push(a[i]); // aur har ek elemnent ko push karega
    }

    int i;
    for (i = 0; a[i] != '\0'; i++) //  ye for loop nayan ke har ek charcter ko scan karega ki jab tak \0 nahi ata tabtak pop karta rahega
    {
        if (a[i] == pop()) //?
        {
            cnt++;
        }
    }

    printf("\n%d \n%d", i, cnt); // i matlab kitne no. of charcters he..aur cnt matlab kitne charcter pop hue

    if (cnt == i) // iska matlab kitne cnt(count) pop huye, aur kitne elements the.. agar dono hi process huye he.. agar dono same nikale to pallindrome hota he
    {
        printf("It is Pallindrom");
    }
    else
    {
        printf("It is not Pallindrome");
    }
    return 0;
}