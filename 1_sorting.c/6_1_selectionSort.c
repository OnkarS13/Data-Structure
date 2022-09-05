#include <stdio.h>

int size;

int main()
{
    int a[10] = {78, 59, 25, 5, 12, 39}; // list is created
    int size = 6;
    int k;
    for (int i = 0; i < size - 1; i++)//size - 1 tak chalewga bcoz, last element swap karne ki jaroorat nahi he
    {
        k = i;
        int min = a[i]; // first har time min ek ek se badhata rahega

        for (int j = i + 1; j < size; j++) // yaha pe size end tak chalega
        {
            if (a[j] < min) // a agar a[j] min se kam hoga to k ko uska index number deke min ko update kar do
            {
                k = j;      // index is updated
                min = a[j]; // here value is updated or replaced
            }
        }

        if (k != i) // agar k aur i same nhi honge tohi swap karna he....agar vo ek hi number honge to swap karke koi fayada nahi
        {
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        printf("\n%d", a[i]);
    }

    return 0;
}
