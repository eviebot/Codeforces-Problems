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
string s;
bool checker(int a,int b)
{
	string sa = s.substr(a, b-a+1), sb ="";
	for(int i = b; i >= a; --i)
		sb += s[i];

	if(sa == sb)
		return true;
	else
		return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	
	cin >> s;

	int n = s.size();
	int DP[15][n];


	int i, j, k;

	for(i =1; i < 15; ++i)
	{
		for(j = 0; j < n; ++j)
			DP[i][j] = 0;
	}
	for(i = 0; i < n; ++i)
	{
		for(j = i; j < n; ++j)
		{
			if(checker(i, j)) {
				++DP[1][i];
				//cout << i << " "<< j << "\n";
			}
		}
	}
	cout << DP[1][0]<<"\n";
	for(i = 2; i < 14; ++i)
	{
		//
	}
}