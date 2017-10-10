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
int n;vector <pair <pair <int, int>, pair <int, int>>> arr;
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO;
	int  i, j, t, d, p;

	cin >>n;
	int DP[110][2100][2];
	for(i = 0; i <= n; ++i){
		for(j = 0; j <= 2000; ++j){
			DP[i][j][0] = 0;
			DP[i][j][1] = 0;
		}
	}
	arr.pb(MP(MP(0, 0), MP(0, 0)));
	for(i = 1; i <= n; ++i){
		cin >> t >> d >> p;
		arr.pb(MP(MP(d, p), MP(t, i)));
	}
	sort(arr.begin()+1, arr.end());

	for(i = 1; i <= n; ++i){
		for(j = 0; j <= 2000; ++j){
			DP[i][j][0] = DP[i-1][j][0];
			DP[i][j][1] = 0;
			if(j >= arr[i].fi.fi || j < arr[i].se.fi)
				continue;
			if(DP[i-1][j-arr[i].se.fi][0]+arr[i].fi.se > DP[i][j][0]){
				DP[i][j][0] = DP[i-1][j-arr[i].se.fi][0]+arr[i].fi.se;
				DP[i][j][1] = 1;
			}
			/*if(j < 100){
				cout << i << " "<< j << " "<< DP[i][j] << "\n";
			}*/
		}
	}
	int maxi = 0, index;
	for(i = 0; i <= 2000; ++i){
		if(DP[n][i][0] > maxi){
			maxi = DP[n][i][0];
			index = i;
		}
	}
	cout << maxi << "\n";
	i = n;
	vector <int> kkk;
	while(maxi){
		if(DP[i][index][1]){
			kkk.pb(arr[i].se.se);
			maxi -= arr[i].fi.se;
			index -= arr[i].se.fi;
		}
		--i;
	}
	cout << kkk.size() << "\n";
	reverse(kkk.begin(), kkk.end());
	for(auto it:kkk)
		cout << it << " ";
	cout << "\n";
}