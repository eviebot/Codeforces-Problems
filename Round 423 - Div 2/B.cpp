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
	int N, M, rowmin = INT_MAX, colmin = INT_MAX, rowmax= 0, colmax = 0, rows, cols, maxi, sum;
	string s;
	int data[101][101], i, j;

	cin >> N >> M;
	for(i = 1; i <= N; ++i)
	{
		cin >> s;
		for(j = 1; j <= M; ++j)
		{
			if( s[j-1] == 'B')
			{
				if( i > rowmax)
					rowmax = i;
				if( i < rowmin)
					rowmin = i;

				if( j > colmax)
					colmax = j;
				if( j < colmin)
					colmin = j;

				data[i][j] = 1;
			}
			else
				data[i][j] = 0;
		}
	}
	if( rowmax == 0)
	{
		cout << 1 ;
		return 0;
	}

	rows = rowmax - rowmin +1;
	cols = colmax - colmin +1;
	maxi = max(rows, cols);

	if( maxi > N || maxi > M)
	{
		cout << -1 ;
		return 0;
	}

	sum = maxi * maxi;

	for(i = rowmin; i <= rowmax; ++i)
	{
		for(j = colmin; j <= colmax; ++j)
		{
			if( data[i][j])
				--sum;
		}
	}
	cout << sum ;
	return 0;
}