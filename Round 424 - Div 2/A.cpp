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

	int n, t, i, prev;
	
	cin >> n ;

	int array[n+1];
	if( n == 1)
	{
		cout << "YES";
		return 0;
	}
		
	for(i = 1; i <= n; ++i)
		cin >> array[i];
	

	if( array[2] > array[1])
	{
		
		for(i = 3; i <= n; ++i)
		{
			if( !(array[i] > array[i-1] ))
				break;
		}
		for(; i <= n; ++i)
		{
			if( array[i] != array[i-1])
				break;
		}
		for(; i <= n; ++i)
		{
			if( !(array[i] < array[i-1]))
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";

	}
	else if( array[2] == array[1])
	{
		for(i = 3; i <= n; ++i)
		{
			if( array[i] != array[i-1])
			{
				break;
			}
		}
		for(; i <= n; ++i)
		{
			if( !(array[i] < array[i-1]))
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
	}
	else
	{
		for(i = 3; i <= n; ++i)
		{
			if( !(array[i] < array[i-1]))
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
	}
}