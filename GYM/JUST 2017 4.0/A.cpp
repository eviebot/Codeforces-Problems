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
	int test, n, i, t, j;
	lli sum = 0, multi, x;
	cin >> test;
	for(int z = 0; z < test; ++z){
		vector <bitset <20>> arr;
		bitset <20> temp;
		cin >> n;
		sum = 0;
		multi = 1;
		for(i = 0; i < n; ++i){
			cin >> t;
			temp = t;
			arr.pb(temp);
		}
		temp = 0;
		arr.pb(temp);
		for(i = 0; i < 20; ++i){
			x = 0;
			for(j = 0; j <= n; ++j){
				if(arr[j][i])
					++x;
				else{
					//cout << i << " "<< j << " "<< x << "\n";
					sum += (x*(x+1)*multi/2);
					x = 0;
				}
			}
			sum += (x*(x+1)*multi/2);
			multi *= 2;
		}
		cout << sum << "\n";
	}
}