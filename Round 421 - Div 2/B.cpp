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

    int n, a, i, index;
    double mini = 1000.0, ref_anglet,smallest;
    cin >> n >> a;

    ref_anglet = (double((n-2)*180))/n;
    smallest = ref_anglet / (n-2);

    for(i = 1; i <= n-2; ++i)
    {
        if( abs(a - smallest*i) < mini )
        {
            index = i;
            mini = abs(a-smallest*i);
        }
    }
    cout << "2 1 "<< 2+index;
}
