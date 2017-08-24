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

int checker(char c)
{
	if(c == 94)
		return 1;
	else if( c == 62)
		return 2;
	else if(c == 118)
		return 3;
	else
		return 0;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	char start, end;
	int n, i, pos_e, pos_s;

	cin >> start >> end >> n;

	n = n % 4;

	pos_s = checker(start);
	pos_e = checker(end);

	if( (pos_s+n)%4 == pos_e && (pos_s+4-n)%4 == pos_e )
	{
		cout << "undefined\n";
	}
	else if( (pos_s+n)%4 == pos_e)
	{
		cout << "cw\n";
	}
	else if((pos_s+4-n)%4 == pos_e)
	{
		cout << "ccw\n";
	}
	else
	{
		cout << "undefined\n";
	}
}