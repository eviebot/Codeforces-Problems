#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back


int main()
{
    int n, first, t, sum=0;
    scanf("%d %d", &n, &first);
    sum += (2*n+first-1);
    for(int i = 1;i<n;i++)
    {
        scanf("%d", &t);
        sum += abs(max(first, t)-min(first, t));
        first = t;
    }
    cout << sum;
}
