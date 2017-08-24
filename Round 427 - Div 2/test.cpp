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

	string s;
	cin >> s;
	int n= s.size(), i, j, k;

	int dp[n][n];
	bool p[n][n];

	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j){
			p[i][j] = 0;
			dp[i][j] = -1;
		}
		p[i][i] = 1;
		dp[i][i] = 1;	
	}

	for(i = 0; i < n-1; ++i)
	{
		if( s[i] == s[i+1])
		{
			p[i][i+1] = 1;
			dp[i][i+1] = 1;
		}
	}


	for(i = 2; i < n; ++i)
	{
		for(j = 0; j < n-i; ++j)
		{
			k = i+j;
			if(s[j] == s[k] && p[j+1][k-1])
			{
				p[j][k] = 1;
				dp[j][k] = dp[j+1][k]+dp[j][k-1]-dp[j+1][k-1]+1;
			}
			else
				dp[j][k] = dp[j+1][k]+dp[j][k-1]-dp[j+1][k-1];
		}
	}


	cout << dp[0][n-1] << "\n";
}