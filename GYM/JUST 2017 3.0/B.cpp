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
	int test, n, i, u, v;
	cin >> test;
	
	for(int z =0; z < test; ++z){
		lli sum = 0;
		cin >> n;
		vector <pair <int, int>> matrices;
		unordered_map <int, int> rows;
		for(i = 0; i < n; ++i){
			cin >> u >> v;
			rows[u]++;
			matrices.pb(MP(u, v));
		}

		for(i = 0; i < n; ++i){
			sum += (lli)(rows[matrices[i].se]);
			if(matrices[i].fi == matrices[i].se){
				--sum;
			}
		}
		cout << sum << "\n";
	}
}