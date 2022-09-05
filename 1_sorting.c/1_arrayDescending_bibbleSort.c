#include<stdio.h>

int main(){
    int i;
    int a[6] = {15, 4, 9, 10, 17, 50};
    for (int i = 0; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i <= 5; i++)
    {

        printf("%d ", a[i]);
    }
    return 0;
}