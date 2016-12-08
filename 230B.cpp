#include <bits/stdc++.h>
// i'm a dumb idiot
using namespace std;
#define endl "\n"
bool prime(long long int *x)
{
    long long int a, j, k;
    a = *x;
    if(a == 1)
        return false;
    k = sqrt(a);

    for(j = 2; j<=(k) ;j+=1)
    {
        if(a%j==0)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n, i, t, sqt;
    cin >> n;
    for(i=1; i<=n;i++)
    {
        cin >> t;
        sqt = sqrt(t);
        if(t==sqt*sqt && prime(&sqt)== true ){cout << "YES"<< endl;}

        else{cout << "NO"<< endl;}
    }

}
