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

	
	int n, i, j, t, k, sum = 0, store = 0;
	cin >> n >> k;

	for(i = 1; i <= n; ++i){
		cin >> t;
		store += t;
		sum += min(store, 8);
		store -= min(store, 8);
		if(sum >= k){
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}