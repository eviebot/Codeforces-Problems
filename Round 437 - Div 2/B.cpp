#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cerr.tie(NULL);
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

	int a, n;
	cin >> a;
	if(a == 1){
		cout << "1 1\n1\n";
		return 0;
	}
	cout << (a-1)*2 << " "<< 2 << "\n";
	cout << 1 << " "<< 2 << "\n";
}