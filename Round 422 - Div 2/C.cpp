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
	lli n, x, l, r, c, i, t, j, k, tt;

	vector <vector <pair <int, pair <int, int>>>> myvec;
	vector <pair <int, pair <int, int>>> temp;

	cin >> n >> x;

	for(i = 0; i < x; ++i)
	{
		myvec.pb(temp);
	}

	for(i =0; i < n; ++i)
	{
		cin >> l >> r >> c;
		t = r-l+1;
		if( t < x)
			myvec[t].pb(MP(c, MP(l, r)));
	}

	int mini = INT_MAX;
	
	for(i = 1; i < x; ++i)
	{
		t = x-i;
		
		for(k = 0; k < myvec[i].size(); ++k)
		{
			for(j = 0; j < myvec[t].size(); ++j)
			{
				//cout << myvec[t][j].se.fi << " "<< myvec[t][j].se.se << " "<< myvec[i][k].se.fi << " "<< myvec[i][k].se.se << "\n";
				if( myvec[t][j].se.se < myvec[i][k].se.fi || myvec[i][j].se.se < myvec[t][j].se.fi)
				{
					tt = myvec[t][j].fi + myvec[i][k].fi;
					if( tt < mini)
						mini = tt;
				}
			}
		}
	}

		
	if( mini == INT_MAX)
		cout << "-1\n";
	else
		cout << mini << "\n";
}