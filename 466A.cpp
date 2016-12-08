#include <bits/stdc++.h>

// derp derp derpidity derp derp derp derp derpity derp

using namespace std;

int main()
{
    unsigned int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    if(n>m){
    if(m*a > b)
    {
        cout << ((b>(n%m)*a)?(b*(n/m)+(n%m)*a):(b*(n/m)+b));
    }
    else
    {
        cout << n*a;
    }}
    else
    {
        cout << (b<(a*n)?b:a*n);
    }
}
