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

	int a, b, c, n;
	cin >> n >> a >> b >> c;
	int t = min(a, min(b, c));
	if(t == a || t == b){
		cout << (n-1)*t << "\n";
		return 0;
	}
	cout << min(min(a, b)*(n-1), min(a, b)+(n-2)*t) << "\n";
}	