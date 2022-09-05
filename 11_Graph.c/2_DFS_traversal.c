#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // first empty visited list is created
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)                          // ye ek integer lega
{
    printf("%d ", i);                    // first integer ko print karega
    visited[i] = 1;                      // aur us interger ke place ko visited kar dega...update kaega ..1 matlab vsited and 0 matlab non visited
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j]) // yaha [i][j] matlab i se kaha par bhi ek edge ja rahi he aur j visited nahi he
                                         // ab usi integer aur loop se chalaye huye j en dono me agar edge he aur jth position visited nahi he to use firse 'j' ko DFS function me push karo
                                         // ab 'j' DFS me as 'i' jayega aur print hoga aur visited function se vo visited mark hoga ... aur ab j ki value aage badhegi aur ye process tab tak chalegi jab tak sare 'j' elements visited nahi hote
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(0); // DFS ki starting '0' kr sakte or kis se bhi kar sakte vo DFS traversal dega
    return 0;
}


