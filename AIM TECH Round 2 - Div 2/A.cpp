#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int d, l, v1, v2, v;

	cin >> d >> l >> v1 >> v2;
	l -= d;
	v = v1+v2;

	double x= (double)(l)/v;
	cout << fixed << setprecision(15)<<x << "\n";
}