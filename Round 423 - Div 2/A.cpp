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

fastIO;
	long long int n, a, b, i, j, sum = 0;
	cin >> n >> a >> b;

	b *= 2;

	for(i = 0; i < n; ++i)
	{
		cin >> j;
		if(j == 1)
		{
			if( a)
				--a;
			else if( b)
				--b;
			else
				++sum;
		}
		else
		{
			if( b > 1)
				b-= 2;
			else
				sum +=2;
		}
	}
	cout << sum << "\n";
}