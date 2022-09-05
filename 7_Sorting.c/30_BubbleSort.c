#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass // yaha pe n-1 kiya because jitne numbers hote he usse ek kam number ke swappings hoti he
    {
        printf("Working on pass no. %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass // this is for traversing from end to front
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;               // first it is made false
    for (int i = 0; i < n - 1; i++) // For number of pass // yaha pe n-1 kiya because jitne numbers hote he usse ek kam number ke swappings hoti he
    {
        printf("Working on pass no. %d\n", i + 1);
        isSorted = 1; // agar array pahalesehi sorted hoga to isSorted  = 1 ye true hoga aur agar sorted nahi hoga to vo second for loop me jayega aur usmese
        // isSorted ka value = 0 hoga matlab Sorted false hoga
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass // this is for traversing from end to front
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted) // Agar Sorted hoga to return hoga
        {
            return;
        }
    }
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array before sorting
    bubbleSortAdaptive(A, n); // Function to sort the array
    printArray(A, n); 
    return 0;
}