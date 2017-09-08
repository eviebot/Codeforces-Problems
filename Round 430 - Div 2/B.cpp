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
	int d, r, i, n, x, y, ri, sum = 0;
	double rsmall, rr, rsaus;
	cin >> r >> d;
	rsmall = r-d;
	rr = r;

	cin >> n;
	for(i =0; i < n; ++i){
		cin >> x >> y >> ri;
		rsaus = sqrt(x*x+y*y);

		double rit = ri;
		if( (rsaus-rit) >= (rsmall) && (rsaus+rit) <= rr) 
			++sum;
	}
	cout << sum << "\n";
}