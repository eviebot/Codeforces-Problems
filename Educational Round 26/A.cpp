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

	string s, t;
	int n;
	getline(cin, s);
	int maxi = 0, i;

	getline(cin , s);
	stringstream ss(s);

	while(ss >> t)
	{
		int sum = 0;
		for(i = 0; i < t.size(); ++i)
		{
			if(t[i] <= 'Z')
				++sum;
		}
		maxi = max(maxi, sum);
	}
	cout << maxi << "\n";
}
