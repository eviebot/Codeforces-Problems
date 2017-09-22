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

	int k, t, maxi = 0;
	cin >> k;
	for(int i = 1; i <= k; ++i){
		cin >> t;
		maxi = max(maxi, t);
	}

	cout << max(0, maxi-25) << "\n";
}