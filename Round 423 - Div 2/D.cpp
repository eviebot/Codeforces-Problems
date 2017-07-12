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

	int n, k, i, j, sum;
	cin >> n >> k;

	int t = n-1;

	sum = (t/k)*2;

	if( t % k == 1)
	{
		sum ++;
	}
	if(t % k > 1)
	{
		sum += 2;
	}

	cout << sum << "\n";

	for(i = 2; i <= k+1; ++i)
	{
		cout << 1<< " "<< i << "\n";
	}

	for(i = k+2; i <= n; ++i)
	{
		cout << i << " "<< i-k << "\n";
	}

	return 0;
}