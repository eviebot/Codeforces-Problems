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
	int test, n, i;
	string s;
	cin >> test;

	for(int z =0; z < test; ++z){
		int living = 0, kitchen = 0, bed =0 ;
		cin >> n;
		for(i = 0; i < n; ++i){
			cin >> s;
			if(s[0] == 'l' || s[0] == 'L'){
				++living;
			}
			else if(s[0] == 'b' || s[0] == 'B'){
				++bed;
			}else{
				++kitchen;
			}
		}
		cout << min( (bed/2), min(living, kitchen) ) << "\n";
	}
}