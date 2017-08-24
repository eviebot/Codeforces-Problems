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

int data[11][11];
bool checker1(int r, int c)
{
	int i, j, sum = 0;
	i = r+1;
	while( i != 11 && data[i][c] > 0){
		++sum;++i;
	}
	i = r-1;
	while(i && data[i][c] > 0){
		++sum;--i;
	}
	if(sum >= 4)
		return 1;
	return 0;
}
bool checker2(int r, int c)
{
	int i, j, sum = 0;
	i = c+1;

	while( i != 11 && data[r][i] > 0){
		++sum;++i;
	}
	i = c-1;
	while(i && data[r][i] > 0){
		++sum;--i;
	}
	if(sum >= 4)
		return 1;
	return 0;
}
bool checker3(int r, int c)
{
	int i, j, sum = 0;
	i = r+1;
	j = c+1;

	while(i != 11 && j != 11 && data[i][j] > 0){
		++sum;
		++i;++j;
	}

	i = r-1;
	j = c-1;
	while( i && j && data[i][j] > 0){
		++sum;--i;--j;
	}
	
	if(sum >= 4)
		return 1;
	return 0;
}
bool checker4(int r, int c)
{
	int i, j, sum = 0;
	i = r-1;
	j = c+1;

	while( i && j != 11 && data[i][j] > 0 )
	{
		--i;++j;++sum;
	}

	i = r+1;
	j = c-1;
	while( j && i != 11 && data[i][j] > 0)
	{
		++i;--j;++sum;
	}
	if(sum >= 4)
		return 1;
	return 0;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	
	char c;
	int i, j;

	for(i = 1; i <= 10; ++i)
	{
		for(j = 1; j <= 10; ++j)
		{
			cin >> c;
			if( c== 'X')
				data[i][j] = 1;
			else if( c == 'O')
				data[i][j] = -1;
			else
				data[i][j] = 0;
		}
	}
	
	for( i = 1 ;i <= 10; ++i)
	{
		for(j = 1; j <= 10; ++j)
		{
			if( data[i][j] == 0)
			{
				if( checker1(i, j) || checker2(i, j) || checker3(i, j) || checker4(i, j))
				{
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}