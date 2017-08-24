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
	
vector <vector <pair <int, int>>> graph;
vector <vector <pair <int, int>>> prev_graph;
vector <int> edges;
vector <pair <int, int>> temp;
int u, v, n, m, d[310000];
bool visited[310000];


void dfs_0(int root){
	visited[root] = 1;

	for(int j= 0; j < prev_graph[root].size(); ++j){
		if(!visited[prev_graph[root][j].fi]){
			graph[root].pb(MP( prev_graph[root][j].fi, prev_graph[root][j].se ));
			graph[prev_graph[root][j].fi].pb(MP (root, prev_graph[root][j].se));
			dfs_0(prev_graph[root][j].fi);
		}
	}
}
void dfs(int root){
	visited[root] = 1;

	if(!d[root]){
		for(int j = 0; j < graph[root].size(); ++j){
			if(!visited[graph[root][j].fi])
				dfs(graph[root][j].fi);
		}
	}
	else{
		bool flag = true;
		for(int j = 0; j < graph[root].size(); ++j){
			if(!visited[graph[root][j].fi]){
				if(flag){
					d[graph[root][j].fi] = !d[graph[root][j].fi];
					flag = false;
					edges.pb(graph[root][j].se);
				}
				dfs(graph[root][j].fi);
			}
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	cin >> n >> m;
	int sum = 0, i;
	for(i = 0; i <= n; ++i){
		prev_graph.pb(temp);
		graph.pb(temp);
	}
	for(i = 1; i <= n; ++i){
		cin >> d[i];
		if(d[i] > 0)
			sum += d[i];
		visited[i] = 0;
	}

	for(i = 1; i <= m; ++i){
		cin >> u >> v;
		prev_graph[u].pb(MP(v, i));
		prev_graph[v].pb(MP(u, i));
	}

	bool flag = sum%2;
	for(i = 1; i <= n; ++i){
		if(d[i] == -1){
			if(flag){
				++sum;
				d[i] = 1;
				flag = false;
			}
			else{
				d[i] = 0;
			}
		}
	}
	
	if(flag){
		cout << "-1\n";
		return 0;
	}
	dfs_0(1);
	for(i = 1; i <= n; ++i)
		visited[i] = 0;

	for(i = 1; i <= n; ++i){
		if(graph[i].size() == 1){
			dfs(i);
			break;
		}
	}
	
	cout << edges.size() << "\n";
	for(i = 0; i < edges.size(); ++i){
		cout << edges[i] << "\n";
	}
}