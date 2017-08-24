#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, sum = 0, i;
    scanf("%d", &n);
    int radii[n];
    for(i = 0; i< n;i++)
    {
        scanf("%d", &radii[i]);
    }
    sort(radii, radii+n);
    for(i=0; i< n;i++)
    {
        if(n%2==0)
        {
            sum += (i%2==0?(-radii[i]*radii[i]):radii[i]*radii[i]);
        }
        else
        {
            sum += (i%2==0?(radii[i]*radii[i]):(-radii[i]*radii[i]));
        }
    }
    double f_sum = 3.1415926536*sum;

    cout << setprecision(10)<<f_sum;
}
