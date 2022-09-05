#include<stdio.h>

int main(){
    int a[6] = {15, 4, 9, 10, 17, 50};
    int max = a[0]; // at start max  = 15

    int i = 0;
    for (i = 0; i <= 6; i++)
    {
        if (a[i] > max)
        {
            max = a[i];// Here max is being updated
        }
    }
    // printf(a[i]);
    // printf(" ");
    printf("Largest in given array is %d", max);
    printf("\n");
    printf("Largest in given array is %d", a[i]);
    return 0;
}