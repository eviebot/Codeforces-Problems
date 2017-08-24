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

int tree[12][300][102];
int coords[12][102][102], x1i, x2i, y1i, y2i;
void buildTree(int node, int start, int end, int t, int y)
{
	if(start == end)
	{
		tree[t][node][y] = coords[t][start][y];
		//if(coords[t][start][y])
			//cout << "sex "<<start << " "<< y << " "<< coords[t][start][y] << "\n";
		return;
	}
	int mid = (start+end)/2, c1 = node*2, c2 = node*2+1;

	buildTree(c1, start, mid, t, y);
	buildTree(c2, mid+1, end, t, y);

	tree[t][node][y] = tree[t][c1][y]+tree[t][c2][y];
}

int query(int node, int start, int end, int t, int y)
{
	if( start > x2i || end < x1i )
		return 0;
	int mid = (start+end)/2, c1 = node*2, c2 = node*2+1;

	if( start >= x1i && end <= x2i )
		return tree[t][node][y];

	return query(c1, start, mid, t, y)+query(c2, mid+1, end, t, y);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, q, c, i, t, x, y, s, j;

	cin >> n >> q >> c;

	for(i = 1; i <= 100; ++i)
	{
		for(j = 1; j <= 100; ++j)
		{
			for(int k = 0; k <= 10; ++k)
				coords[k][i][j] = 0;
		}
	}
	for(i = 1; i <= n; ++i)
	{
		cin >> x >> y >> s;
		for(j = 0; j <= 10; ++j)
			coords[j][x][y] += (s+j)%(c+1);
		
	}
	for(i = 1 ;i <= 100; ++i)
	{
		for(t = 0; t <= 10; ++t)
		{
			//cout << i << " "<< t << "\n";
			buildTree(1, 1, 100, t, i);
		}
	}
	for(i = 1; i <= q; ++i)
	{
		cin >> t >> x1i >> y1i >> x2i >> y2i;

		t = t%(c+1);
		//sex
		int sum = 0;
		for(j = y1i; j <= y2i; ++j)
		{
			//cout << j << " "<< query(1, 1, 100, t, j)<<"\n";
			sum += query(1, 1, 100, t, j);
		}
		cout << sum << "\n";
	}
}	
