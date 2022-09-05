#include <stdio.h>

int stack[10]; // stack having capacity of 10 elements
int maxSize = 9;
int ind = -1; // This is like default syantax...ind matlab index number he

int isFull()
{
    if (ind == maxSize) // Stack is Full   // Agra ind aur maxSize same hue to ye 0 return karega...isse ham 0 bhi kar sakte the ya 1 bhi...par hame sabhi jagah yahi use  karna ne
                        //  kyuki hame push karna hoga to agar stack full raha to add nahiskar sakte isliye ... add na ho is liye hame condition false karni he with the help of 0

    {
        return 0; 
    }
    else
    {
        return 1; // Stack is not full // ind maXSize se equal nahi hoga matlab ...jagah bachi ho stack me...tab ham 1 return karenge jisase push function true hoke execute ho
    }
}

int isEmpty()
{
    if (ind == -1) // Stack is Empty // ind matlab index numbers he..agar ind  = 0 hota matlab usme ek element he...par ye ind  = -1 hoga matlab ....ye pura empty he
    {
        return 0; //  return karega matlab Pop ko vo false kar dega...jisasse pop execute nahi hoga
    }
    else
    {
        return 1; // Stack is not empty....Hame Pop karne ke liye....stack me atleast ek to element hona chahiye to ye check karne ke liye isEmpty ka use karte he aur empty nahi hua to 1 return karega
    }
}

void push(int element) // void matlab ye kuch nhi return karta
{
    if (isFull()) // agar isFull me 1 jayega to iska matlab ki ye function true he isko execute kardo aur push hoga...aur 0 ka matlab false hota he
    {
        stack[++ind] = element; // to yaha pe ++ind kiya because ind ko -1 se 0 increment kiya...bcoz, index 0 se start hota he to stack[o] = element assign hoga
        printf("\nElement is added :- %d", element);
    }
    
    {
        printf("\nStack is Full");
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("\n%d This element is removed ", stack[ind]); // yaha pe suppose stack me 5 elements honge to sabse uper wale ka index number 4 hoga to vohi delete ya remove hoga ... islie hamne ye statement pahale print kiya
                                                             //  Aur bad me remove kiya...remove karne ke bad ek element kam hoga to 4 elements rahenge aur top ke element ka index 3 hoga

        stack[ind] = 0; // this ind is index wise value staring from 0, 1, 2, and so on...ise 0 kiya matlab remove kiya
        ind--;          // Decrement matlab agale time remove karte time uss ind ke niche wala remove hoga..
    }
    else
    {
        printf("\nCan't remove element");
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("\nTop:%d\n", stack[ind]); // Yaha pe ind number sabse top wale ka hi hota he...to vo hi print karna he
        printf("\nElement is Shown ! and it is %d", stack[ind]);
    }
    else
    {
        printf("\nStack is Empty");
    }
}

void printStack()
{
    if (isEmpty())
    {
        printf("\n--------------------------------------------------------------------");
        // for (int i = 0; i <= ind; i++) //For Asceding order
        for (int i = ind; i >= 0; i--) // For Descending order
        {
            printf("\n%d", stack[i]);
        }
        printf("\n--------------------------------------------------------------------");
    }
    else
    {
        printf("Stack is empty");
    }
}

int Menulist()
{
    int cho;
    printf("\n");
    printf("\n0. Exit :-");
    printf("\n1. Insert Element :-");
    printf("\n2. Remove Element :-");
    printf("\n3. Show peek element :-");
    printf("\n4. Print Stack :-");
    printf("\n5. To Exit Program ");
    printf("\nPlease Enter Your Choice:- \n");
    scanf("%d", &cho);
    return cho; // ye jo bhi choice hogi vo Menulist ko return karge ...aur use choice se assign kiya he...aur 0 availabe nhi he to vo function exit kar dega
}

int main()
{

    int choice;
    int p;
    

    printf("\nProgram started !\n");
    while (choice = Menulist() != 0)
    {

        switch (choice)
        {
        case 1:
            printf("Enter the number you want to add :-");
            scanf("%d", &p);
            push(p);

            break;

        case 2:

            pop();
            break;

        case 3:

            peek();
            break;

        case 4:
            printStack();
            break;

        default:
            printf("Please Enter valid Choice !");
            break;
        }
    }

    return 0;
}
