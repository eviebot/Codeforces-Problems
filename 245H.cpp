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

string s;
int n, q, l, r;
int DP[5010][5010];
bool PAL[5010][5010];

void func(){
	int i, j;
	for(i = 1; i < n; ++i){
		PAL[i][i] = 1;
		DP[i][i] = 1;
		if(s[i] == s[i+1]){
			PAL[i][i+1] = 1;
			DP[i][i+1] = 3;
		}else{
			PAL[i][i+1] = 0;
			DP[i][i+1] = 2;
		}
	}

	for(int len = 2; len < n; ++len){
		for(i = 1; i+len <= n; ++i){
			j = i+len;
			if(s[i] == s[j] && PAL[i+1][j-1]){
				PAL[i][j] = 1;
				DP[i][j] = DP[i+1][j] + DP[i][j-1] + 1 - DP[i+1][j-1];
			}else{
				PAL[i][j] = 0;
				DP[i][j] = DP[i+1][j] + DP[i][j-1] - DP[i+1][j-1];
			}
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	cin >> s >> q;
	s = '@'+s;
	n = s.size();
	func();

	for(int i= 1; i <= q; ++i){
		cin >> l >> r;
		cout << DP[l][r] << "\n";
	}
}