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

	lli a, b;
	cin >> a >> b;
	if(a > b){
		cout << "0\n";
		return 0;
	}
	else if(b-a <= 20){
		lli digit = 1;
		for(lli i = a+1; i <= b; ++i){
			digit = (digit*i)%10;
		}
		cout << digit << "\n";
		return 0;
	}
	cout << "0\n";
}