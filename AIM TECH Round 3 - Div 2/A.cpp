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

	lli n, b, d;
	cin >> n >> b >> d;

	lli t, sum = 0, x= 0;

	for(lli i =0; i < n; ++i){
		cin >> t;
		if( t <= b){
			sum += t;
		}else{
			continue;
		}

		if(sum > d){
			sum = 0;
			++x;
		}
	}
	cout << x << "\n";
}