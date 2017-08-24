#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    long long int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    long long int n = 1, temp = 0;
    while(true)
    {
        temp += min(v0 + (n-1)*a, v1);
        if( temp >= c){
            cout << n;break;}

        temp -= l;
        ++n;
    }
}
