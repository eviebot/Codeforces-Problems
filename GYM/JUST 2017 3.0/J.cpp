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
	int test, n, i, arr[1010][1010];

	cin >> test;
	for(int z =0; z < test; ++z){
		cin >> n;
		for(i =1; i <= n; ++i){
			cin >> arr[i][i];
		}
		
		for(int size = 2; size <= n; ++size){
			for(i = 1; i <= n; ++i){
				int j = i + size-1;
				if(j > n)
					break;

				arr[i][j] = max( arr[i][i] - arr[i+1][j], arr[j][j]-arr[i][j-1] );
			}
		}

		cout << arr[1][n] << "\n";
	}
}