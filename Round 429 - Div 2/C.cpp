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
	int n, t, i;
	
	int free1 = -1, free2 = -1;

	cin >> n;
	vector <pair <int, int>> myvec;
	int u, v;
	for(i = 0; i < n; ++i){
		cin >> u >> v;
		
		myvec.pb(MP(u, v));
	}

	sort(myvec.begin(), myvec.end());

	for(i = 0; i < n; ++i){
		
		if(myvec[i].fi > free1)
			free1 = myvec[i].se;
		else if(myvec[i].fi > free2)
			free2 = myvec[i].se;
		else{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}