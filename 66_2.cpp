
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, i, sum = 1, out = 1, j;
    scanf("%d", &n);
    int h[n];
    for(i=0;i<n;i++)
        scanf("%d", &h[i]);
    for(i = 0; i<n;i++)
    {
        for(j = i-1; j>=0;j--)
        {
            if(h[j]>h[j+1])
            {
                break;
            }
            sum++;

        }
        for(j=i+1;j<n;j++)
        {
            if(h[j]> h[j-1])
            {
                break;
            }sum++;
        }
        out = max(out, sum);
        sum = 1;
    }
    cout << out;
}
