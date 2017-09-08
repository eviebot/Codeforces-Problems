#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, m, k, i, t, date, c1, c2, cost, j;
	cin >> n >> m >> k;
	vector <vector <pair <int, int>>> arrival;
	arrival.resize(n+1);
	vector <tuple <int, int, int>> dept;

	for(i = 1; i <= m; ++i){
		cin >> date >> c1 >> c2 >> cost;
		if(c2){
			arrival[c2].pb(MP(date, cost));
		}else{
			dept.pb(MT(date, cost, c1));
		}
	}

	lli minarrival[n+1], mindept[n+1], tsum = 0, sum = 1000000000000000ll, curdept = 0, pointer[n+1];
	sort(dept.begin(), dept.end());
	for(i = 1; i <= n; ++i){
		mindept[i] = INT_MAX;
		minarrival[i] = INT_MAX;
		sort(arrival[i].begin(), arrival[i].end());
		if(!arrival[i].size()){
			cout << "-1\n";
			return 0;
		}
	}

	for(i = 1; i <= n; ++i){
		for(j = 0; j < arrival[i].size(); ++j){
			if(arrival[i][j].se < minarrival[i]){
				minarrival[i] = arrival[i][j].se;
				pointer[i] = j;
			}
		}
		tsum += minarrival[i];
	}
	for(i = 0; i < dept.size(); ++i){
		int city = get<2>dept[i], dep = get<0>dept[i];
		if(get<1>dept[i] < mindept[city]){
			while(pointer[city] != arrival[city].size()){
				if(arrival[city][pointer[city]].fi > dep+k){
					break;
				}
				++pointer[city];
			}
			
		}
	}

}