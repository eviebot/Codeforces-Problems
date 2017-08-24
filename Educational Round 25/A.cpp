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

	int n, num = 0, temp;
	string s;

	cin >> n >> s;

	for(int i =0 ; i < n; )
	{
		if( s[i] == '1')
		{
			temp = 0;
			while(s[i] == '1')
			{
				++temp;++i;
			}
			num *= 10;
			num += temp;
		}
		else
		{
			++i;
			while(s[i] == '0')
			{
				++i;
				num *= 10;
			}
		}
	}
	if( s[n-1] == '0')
		num *= 10;
	cout << num << "\n";
}