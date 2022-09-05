#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size; // abhi inko heap me  dyanamically memory nahi mile he ... jab create array call hoke ussase values size milegi
    int used_size;
    int *ptr; // pointer jo address store karta he aur ye memory block ke pahale block ko point karta he  .... to ye show bhi karne aur set karne ke liye bhi us kar sakte he
};

void createArray(struct myArray *a, int tSize, int uSize) // parameterized function banaya, yaha pe pointer banake vo address srore karta he 
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize; // ye value ko show karta he aur arrow pointer uski value ko show karta he
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int)); //malloc se heap se memory milti he // ye pointer ptr ko heap me dynamic memory alocate karke de raha he ....tsize * sizeof(int)
}

void show(struct myArray *a) // ye void struct array ke a variable ke pointer ko lega
{
    for (int i = 0; i < a->used_size; i++) // for loop chalake shoe karega aur hamesha used size se chota hi rahega
    {
        printf("%d\n", (a->ptr)[i]); // show karte time heap me jo memory alote huyi he vo ptr me store huyi he to use vo one by one show karega
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d :- ", i + 1);
        scanf("%d", &n); // pahale n me assign karega 
        (a->ptr)[i] = n; //aur usi n ko a jo variable banaya ussase assign kar dega
    }
}

int main()
{
    struct myArray marks; // marks nam ka instance banaya

    // upar sabhi jagah pointer banaye he ki jo address as a input leta he...to hame value pass karte samay & laga ke send karna padega 

    createArray(&marks, 10, 2); //&marks ka address myarray *a me jayega 

    printf("We are running setVal now\n");
    setVal(&marks); //setval is called

    printf("We are running show now\n");
    show(&marks); // show marks are called]\

    return 0;
}