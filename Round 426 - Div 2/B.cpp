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

	int n, k, pos;
	string s;
	cin >> n >> k >> s;
	bool assigned[26];
	int i;
	bool flag[n], taken[26];

	for(i = 0; i < 26; ++i){
		taken[i] = 1;
		assigned[i] = 0;
	}

	for(i = n-1; i >= 0; --i)
	{
		pos = s[i]-'A';
		if( taken[pos])
		{
			taken[pos] = 0;
			flag[i] = 1;
		}
		else
		{
			flag[i] = 0;
		}
	}

	for(i = 0; i < s.size(); ++i)
	{
		pos = s[i]-'A';
		if( !flag[i])
		{
			if( !assigned[pos])
			{
				if( k > 0){
				//cout << pos << " "<< i << " "<< k << "\n";
				assigned[pos] = 1;
				--k;}
				else{
					cout << "YES\n";
					return 0;
				}
			}
		}
		else
		{
			if( assigned[pos])
				++k;
			else
			{
				if( k == 0)
				{
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}