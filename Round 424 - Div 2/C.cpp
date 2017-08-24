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
	lli n, k, i, t, init_val, x, j;
	set <lli> final;
	unordered_map<lli, bool> rem;
	unordered_map<lli, bool>::iterator iter;
	cin >> k >> n;

	lli data[k+1], sum[k+1];
	sum[0] = 0;

	for(i = 1; i <= k; ++i)
	{
		cin >> data[i];
		sum[i] = sum[i-1] + data[i];
	}

	for(i = 1; i <= n; ++i)
	{
		cin >> t;
		rem.insert(MP(t, 1));
	}

	iter = rem.begin();
	x = iter->fi;
	for(i = 1; i <= k; ++i)
	{
		for(iter = rem.begin(); iter != rem.end(); ++iter)
			iter->se = 1;
		init_val = x - sum[i];
		t = n;
		//cout << init_val << " ";
		for(j = 1; j <= k; ++j)
		{
			init_val += data[j];
			iter = rem.find(init_val);

			if( iter != rem.end() && iter->se )
			{
				iter->se = 0;
				--t;
			}
		}
		//cout << t << "\n";
		if( t <1){

			final.insert(x-sum[i]);
		}
	}
	cout << final.size()<< "\n";

}