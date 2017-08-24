#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    int last, sec_last;
    cin >> n;
    if(n>0)
        cout << n;
    else
    {
        n = abs(n);
        last = n%10;
        sec_last = (n/10)%10;
        n/=100;
        n*=10;
        n+=min(last, sec_last);
        cout << (n==0?"":"-")<< n;
    }

}
