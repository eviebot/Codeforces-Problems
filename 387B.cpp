#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m, i, j, sum = 0;
    scanf("%d %d", &n, &m);
    int good[n], g[m];
    for(i = 0; i< n;i++)
    {
        scanf("%d", &good[i]);
    }
    for(i=0;i< m;i++)
    {
        scanf("%d", &g[i]);
    }
    j = n-1;
    i = m-1;
    while(j>=0 && i>=0)
    {
        if(good[j] > g[i])
        {
            sum++;
        }
        else
        {
            i--;
        }
        j--;
    }j++;
    sum += j;
    cout << sum;
}
