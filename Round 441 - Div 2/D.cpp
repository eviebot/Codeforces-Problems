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
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;


int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, i, t, j, sum = 0;
	bool present[300010];
	memset(present, 0, sizeof(present));

	cin >> n;
	int pointer = n;
	cout << 1 << " ";
	for(i = 1; i <= n; ++i){
		cin >> t;
		present[t] = 1;
		while(present[pointer])
			pointer--;
		cout << 1+i-(n-pointer)<< " ";
	}
	cout << "\n";
}