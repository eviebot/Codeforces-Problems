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

	int n, k, i, t;
	string s;
	int balloon[27];

	for(i = 0; i < 26; ++i)
		balloon[i] = 0;
	cin >> n >> k >> s;

	for(i = 0; i < n; ++i){
		balloon[s[i]-'a']++;
	}

	for(i =0; i < 26; ++i){
		if(balloon[i] > k){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}