#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element) // jab dono match honge tab index return karega
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int size, int ele)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high) // agar low aur high same huye matlab sab element serch ho gaye
    {
        mid = (low + high) / 2;

        if (array[mid] == ele)
        {
            return mid;
        }
        if (array[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    // Unsorted array for linear search
    int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 544, 56, 34};
    int size = sizeof(arr) / sizeof(int); // this is for finding size of the array
    int element;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nPlease enter the element that you want to find by linear search :- ");
    scanf("%d", &element);

    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    printf("------------------------------------------------------------------------------");
    printf("\n");

    // Sorted array for binary search
    int array[] = {1,3,5,56,64,73,123,225,444};
    int siz = sizeof(array)/sizeof(int); // this is for finding size of the array
    int ele;
    for (int i = 0; i < siz; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\nPlease enter the element that you want to find by binary search :- ");
    scanf("%d", &ele);

    int searchI = binarySearch(array, siz, ele);
    printf("The element %d was found at index %d \n", ele, searchI);

    return 0;
}