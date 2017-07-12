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

#define MOD 1000000007ll
ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	long long int l, r, i, j, ttt, small, big, sum = 0, multi =1, base = 1000000007;
	vector <long long int > DP, visited;
	cin >> ttt >> l >> r;

	DP.pb(0);
	DP.pb(1);
	visited.pb(0);
	visited.pb(0);

	for(i = 2; i<= r; ++i)
	{
		visited.pb(0);
		DP.pb(0);
	}
	for(i = 2; i <= r; ++i)
	{
		if( !visited[i])
		{
			for(j = i; j <= r; j += i)
			{
				if(!visited[j])
					visited[j] = i;
			}
			DP[i] = (i*(i-1)/2)% base;
		}
	}
	for(i = 4; i <= r; ++i)
	{
		if( !DP[i])
		{
			small = min(visited[i], i/visited[i]);
			big = max(visited[i], i/visited[i]);
			DP[i] = ( (big * DP[small])%base + DP[big])%base;
		}
	}
	
	for(i = l; i <= r; ++i)
	{
		sum =(sum + multi * DP[i]) % base;
		multi = (multi * ttt)%base;
	}
	cout << sum << '\n';
}