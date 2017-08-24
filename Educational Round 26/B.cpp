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

int n, m, arr[102][102];

bool checker(int cond)
{
	int i, j, ht = 0, h, new_arr[102][102];
	
	if(cond == 1)
	{
		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= m; ++j)
			{
				new_arr[i][j] = arr[i][j];
			}
		}
	}
	else
	{
		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= m; ++j)
			{
				new_arr[j][i] = arr[i][j];
			}
		}
		i = n;
		n = m;
		m = i;
	}
	if(n%3)
		return false;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j < m; ++j)
		{
			if(new_arr[i][j] != new_arr[i][j+1]){
				//cout << cond << " "<< i << " "<< j << "\n";
				return false;
			}
		}
	}
	h = n/3;
	if(new_arr[1][1] == new_arr[h+1][1] || new_arr[h+1][1] == new_arr[2*h+1][1] || new_arr[1][1] == new_arr[2*h+1][1]){
		//cout << h << " "<< arr[1][1] << " "<< arr[h+1][1] << " "<< arr[2*h+1][1] << "\n";
		return false;
	}
	for(i = 1; i < h; ++i)
		if(new_arr[i][1] != new_arr[i+1][1])
			return false;
	for(i = h+1; i < 2*h; ++i)
		if(new_arr[i][1] != new_arr[i+1][1])
			return false;
	for(i = 2*h+1; i < 3*h; ++i)
		if(new_arr[i][1] != new_arr[i+1][1])
			return false;
	return true;

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i, j;

	cin >> n >> m;
	string s;

	for(i = 1; i <= n; ++i)
	{
		cin >> s;
		for(j = 1; j <= m; ++j)
		{
			char c = s[j-1];
			if(c == 'R')
				arr[i][j] = 1;
			else if(c == 'G')
				arr[i][j] = 2;
			else
				arr[i][j] = 3;
		}
	}

	if(checker(1) || checker(2))
		cout << "YES\n";
	else
		cout << "NO\n";
}