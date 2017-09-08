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

#define maxi 2000000000000ll
#define smallmaxi 1000000000ll
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli test, n, i, t, arr[2002], j;
	
	fastIO;
	cin >> test;

	for(lli z =0; z < test; ++z){
		cin >> n;
		for(i = 1; i <= n; ++i){
			cin >> arr[i];
		}
		lli n_super = n, sum, tlcm;
		for(i = 1; i < n; ++i){
			sum = arr[i];
			tlcm = arr[i];
			for(j = i+1; j <= n; ++j){
				sum += arr[j];
				tlcm = ((tlcm)/(__gcd(tlcm, arr[j])))*arr[j];
				//cout << i << " "<< j << " "<< tlcm << " "<< sum << "\n";
				if(!(sum%tlcm))
					++n_super;
				if(tlcm > maxi )
					break;
			}
		}
		cout << n_super << "\n";
	}
}