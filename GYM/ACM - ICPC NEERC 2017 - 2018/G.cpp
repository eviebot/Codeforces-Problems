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
	int n, maxi = 0;
	vector <string> vec;
	string s;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		vec.pb(s);
	}
	for(int j= 0; j < 7; ++j){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(vec[i][j] == '1'){
				++sum;
			}
		}
		maxi = max(maxi, sum);
	}
	cout << maxi << "\n";
}