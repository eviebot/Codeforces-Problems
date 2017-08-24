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

lli tree[300000];

void buildTree(int node, int start, int end)
{
	if( start == end)
	{
		tree[node] = 1;
		return;
	}

	int mid = (start+end)/2;

	buildTree(node*2, start, mid);
	buildTree(node*2+1, mid+1, end);
	tree[node] = tree[node*2+1] + tree[node*2];
}

lli solve(int node, int start, int end, int l, int r)
{
	if( l > end || r < start)
		return 0;

	int mid = (start+end)/2;

	if( start >= l && end <= r)
		return tree[node];

	return solve(node*2, start, mid, l, r)+solve(node*2+1, mid+1, end, l, r);
}

void update(int node, int start, int end, int pos)
{
	if( start == end)
	{
		tree[node] = 0;
		return;
	}
	int mid = (start+end)/2;

	if( start <= pos && pos <= mid)
		update(node*2, start, mid, pos);
	else
		update(node*2+1, mid+1, end, pos);

	tree[node] = tree[node*2]+tree[node*2+1];
}
/*void checker(int node, int start, int end)
{
	cout << start << " "<< end << " "<< tree[node] << "\n";
	if( start == end)
		return;
	int mid = (start+end)/2;
	checker(node*2, start, mid);
	checker(node*2+1, mid+1, end);
}*/
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, t, i, curPos, nextpos, j, maxl;
	lli sum = 0;
	vector <vector <int>> data;
	vector <int> temp;
	cin >> n;

	for(i = 0; i <= 100000; ++i)
		data.pb(temp);

	for(i = 1; i <= n; ++i)
	{
		cin >> t;
		data[t].pb(i);
	}
	
	curPos = 0;

	buildTree(1, 1, n);

	for(i = 1; i <= 100000; ++i)
	{
		if(data[i].size())
		{
			if( data[i][0] > curPos)
				nextpos = data[i][data[i].size()-1];
			else
			{
				for(j = 1; j < data[i].size(); ++j)
				{
					if( data[i][j] > curPos)
						break;
				}
				nextpos = data[i][j-1];
			}

			if( nextpos < curPos)
			{
				if( curPos == n)
					sum += solve(1, 1, n, 1, nextpos);
				else
					sum = sum + (solve(1, 1, n, curPos+1, n) + solve(1, 1, n, 1, nextpos) );
			}
			else
			{
				sum += solve(1, 1, n, curPos+1, nextpos);
			}

			curPos = nextpos;
			
			for(j = 0; j < data[i].size(); ++j)
			{
				update(1, 1, n, data[i][j]);
			}
			
		}
	}
	cout << sum << "\n";
}
