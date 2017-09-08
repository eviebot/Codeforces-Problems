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

	int n, t, k, i;
	cin >> n >> k >> t;
	int spectators[n+k+1];

	for(i = 1; i <= k; ++i){
		spectators[i] = i;
	}
	for(i = k+1; i <= n; ++i){
		spectators[i] = k;
	}
	for(i = n+1; i <= n+k; ++i){
		spectators[i] = spectators[i-1]-1;
	}

	for(i = 1; i <= n+k; ++i)
		cout << i << " = "<< spectators[i] << "\n";
}