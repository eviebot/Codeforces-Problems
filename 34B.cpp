#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, max_tv, sum = 0, i;
    scanf("%d %d", &n, &max_tv);
    int t[n];
    for(i=0;i<n;i++)
    {   scanf("%d", &t[i]);
    }
    sort(t, t+n);
    for(i=0;i<n;i++){
        if(t[i] < 0)
        {
            sum += abs(t[i]);
            max_tv--;
        }
        if(max_tv==0)
            break;
    }
    cout << sum;
}
