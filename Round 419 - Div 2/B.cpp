#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;
ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    int n, k, q, i, j, sum, l, r;
    int permissible[200002] = {0};
    cin >> n >> k >> q;

    for(i = 0; i < n; ++i)
    {
        cin >> l >> r;
        for(j = l; j <= r; ++j)
        {
            ++permissible[j];
        }
    }
    for(i = 0; i < q; ++i)
    {
        cin >> l >> r;
        sum = 0;
        for(j = l; j <= r; ++j)
        {
            if( permissible[j] >= k)
                ++sum;
        }
        cout << sum << "\n";
    }
}
