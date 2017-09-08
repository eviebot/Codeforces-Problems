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

	fastIO;
	int n, m, test, i, j;
	lli t, sum, sum2;
	vector <vector <pair <lli, lli>>> DP;
	vector <vector <lli>> time,cost;
	vector <pair <lli, lli>> temp;
	vector <lli> temp2;
	for(i = 0; i <= 25010; ++i){
		temp2.pb(0);
		temp.pb(MP(0, 0));
	}

	for(i = 0; i <= 26; ++i){
		DP.pb(temp);
		cost.pb(temp2);
		time.pb(temp2);
	}
	cin >> test;
	for(int z = 0; z < test; ++z){
		cin >> n >> m;
		
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= m; ++j){
				cin >> cost[j][i];
			}
		}
		for(i = 1; i <= n; ++i){
			sum = 0;
			time[1][i] = 0;
			for(j = 2; j <= m; ++j){
				cin >> t;
				sum += t;
				time[j][i] = sum;
			}
			
		}

		for(i = 1; i <= m; ++i){
			DP[i][1].fi = 0;
			DP[i][1].se = time[i][1];
		}

		for(i = 2; i <= n+1; ++i){
			
			for(j = 1; j <= m; ++j){
				lli mini = 1000000000000000ll, minitime ;
				for(int k = 1; k <= m; ++k){
					sum = DP[k][i-1].fi + cost[j][i-1];
					sum2 = DP[k][i-1].se + abs(time[k][i-1] - time[j][i-1]);
					
					if( sum < mini ){
						mini = sum;
						minitime = sum2;
					}else if(sum == mini){
						if(sum2 < minitime){
							minitime = sum2;
						}
					}
				}
				DP[j][i].se = minitime;
				DP[j][i].fi = mini;
			}
		}
		lli mini = DP[1][n+1].fi, minitime = DP[1][n+1].se;
		
		for(j = 2; j <= m; ++j){
			if(DP[j][n+1].fi < mini){
				minitime = DP[j][n+1].se;
				mini = DP[j][n+1].fi;
			}
			else if(DP[j][n+1].fi == mini && DP[j][n+1].se < minitime)
				minitime = DP[j][n+1].se;
		}
		cout << mini << " " << minitime << "\n";
	}
}