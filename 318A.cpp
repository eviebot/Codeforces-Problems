#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n, k, f;
    cin >> n >> k;
    if(n%2==1)
    {   f = (k<=(n/2+1)?(2*k-1):(2*(k-n/2-1)));
        cout << f;
    }
    else
    {   f = (k<=n/2?(2*k-1):2*(k-n/2));
        cout << f;
    }
}
