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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, i;
	string s;
	set <string> myset;
	set <string>::iterator iter;
	cin >> n;
	for(i = 1; i <= n;++i){
		cin >> s;
		iter = myset.find(s);
		if(iter == myset.end()){
			myset.insert(s);
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}