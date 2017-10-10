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
	int test, n, i, t, j;
	int DP[210000], col[210000], color[210000];

	cin >> test;
	for(int z = 0; z < test; ++z){
		cin >> n;
		for(i = 1; i <= 200000; ++i)
			color[i] = 1000000000;

		for(i = 1; i <= n; ++i){
			cin >> col[i];
		}
		DP[1] = 0;
		color[col[1]] = 0;
		for(i = 2; i <= n; ++i){
			DP[i] = min(DP[i-1]+1, color[col[i]]+1);
			color[col[i]] = DP[i];
		}

		cout << DP[n] << "\n";
	}
}