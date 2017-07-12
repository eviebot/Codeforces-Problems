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
	int n, k, i, j, val, t, maxi = 0, temp;
	string s;
	vector <pair <string, int>> data;
	data.pb(MP("sex", 0));
	vector <int> array;

	cin >> n;

	for(i = 0; i <= 2000001;++i)
		array.pb(0);

	for(i = 1; i <= n; ++i)
	{
		cin >> s >> k;
		data.pb( MP(s, s.size()));

		for(j = 0; j < k; ++j)
		{
			cin >> t;
			if( data[i].se > data[array[t]].se)
			{
				array[t] = i;
			}
			maxi = max(maxi, t+data[array[t]].se-1);
		}
	}
	/*for(i = 1; i <= maxi; ++i)
	{
		cout << i << " "<< array[i] << " "<< data[array[i]].fi << ' '<< data[array[i]].se << "\n";
	}*/
	
	for(i = 1; i <= maxi;)
	{
	
		if( !array[i])
		{
			++i;
			cout << 'a';
			continue;
		}

		t = i ;
		temp = t + data[array[i]].se ;

		while(i < temp)
		{
			if( data[array[i]].se > temp - i)
			{
				break;
			}
			cout <<  (data[array[t]].fi)[i-t];
			++i;
		}

	}
	cout << "\n";
}