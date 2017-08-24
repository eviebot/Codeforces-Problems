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

int a, b;

bool checker(int x1, int y1, int x2, int y2)
{
	if( (x1+x2) <= a && max(y1, y2) <= b)
		return true;

	if( (x1+x2) <= b && max(y1, y2) <= a )
		return true;

	if( (x1+y2) <= a && max(x2, y1) <= b) 
		return true;

	if( (x1+y2) <= b && max(x2, y1) <= a) 
		return true;

	if( (x2+y1) <= a && max(x1, y2) <= b )
		return true;

	if( (x2+y1) <= b && max(x1, y2) <= a )
		return true;

	if( (y1+y2) <= a && max(x2, x1) <= b )
		return true;

	if( (y1+y2) <= b && max(x2, x1) <= a )
		return true;
	return false;
}

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	
	vector <pair <int, int>> data;
	data.pb({0, 0});

	int n, i, j, maxi = 0, x, y;

	cin >> n >> a >> b;

	for(i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		data.pb(MP(x, y));
	}

	for(i = 1; i <= n; ++i)
	{
		for(j = i+1; j <= n; ++j)
		{
			if( checker(data[i].fi, data[i].se, data[j].fi, data[j].se) )
				maxi = max(maxi, data[i].fi*data[i].se+data[j].fi*data[j].se);
		}
	}
	cout << maxi << "\n";
}