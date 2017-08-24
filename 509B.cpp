#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, k, i, mini, maxi, j, status, t, y;
    scanf("%d %d", &n, &k);
    int n_pebbles[n];
    scanf("%d", &n_pebbles[0]);
    mini = n_pebbles[0]; maxi = n_pebbles[0];
    for(i=1; i< n;i++)
    {
        scanf("%d", &n_pebbles[i]);
        if(n_pebbles[i]< mini)
            mini = n_pebbles[i];
        else if(n_pebbles[i] > maxi)
            maxi = n_pebbles[i];
    }
    if(maxi-mini > k)
        cout << "NO";
    else
    {
        cout << "YES\n";
        for(i=0; i< n;i++)
        {
            status = n_pebbles[i]%k;
            t = n_pebbles[i]/k;
            for(j=1;j<=k;j++)
            {   if(status)
                {
                    printf("%d ", j);status--;
                }
                for(y = 1; y <=t;y++)
                    printf("%d ", j);
            }
            printf("\n");
        }
    }
}
