#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;
#define maxn 210000
int beauty[maxn], ans[maxn], n;
bool visited[maxn];

vector <vector <int>> graph;
vector <int> temp;

void dfstype1(int root, int gcdtot, int gcdbest){
	if(visited[root])
		return ;

	visited[root] = 1;
	int t = __gcd(gcdbest, beauty[root]), newgcdtot = __gcd(gcdtot, beauty[root]), newgcdbest;

	cout << root << " "<< gcdbest << " "<< gcdtot << "\n";
	if( gcdtot > t ){
		ans[root] = gcdtot;
		newgcdbest = gcdtot;
	}
	else{
		newgcdbest = t;
		ans[root] = t;
	}

	for(int j = 0; j < graph[root].size(); ++j){
		dfstype1(graph[root][j], newgcdtot, newgcdbest);
	}
}

void dfstype2(int root, int gcdtot){
	if(visited[root])
		return;
	visited[root] = 1;

	int t= __gcd(gcdtot, beauty[root]);
	ans[root] = max(ans[root], t);

	for(int j =0; j < graph[root].size(); ++j){
		dfstype2(graph[root][j], t);
	}
	return ;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	cin >> n;
	int i, u, v;
	for(i = 0; i <= n; ++i)
		graph.pb(temp);

	for(i= 1; i <= n; ++i){
		visited[i] = 0;
		ans[i] = 0;
		cin >> beauty[i];
	}

	for(i = 1; i < n; ++i){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	ans[1] = beauty[1];
	visited[1] = 1;
	for(i = 0; i < graph[1].size(); ++i){
		dfstype1(graph[1][i], beauty[1], beauty[graph[1][i]]);
	}
	for(i = 1; i <= n; ++i)
		visited[i] = 0;

	visited[1] = 1;

	for(i = 0; i < graph[1].size(); ++i){
		dfstype2(graph[1][i], beauty[graph[1][i]]);
	}

	for(i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}