#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main()
{
    int n , d, i, sum=0, t;
    scanf("%d %d", &n , &d);

    for(i=0; i< n; i++)
    {
        scanf("%d", &t);
        sum +=t;
    }
    sum += 10*(n-1);
    if(sum > d)
        cout << "-1";
    else
    {
        cout << ((n-1)*2 + (d-sum)/5);
    }
}
