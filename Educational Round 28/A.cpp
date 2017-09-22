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

	int n, arr[200], i, sum, j;
	cin >> n;
	sum = 0;

	for(i = 1; i <=n;++i)
		cin >> arr[i];

	for(i = 0; i <= n; ++i){
		int sum2 = 0;
		for(j = 1; j <= i; ++j){
			if(!arr[j])
				++sum2;
		}
		for(j = i+1; j <= n; ++j){
			if(arr[j])
				++sum2;
		}
		sum = max(sum, sum2);
	}
	
	cout << sum << "\n";
	}