#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, i, t, sum = 0;

	unordered_set<lli> myset;
	unordered_set<lli>::iterator iter;
	cin >> n;

	for(i = 1; i <= n; ++i){
		cin >> t;
		while(t > 0){
			iter = myset.find(t);
			if(iter == myset.end()){
				myset.insert(t);
				sum += t;
				break;
			}
			--t;
		}
	}
	cout << sum << "\n";
}

	