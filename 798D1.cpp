#include <bits/stdc++.h>
using namespace std;

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

bool comp(pair <int, int> a, pair <int, int> b){
	return a.fi > b.fi;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, t;
	vector <pair <int, int>> A, B;

	A.pb(MP(INT_MAX, 0));
	B.pb(MP(0, 0));
	cin >> n;
	int k = (n/2)+1, i;

	for(i = 1; i <= n; ++i){
		cin >> t;
		A.pb(MP(t, i));
	}
	for(i = 1; i <= n; ++i){
		cin >> t;
		B.pb(MP(t, i));
	}


	sort(A.begin(), A.end(), comp);

	cout << k << "\n";
	if(n%2){
		cout << A[1].se << " ";
		t = 2;
		for(i = 1; i < k; ++i, t+=2){
			if(B[A[t].se] > B[A[t+1].se]){
				cout << A[t].se << " ";
			}else{
				cout << A[t+1].se << " ";
			}
		}
	}
	else{
		cout << A[1].se << " "<< A[2].se << " ";
		t = 3;
		for(i = 1; i < k-1; ++i, t+=2){
			if(B[A[t].se] > B[A[t+1].se]){
				cout << A[t].se << " ";
			}else{
				cout << A[t+1].se << " ";
			}
		}
	}
	cout << "\n";
}