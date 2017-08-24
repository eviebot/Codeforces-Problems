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

vector <vector <int>> graph;
vector <int> temp;
vector <bool> visited;
double ans = 0;


void dfs(int root, double prob, int dist){
	visited[root] = 1;

	int j, sum = 0;
	for(j = 0; j < graph[root].size(); ++j){
		if(!visited[graph[root][j]])
			++sum;
	}

	if(!sum){
		//cout << dist << " "<< root << "\n";
		ans += prob * dist;
		return;
	}

	double p = prob / (double)(sum);

	for(j = 0; j < graph[root].size(); ++j){
		if(!visited[graph[root][j]]){
			dfs(graph[root][j], p, dist+1);
		}
	}
	return ;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, u, v;
	double prob;

	cin >> n;
	int i;

	for(i = 0; i <= n; ++i){
		graph.pb(temp);
		visited.pb(0);
	}

	for(i = 1; i < n; ++i){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1, 1.0, 0);

	cout << fixed << setprecision(15) << ans << "\n";

}