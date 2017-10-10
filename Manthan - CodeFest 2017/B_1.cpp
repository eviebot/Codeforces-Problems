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
	lli n, p, q, r, i, t, arr[200000];
	lli DPL[200000], DPR[200000];
	cin >> n >> p >> q >> r;

	for(i = 1; i <= n; ++i){
		cin >> arr[i];
	}

	DPL[0] = -3000000000000000000ll;
	DPR[n+1] = -3000000000000000000ll;

	for(i = 1; i <= n; ++i){
		DPL[i] = max(DPL[i-1], p*arr[i]);
	}
	for(i = n; i >= 1; --i){
		DPR[i] = max(DPR[i+1], r*arr[i]);
	}

	lli maxi = -3000000000000000000ll;

	for(i = 1; i <= n; ++i){
		maxi = max(maxi, DPL[i]+DPR[i]+q*arr[i]);
	}

	cout << maxi << "\n";
}