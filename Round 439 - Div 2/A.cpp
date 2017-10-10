#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	int n, t, i, sum = 0, j;
	vector <int> arr1, arr2;
	unordered_set <int> myset;

	cin >> n;
	for(i = 0; i < n; ++i){
		cin >> t;
		arr1.pb(t);
		myset.insert(t);
	}
	for(i = 0; i < n; ++i){
		cin >> t;
		arr2.pb(t);
		myset.insert(t);
	}

	for(i = 0; i < n ;++i){
		for(j = 0; j < n; ++j){
			t = arr1[i]^arr2[j];
			if(myset.find(t) != myset.end())
				++sum;
		}
	}
	if(sum%2)
		cout << "Koyomi\n";
	else
		cout << "Karen\n";
}