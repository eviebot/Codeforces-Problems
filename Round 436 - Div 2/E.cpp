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
	int n, t[200], d[200], v[200], i, j;
	cin >> n;
	for(i = 1; i <= n; ++i){
		cin >> t[i] >> d[i] >> v[i];
	}

	int DP[110][2100][2];
	for(i = 0; i <= n; ++i){
		for(j = 0; j <= 2000; ++j)
			DP[i][j][1] = INT_MAX;
	}

	DP[0][0][0] = 0;
	DP[0][0][1] = 0;

	for(j = 0; j <= 2000; ++j)
	{
		for(i = 1; i <= n; ++i)
		{
			if(v[i] > j)
				continue;
			DP[i][j][0] = 100000;
			for(int k = 0; k < i; ++k){
				
				if(d[i] <= DP[k][j-v[i]][0] + t[i] || DP[k][j-v[i]][1] >= i)
					continue;
				else{
					//cout << i << " "<< j << "\n";
					DP[i][j][0] = min(DP[i][j][0], DP[k][j-v[i]][0]+t[i]);	
					DP[i][j][1] = i;
				}
			}
		}
	}
	int maxi = 0, index;
	for(i = 1; i <= n; ++i){
		for(j = 0; j <= 2000; ++j){
			if(DP[i][j][0] < 20000 && DP[i][j][0]){
				if(j > maxi){
					maxi = j;
					index = i;
				}
			}
		}
	}
	cout << maxi << "\n";
	vector <int> elements;
	while(maxi){
		if(DP[i][maxi][0] && DP[i][maxi][0] < 20000){
			elements.pb(i);
			maxi -= v[i];
		}
		--i;
	}
	cout << elements.size() << "\n";
	reverse(elements.begin(), elements.end());
	for(auto it:elements)
		cout << it << " ";

	cout << "\n";
}