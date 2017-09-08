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

	int l, r, x, y, k;
	double kk, rangel, rangeu;
	cin >> l >> r >> x >> y >> k;
	kk = (double)(k);

	rangel = (double)(l)/y;
	rangeu = (double)(r)/x;

	if(kk < rangel || kk > rangeu)
		cout << "NO\n";
	else
		cout << "YES\n";
}