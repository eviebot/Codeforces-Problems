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

	int n, t, arr[200], i, tester[200] = {0};
	bool extra = 0;
	cin >> n;


	for(i = 1; i <= n; ++i){
		cin >> arr[i];
		arr[i] = arr[i] %2;
	}

	if( !arr[1] || !arr[n]){
		cout << "NO\n";
		return 0;
	}
	else if(n%2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}