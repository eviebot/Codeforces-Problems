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
	
	int free1 = 0, free2 = 0, cur = -1;

	cin >> n;
	vector <pair <int, int>> myvec;
	int u, v;
	for(i = 0; i < n; ++i){
		cin >> u >> v;
		
		myvec.pb(MP(u, v));
	}

	sort(myvec.begin(), myvec.end());

	bool flag = false;
	for(i = 0; i < n; ++i){
		if(myvec[i].fi >= cur){
			cur = myvec[i].se;
			continue;
		}
		else if(myvec[i].fi < cur){
			cout << "NO\n";
			return 0;
		}
		

	}
	cout << "YES\n";
}