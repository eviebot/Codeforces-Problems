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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;

	int val1 = v1*s+t1*2;
	int val2 = v2*s+t2*2;
	
	if(val1 < val2)
		cout << "First\n";
	else if(val2 < val1)
		cout << "Second\n";
	else
		cout << "Friendship\n";
}