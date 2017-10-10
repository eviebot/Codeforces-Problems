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
#define mod 1000000007
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, n, i, t;
	lli DP[110000], arr[110000];

	cin >> test;
	for(int z = 0; z < test; ++z){
		cin >> n;
		for(i = 1; i <= n; ++i){
			cin >> arr[i];
		}
		DP[n+1] = 0;
		for(i = n; i >= 1; --i){
			DP[i] = ((arr[i] + DP[i+1])%mod + (arr[i]*DP[i+1])%mod)%mod;
		}
		cout << DP[1] << "\n";
	}
}