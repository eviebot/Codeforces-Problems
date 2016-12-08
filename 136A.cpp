#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, t;
    scanf("%d", &n);
    int reversed[n] ;
    for(i= 0; i< n; i++)
    {
        scanf("%d", &t);
        reversed[t-1] = (i+1);
    }


    for(int j = 0 ; j< n; j++)
    {
        cout << reversed[j] << " " ;
    }
}
