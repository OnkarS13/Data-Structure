#include <stdio.h>
#include <stdlib.h>

int cnt = 0; // created for counting

struct Student
{
    int rollNo;

    struct Student *next; // yaha struct student ek data type he aur next nam ka us type ka pointer banaya he
};

struct Student *head = NULL; // first head nam ka ek pointer banake use null kar diya

void firstinsert(int roll)
{
    struct Student *ptr = malloc(sizeof(struct Student *)); // ptr nam ka pointer banake withthe help of malloc (struct Student *) ke size ka memory heap me allocate kiya

    ptr->rollNo = roll; // ptr matlab full node ka address //pointer ptr ek full node jaise he...usme value aur next wale node ka addrress hota he...to usme value me rollNo ko element se assign kiya he
    ptr->next = head;   // aur nextmatlab next wale ka address usi node me store karna he aur use head ke address se assign kar do
    head = ptr;         // aur usi ptr ko head bana do...means recent wala head rahega aur first wala ke adress null rahega
}

void lastInsert(int rollno)
{
    struct Student *ptr = malloc(sizeof(struct Student *)); // koi bhio node insert kaene ke liye pehale heap me memory book karna padata he
    ptr->rollNo = rollno;
    struct Student *p = head; // created a p pointer and assigned to head aur vo last element tak traverse karega

    while (p->next != NULL) // jab tak p->next null nahi at6a tak tak
    {                           
        p = p->next; // p is updated
    }
    p->next = ptr;    // p ke next me ptr ka address
    ptr->next = NULL; // aur ptr ke next me null dal do
}

void insertAtIndex(int rolln, int index) // created a function
{
    struct Student *ptr = malloc(sizeof(struct Student *)); // heap me dynamic memory allocate kar ke dedi
    struct Student *p = head;                               // p pointer banake use head se assign kiya
    int i = 0;

    while (i != (index - 1))
    {
        p = p->next; // updated p
        i++;         // incremented
    }
    ptr->rollNo = rolln; // value data assign kiya
    ptr->next = p->next;
    p->next = ptr;
}

void fDelete(void)
{
    struct Student *ptr = head; // ptr nam ka ek struct student ka ek data type banaya....aur head se use assign kiya

    if (ptr == NULL) // agar pointer empty rahega to underflow
    {
        printf("\nUnderFlow !");
    }
    else
    {
        printf("\n Element %d successfully deleted !\n", head->rollNo);
        // printf("\n Element %d successfully deleted !\n", ptr->rollNo); // both will print same because ptr he head he
        head = ptr->next; // matlab ptr ko jo head assign kiya tha usme jo addrees store tha matlab vo uske pahale wale node ka address tha use head se assign
        free(ptr);        // aur jo delete karna tha use free kiya
    }
}

void lastDelete(void)
{
    struct Student *ptr = head; // ptr nam ka ek struct student ka ek data type banaya....aur head se use assign kiya
    struct Student *p = head;   // ptr nam ka ek struct student ka ek data type banaya....aur head se use assign kiya

    if (ptr == NULL) // agar pointer empty rahega to underflow
    {
        printf("\nUnderFlow !");
    }
    else
    {
        while (ptr->next != NULL) // start se leke end tak traverse karne ke liye banaya he for finding last element
        {
            ptr = ptr->next;
        }

        while (p->next != ptr) // second last ko find karne keliye...or traverse karne ke liye
        {
            p = p->next;
        }

        printf("\n Element %d successfully deleted !\n", ptr->rollNo);
        free(ptr);
        p->next = NULL;
    }
}

void deleteAtIndex(int index)
{
    struct Student *ptr = head; // ptr nam ka ek struct student ka ek data type banaya....aur head se use assign kiya
    struct Student *p = head;   // ptr nam ka ek struct student ka ek data type banaya....aur head se use assign kiya
    int i = 0;

    if (ptr == NULL) // agar pointer empty rahega to underflow
    {
        printf("\nUnderFlow !");
    }
    else
    {
        while (i != (index)) // traversing upto that index - 1 to which is going to be deleted
        {
            ptr = ptr->next;
            i++;
        }

        while (p->next != ptr) // ptr se pichalewala find karne ke liye
        {
            p = p->next;
        }

        printf("\n Element %d successfully deleted !\n", ptr->rollNo);
        p->next = ptr->next;
        free(ptr);
    }
}

void length(void)
{
    struct Student *ptr = head;
    while (ptr != NULL) // jab tak ptr me null nahi ata tab tak traverse karo
    {
        cnt++;
        ptr = ptr->next;
    }
    printf("\nThe number of nodes :- %d ", cnt);
}

void display()
{
    struct Student *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf(" %d", ptr->rollNo);
        printf(" %d", ptr->next); // address prin karega
        printf(" \n");

        ptr = ptr->next; // ptr ka update karta he
    }
}

int main()
{


    firstinsert(10);
    firstinsert(20);
    firstinsert(30);
    firstinsert(40);
    firstinsert(50); // 50 40 30 20 10 NULL
    display();
    // length();
    fDelete(); // 40 30 20 10 NULL
    display();
    // length();
    lastInsert(100); // 40 30 20 10 100 NULL
    display();
    lastDelete(); // 40 30 20 10 NULL
    display();
    insertAtIndex(123, 1); // element 123 ata index o // 40 123 30 20 10 NULL
    display();

    deleteAtIndex(2); // 40 123 20 10 NULL
    display();

    return 0;
}