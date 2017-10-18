#include <bits/stdc++.h>


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
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
	int q, n, i;
	cin >> q;
	for(i =1 ; i <= q; ++i){
		cin >> n;
		if(n < 4 || n == 5 || n == 7 || n == 11){
			cout << "-1\n";
			continue;
		}
	 	if(n%4 == 0){
	 		cout << n/4 << "\n";
	 	}else if(n%4 == 2){
	 		cout << n/4 << "\n";
	 	}else if(n%4 == 1){
	 		cout << n/4-1 << "\n";
	 	}else{
	 		cout << n/4-1 << "\n";
	 	}
	}
}