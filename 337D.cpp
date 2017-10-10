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

int m, n, d;
vector <vector <int>> graph;
int in[100010], out[100010];
bool ok[100010], P[100010];

void dfs1(int node, int par){
	if(P[node])
		in[node] = 0;
	int maxi = -100000000;
	for(auto it:graph[node]){
		if(it == par)
			continue;
		dfs1(it, node);
		maxi = max(maxi, in[it]);
	}
	in[node] = max(in[node], maxi+1);
}

void dfs2(int node, int par){
	if(P[node])
		out[node] = max(out[node], 0);
	int mx1 = -100000000, mx2 = -100000000;
	for(auto it:graph[node]){
		if(it == par)
			continue;
		if(in[it] >= mx1){
			mx2 = mx1;
			mx1 = in[it];
		}else if(in[it] > mx2){
			mx2 = in[it];
		}
	}
	//cout << node << " "<< mx1 << " "<< mx2 << "\n";
	for(auto it:graph[node]){
		if(it == par)
			continue;

		if(in[it] == mx1){
			out[it] = max(1+out[node], 2+mx2);
		}else{
			out[it] = max(1+out[node], 2+mx1);
		}
		dfs2(it, node);
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO
	cin >> n >> m >> d;
	memset(P, 0, sizeof(P));
	memset(ok, 0, sizeof(ok));
	graph.resize(n+1);
	int i, j, u, v;
	for(i = 1; i <= n; ++i){
		in[i] = -100000000;
		out[i] = -100000000;
	}
	for(i =1 ; i <= m; ++i){
		cin >> u;
		P[u] = 1;
	}
	for(i = 1; i <n; ++i){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs1(1, 0);
	dfs2(1, 0);
	int sum = 0;
	for(i = 1; i <= n; ++i){
		//cout << in[i] << " "<< out[i] << "\n";
		if(max(in[i], out[i]) <= d)
			++sum;
	}
	cout << sum << "\n";
}