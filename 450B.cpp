#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back


int main()
{
    long long int x, y, n, t, val;
    cin >> x >> y >> n;
    t = n%6;
    switch(t)
    {
        case 0: val=(x-y);
                break;
        case 1: val=x;break;
        case 2: val = y;break;
        case 3: val = (y-x);break;
        case 4: val = -x; break;
        case 5: val = -y; break;
    }
    if(val%1000000007 <0)
        cout << (1000000007-abs(val%1000000007));
    else
        cout << val %1000000007;
}
