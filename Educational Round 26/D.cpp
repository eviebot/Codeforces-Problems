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

lli n, k;
lli arr[202][2];
bool flags[202];

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli i, sum2, sum5, j, sum[5] , max_s = 0, t, kk, k;

	cin >> n >> kk;
	for(i = 1; i <= n; ++i)
	{
		cin >> t;
		sum2 = 0;sum5 = 0;

		while( !(t%2))
		{
			t/=2;
			++sum2;
		}
		while(!(t%5)){
			t/=5;
			++sum5;
		}
		arr[i][0] = sum2;
		arr[i][1] = sum5;
	}

	lli prev[202][2002], next[202][2002];

	for(i = 1; i <= n; ++i){
		for(j = 0; j <= 2000; ++j)
			prev[i][j] = 0;
	}

	for(i = 1; i <= n; ++i){
		for(j = 0; j <= 2000; ++j)
			next[0][j] = 0;

		for(j = 1; j <= n; ++j){
			for(k = 0; k <= 2000; ++k){
				if(j > i)
					next[j][k] = 0;
				else{
					if(arr[i][1] > k){
						next[j][k] = max(arr[i][0], prev[j][k]);
					}
					else{
						next[j][k] = max( prev[j-1][k-arr[i][1]] + arr[i][0], prev[j][k] );
					}
				}
			}
		}

		for(j = 0; j <= n; ++j){
			for(k = 0; k <= 2000; ++k)
				prev[j][k] = next[j][k];
		}
	}
	lli maxi = 0;
	for(k = 0; k <= 2000; ++k){
		maxi = max(maxi, min(k, prev[kk][k]));
	}

	cout << maxi << "\n";
}
