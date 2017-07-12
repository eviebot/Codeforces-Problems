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

vector <int> tree;
vector <int> arr;
int p, b;

bool buildTree(int node, int start, int end)
{
	
	if( start ==end)
	{
		tree[node] = arr[start];
		return true;
	}
	int mid = (start+end)/2;

	buildTree(node*2, start, mid);
	if(buildTree(node*2+1, mid+1, end))
	{
		tree[node] = tree[node*2] | tree[node*2+1];
		return false;
	}

	else
	{
		tree[node] = tree[node*2] ^ tree[node*2+1];
		return true;
	}

}

bool update(int node, int start, int end)
{
	if( start == end)
	{
		tree[node] = b;
		return true;
	}
	int mid = (start+end)/2;

	if( start <= p && p <= mid )
	{
		if( update(node*2, start, mid) )
		{
			tree[node] = tree[node*2] | tree[node*2+1];
			return false;
		}

		else
		{
			tree[node] = tree[node*2] ^ tree[node*2+1];
			return true;
		}
	}
	else if( p > mid && p <= end)
	{
		if( update(node*2+1, mid+1, end) )
		{
			tree[node] = tree[node*2] | tree[node*2+1];
			return false;
		}	

		else
		{
			tree[node] = tree[node*2] ^ tree[node*2+1];
			return true;
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

fastIO;
	int n, m;
	cin >> n >> m;
	n = pow(2, n);
	int i, t = n*2;

	tree.pb(0);
	arr.pb(0);

	for(i = 1; i <= t; ++i)
	{
		tree.pb(0);
	}

	for(i = 0; i < n; ++i)
	{
		cin >> t;
		arr.pb(t);
	}

	buildTree(1, 1,n);
	
	
	for(i = 0; i < m; ++i)
	{
		cin >> p >> b;
		update(1, 1, n);
		cout << tree[1] << "\n";
	}
}	