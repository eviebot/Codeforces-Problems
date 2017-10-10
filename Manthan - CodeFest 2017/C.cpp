#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cerr.tie(NULL);
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
#define mod 1000000007
int n, m, kkk, x;
vector <vector <int>> graph;
vector <int> temp;
lli DP[100010][3][11];

bool visited[100010];
void dfs(int root, int par){
	visited[root] = 1;
	lli temp[3][12];
	memset(temp, 0, sizeof(temp));
	bool flag = true;
	for(int j = 0; j < graph[root].size(); ++j){
		if(!visited[graph[root][j]])
			flag = false;
	}
	if(flag){
		DP[root][0][0] = kkk-1;
		DP[root][1][1] = 1;
		DP[root][2][0] = m-kkk;
		return ;
	}
	for(int j =0; j < graph[root].size(); ++j){
		int t = graph[root][j];
		if(visited[t])
			continue;
		dfs(t, root);
	}
	for(auto it:graph[root]){
		if(it == par)
			continue;
		for(int a = 0; a <= 10; ++a){
			for(int b = 0; b <= 10; ++b){
				if(a+b > x)
					break;
				temp[0][a+b] = temp[0][a+b] + (DP[it][])
			}
		}
	}
	for(int j = 0; j <= x; ++j){
		DP[root][0][j] = (DP[root][0][j]*(kkk-1))%mod;
		DP[root][2][j] = (DP[root][2][j]*(m-kkk))%mod;
	}

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int u, v, i, j, k;
	cin >> n >> m;
	for(i = 0; i <= n; ++i)
		graph.pb(temp);
	memset(visited, 0, sizeof(visited));
	for(i = 1; i <= n; ++i){
		for(j = 0; j < 3; ++j){
			for(k = 0; k < 11; ++k)
				DP[i][j][k] = 0;
		}
	}
	for(i = 1; i < n; ++i){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	cin >> kkk >> x;

	dfs(1, -1);
	lli sum = 0;	
	for(i = 0; i < 3; ++i){
		for(j = 0; j <= x; ++j){
			sum = (sum + DP[1][i][j])%mod;
		}
	}
	cout << sum << "\n";
}