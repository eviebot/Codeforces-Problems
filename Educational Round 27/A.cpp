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

	int n, i, t;
	vector <int> array;
	cin >> n;
	for(i = 0; i < 2*n; ++i){
		cin >> t;
		array.pb(t);
	}


	sort(array.begin(), array.end());

	if(array[n] == array[n-1]){
		cout << "NO\n";
	}
	else
		cout << "YES\n";
}