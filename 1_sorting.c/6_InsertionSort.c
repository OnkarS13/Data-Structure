#include <stdio.h>

int size;
int i;
int j;
int k;

int main()
{
    int a[10] = {78, 59, 25, 5, 12, 39};
    int size = 6;
    
    for (int i = 1; i < size ; i++)
    {
        k = a[i]; //  ye index 1 se start hoga aur...use k se assign kiya he
        int j = i - 1; // je ki value i se kam hi rahegi

        // for (int j = i - 1; j >= 0 && a[j] > a[i]; j--)
        // {
        //     int temp = a[i];
        //     a[i] = a[j];
        //     a[j] = temp;
        // }
        // a[i + 1] = a[j];
        // a[j + 1] = a[i];

        while (j >= 0 && a[j] > k) //j, 0 se bada aur a[j] k se bada matlab a[i] se bada
        {
            a[j + 1] = a[j]; // to yaha swapping kiya he // matlab badi value ko age dala he
            j--; // aur decreement kiya he
            // j = j - 1;
        }
        a[j + 1] = k; // aur hamane jo j-- kiya usase decrement hua to hame use ...ek se increment kr ke usi min value ko assign kiya 
    }
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", a[i]);
    }

    return 0;
}