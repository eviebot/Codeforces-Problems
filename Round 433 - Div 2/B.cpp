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

	
	int n, k, maxi, mini;
	cin >> n >> k;
	if(n == 1 ){
		cout << 0 << " "<< 0 << "\n";
		return 0;
	}
	if(k == n || k == 0)
		mini = 0;
	else
		mini = 1;
	
	if(k >= n/2){
		maxi = n-k;
	}
	else{
		maxi = min(n-k, 2*k);
	}
	cout << mini << " "<< maxi << "\n";
}