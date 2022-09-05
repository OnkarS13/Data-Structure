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

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return 0;
    }

    for (int i = size - 1; i >= index; i--) // ulta for loop chalaya, jisase eg. 4th index wale ko 5th me shift kiya , 3rd ko 4th me, so on...index se equal na ho jaye tab tak
    {
        arr[i + 1] = arr[i]; // aur ek block badhake eg. 5th ki value ko 4th assign kiya, 4th ko 3rd, 3rd ko 2nd,....jab tak desired index ki value aa na jaye
    }
    arr[index] = element; // aur badme jis index pe value add karni he vahape usse element se assign kr do
    return 1;
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
    int element;
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
    printf("\nArray before insertion\n");
    show(arr, size);

    for (int i = 0; i <= size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("\nEnter the index no. at that position you want to add:-");
    scanf("%d", &index);

    printf("\nEnter the element that you want to add:-");
    scanf("%d", &element);

    printf("\nArray after insertion\n");
    indInsertion(arr, size, element, 100, index);
    size += 1; // size ko addition ke bad 1 se badhaya
    show(arr, size);

    return 0;
}