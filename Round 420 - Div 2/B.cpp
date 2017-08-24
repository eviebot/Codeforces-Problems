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

    long long int m, b;
    cin >> m >> b;

    long long int temp, maxi=0, x, y;

    for(y = 0; y <= b; ++y)
    {
        x = (b-y)*m;
        temp = ( x*(x+1)/2 )*(y+1) + ( y*(y+1)/2 )*(x+1);
        maxi = max(maxi , temp);
    }
    cout << maxi;
}
