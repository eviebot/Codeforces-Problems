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
	int test, n, i, t, q, j, l, r;
	char c;
	int f[11000][30];
	string s;
	cin >> test;
	for(int z =0 ; z < test; ++z){
		cin >> n >> q;
		cin >> s;
		for(i = 0; i < 26; ++i)
			f[0][i] = 0;
		for(i = 1; i <= n; ++i){
			for(j = 0; j < 26; ++j)
				f[i][j] = f[i-1][j];
			f[i][s[i-1]-'a']++;
		}
		for(int x = 0; x < q; ++x){
			cin >> l >> r >> c;
			int size = r-l+1;
			lli sum = ((int)(size/n))*f[n][c-'a'];
			if(!(size%n)){
				cout << sum << "\n";
				continue;
			}
			l %= n;
			r %= n;
			if(!l)
				l = n;
			if(!r)
				r = n;
			//cout << f[n][c-'a'] << " "<< l << " "<< r << " "<< sum << "\n";
			if(l <= r){
				sum += (lli)(f[r][c-'a'] - f[l-1][c-'a']);
			}else{
				sum += (lli)(f[n][c-'a']-f[l-1][c-'a']+f[r][c-'a']);;
			}
			cout << sum << "\n";
		}
	}
}