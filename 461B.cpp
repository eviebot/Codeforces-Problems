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

#define MOD 1000000007
int n;
lli B[110000], W[110000];
vector <vector <int>> graph;
vector <int> temp;
bool colors[110000], visited[110000];

void dfs(int root){
	lli Wt, Bt;
	int t;
	visited[root] = 1;
	if(colors[root] == 1){
		W[root] = 0;
		B[root] = 1;
	}else{
		W[root] = 1;
		B[root] = 0;
	}
	for(int j = 0; j < graph[root].size(); ++j){
		t = graph[root][j];
		if(visited[t]){
			continue;
		}
		dfs(t);
		//cout << W[t] << " "<< B[t] << "\n";
		Wt = W[root];
		Bt = B[root];

		Wt = (W[t]*W[root])%MOD;
		Bt = ((B[t]*W[root])%MOD+(B[root]*W[t])%MOD)%MOD;
		Wt = (Wt + W[root]*B[t]%MOD)%MOD;
		Bt = (Bt + (B[root]*B[t])%MOD)%MOD;

		W[root] = Wt;
		B[root] = Bt;
		//cout << W[root] << " "<< B[root] << "\n";
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");	

	fastIO;
	int t, i;
	cin >> n;
	for(i = 0; i < n; ++i)
		graph.pb(temp);
	for(i = 1; i < n; ++i){
		cin >> t;
		graph[i].pb(t);
		graph[t].pb(i);
	}
	for(i = 0; i < n; ++i){
		cin >> colors[i];
		visited[i] = 0;
	}


	dfs(0);
	cout << B[0] << "\n";
}