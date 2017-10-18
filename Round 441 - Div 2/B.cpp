#include <bits/stdc++.h>


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, m, k, i, j;
	vector <vector <int>> count;
	cin >> n >> k >> m;
	count.resize(m+1);

	for(i = 1; i <= n; ++i){
		cin >> j;
		count[j%m].pb(j);
	}
	for(i = 0; i < m; ++i){
		if(count[i].size() >= k){
			cout << "Yes\n";
			for(j = 0; j < k; ++j){
				cout << count[i][j] << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "No\n";
}