#include <stdio.h>

int arr[100]; // array arr declared
int ind = -1; // declared for push

void show(int arr[], int size) // takes arr[] and then print one by one
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++) // ab for loop index se chalu hoga ....aur size - 1 tak chalega...because index hamesha size se 1 se kam hi hota he
    {
        arr[i] = arr[i + 1]; // ab array me, index no.position ke bad wale ko index position se assign kiya jayega...matlab index wale position ke value ko replace kiya jayega uske agale wale value se...yahi age chalta rahega
    }                        // eg. 3rd wale index position ki value 4th se replace hogi, 4th ki 5th se...so on
}

void push(int ele)
{
    arr[++ind] = ele; // push function is created using stack
}

int main()
{
    // int arr[100] = {7, 8, 12, 27, 88};
    int p;
    int size;

    int index;

    printf("\nPlease Enter the size of array:-");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("\nPlease enter the element %d :-", i + 1);
        scanf("%d", &p);
        push(p);
    }

    // int size = 5, element = 45, index = 3;
    printf("\nArray before deletion :- \n");
    show(arr, size);

    for (int i = 0; i <= size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("\nEnter the index no. at that position you want to delete:-");
    scanf("%d", &index);

    printf("\nArray after deletion :- \n");
    indDeletion(arr, size, index);
    size -= 1; // size ko addition ke bad 1 se kam hogi
    show(arr, size);

    return 0;
}