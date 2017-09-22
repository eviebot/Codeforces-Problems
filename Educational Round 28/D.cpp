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


int n, m, k, q, val;
vector <pair <int, pair <int, int>>> times;

bool checker(int t){
	bool arr[502][502];
	int pixels[502][502];
	int i, j;
	for(i =0 ; i <= n+1; ++i){
		for(j = 0; j <= m+1; ++j){
			arr[i][j] = 0;
		}
	}
	for(int i =0 ; i < q; ++i){
		if(times[i].fi <= t)
			arr[times[i].se.fi][times[i].se.se] = 1;
	}
	for(i = 0; i <= m; ++i){
		pixels[i][0] = 0;
		pixels[0][i] = 0;
	}

	for(i = 1; i <= n; ++i){
		for(j = 1; j <= m; ++j){
			pixels[i][j] = pixels[i][j-1] + pixels[i-1][j] + arr[i][j] - pixels[i-1][j-1];
			//cout << i << " "<< j << ' '<< pixels[i][j] << ' '<< t << "\n";
		}
	}
	for(i = k; i <= n; ++i){
		for(j = k; j <= m; ++j){
			if(pixels[i][j] - pixels[i][j-k] - pixels[i-k][j] + pixels[i-k][j-k] == val){
				//cout << i << " "<< j << " "<< i-k << " "<< j-k << " " << t << "\n";
				return true;
			}
		}
	}

	return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j, r, c, t;
	cin >> n >> m >> k >> q;
	
	val = k*k;
	
	for(i = 0; i < q; ++i){
		cin >> r >> c >> t;;
		times.pb(MP(t, MP(r, c)));
	}
	sort(times.begin(), times.end());

	int lower = 0, upper = 1000000000, mid;
	while(true){
		mid = (upper+lower)/2;
		if(upper == lower){
			if(checker(lower)){
				cout << lower << "\n";
				return 0;
			}
			break;
		}
		if(upper == lower+1){
			if(checker(lower)){
				cout << lower << "\n";
				return 0;
			}else if(checker(upper)){
				cout << upper << "\n";
				return 0;
			}
			break;
		}
		if(checker(mid)){
			upper = mid;
		}else{
			lower = mid+1;
		}
	}
	cout << "-1\n";
}