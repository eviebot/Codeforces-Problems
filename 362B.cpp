#include <bits/stdc++.h>
// I REALLY NEED TO SLEEP IM DOING THE SAME MISTAKE OVER AND OVER AGAIN
using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n, m, t, i;
    cin >> n >> m;
    set <long long int> myset;
    for(i = 0; i< m;i++)
    {
        cin >> t;
        myset.insert(t);
    }
    if(m==0)
    {
        cout << "YES";return 0;}
    if(*myset.begin()==1 || *(--myset.end())==n){cout << "NO";return 0;}
    if(m<=2){cout << "YES";return 0;}
    set<long long int>::iterator it = myset.begin();
    advance(it, 2);
    for(;it!=myset.end();it++)
    {   t = *it;
    advance(it, -2);
    i = *it;
        if(t-i==2)
        {
            cout << "NO";
            return 0;
        }
        advance(it, 2);

    }
    cout << "YES";
}
