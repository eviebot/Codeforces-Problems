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

	int n, m, ss, ts, diff, i, j;
	string s, t;
	cin >> n >> m >> s >> t;
	ss = s.size();
	ts = t.size();
	diff = ts - ss;

	int mini = INT_MAX;
	vector <int> ans;

	for(i = 0; i <= diff; ++i)
	{
		int sum = 0;
		vector <int> temp;
		for(j = i; j < i + ss; ++j)
		{
			if( s[j-i] != t[j] )
			{
				++sum;
				temp.pb(j-i+1);
			}
		}
		if(sum < mini)
		{
			mini = sum;
			ans = temp;
		}
	}
	cout << mini << "\n";
	for(i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}