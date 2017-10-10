#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cerr.tie(NULL);
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

	vector <pair <int, int>> a;
	vector <pair <int, int>>::iterator iter;
	a.pb(MP(3, 10));
	a.pb(MP(10, 20));
	a.pb(MP(20, 30));

	iter = lower_bound(a.begin(), a.end(), MP(2, numeric_limits<int>::min()));
	cout << iter->fi << " "<< iter->se<< "\n";
}