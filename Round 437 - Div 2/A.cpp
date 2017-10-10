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

	int seat = 0, sanfran = 0, i, n;
	string s;
	bool flag;
	cin >>n >>  s;
	if(s[0] == 'F')
		flag = true;
	else
		flag = false;
	for(i = 0; i < n; ++i){
		if(s[i] == 'F' && !flag){
			flag = true;
			++seat;
		}
		if(s[i] == 'S' && flag){
			flag = false;
			++sanfran;
		}
	}
	if(seat > sanfran)
		cout << "YES\n";
	else
		cout << "NO\n";
}