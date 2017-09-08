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
	int test, a, b, c;
	cin >> test;
	for(int z =0; z < test; ++z){
		cin >> a >> b >> c;
		if(a <= b && a <= c){
			cout << "First\n";
		}else if(b <= a && b <= c){
			cout << "Second\n";
		}else{
			cout << "Third\n";
		}
	}
}