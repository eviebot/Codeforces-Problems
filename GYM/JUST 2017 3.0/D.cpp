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
	int arr[15000][7], i, test, j, n;

	for(i = 1; i <= 10000; ++i){
		for(j = 1; j <= 6; ++j)
			arr[i][j] = 1000000000;
	}
	arr[1][1] = 0;
	arr[2][2] = 1;
	arr[3][3] = 1;
	arr[4][4] = 1;
	arr[5][5] = 1;
	for(i = 6; i <= 10000; ++i){
		for(j = 1; j <= 6; ++j){
			if(i-j <= 1)
				break;
			int temp = INT_MAX;
			for(int k = 1; k <= 6; ++k){
				if(k != j && k != 7-j){
					temp = min(temp, arr[i-j][k]+1);
					
				}
			}

			arr[i][j] = temp;
		}
	}
	
	cin >> test;

	for(int  z= 0; z < test; ++z){
		cin >> n;
		if(n == 1){
			cout << "-1\n";
			continue;
		}
		int mini = INT_MAX;
		for(j = 1; j <= 6; ++j){
			mini = min(mini, arr[n][j]);
		}
		cout << mini << "\n";
	}
}