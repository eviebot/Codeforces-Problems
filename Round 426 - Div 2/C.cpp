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
map <int, int> sieve1, sieve2;
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n_games, a, b, i, sum;

	

	cin >> n_games;

	for(int z = 0; z < n_games; ++z)
	{
		sieve1.clear();
		sieve2.clear();
		cin >> a >> b;
		if( prime(a) )
		{
			if( a == b)
				cout << "YES\n";
			else
				cout << "NO\n";
			return 0;
		}

		i = 2;
		while( a != 1)
		{
			sum = 0;
			while( a%i == 0){
				a/= i;
				++sum;
			}
			sieve1[i] = sum;
			++i;
		}
		i = 2;
		while( b != 1)
		{
			sum = 0;
			while( b%i == 0){
				b /= i;
				++sum;
			}
			sieve2[i] = sum;
			++i;
		}

		for()
	}