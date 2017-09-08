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
	
#define maxn 300000
lli arr[maxn];
lli base[maxn], n;

lli find(lli x){
	if(x == 1){
		return 0;
	}else if(x == 2){
		return 1;
	}
	if(x%2){
		return find(x/2) + 2;
	}else{
		return find(x/2) + 1;
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, i, q, l, r;
	lli val;
	cin >> test;
	for(int z = 0; z < test; ++z){
		cin >> n >> q;

		for(i = 1; i <= n; ++i){
			cin >> val;
			base[i] = find(val);
		}
		arr[0] = 0;
		for(i = 1; i <= n; ++i){
			arr[i] = arr[i-1] + base[i];
		}

		for(i = 1; i <= q; ++i){
			cin >> l >> r;
			cout << arr[r] - arr[l-1] << "\n";
		}
	}
}